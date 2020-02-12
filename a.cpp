#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nvertices;
    cout<<"Please enter the number of vertices :\n";
    cin>>nvertices;

    int d[nvertices];
    for(int i=0;i<nvertices;i++)
    {
        d[i] = INT_MAX;
    }
    int a[nvertices][nvertices];

    cout<<"Please enter the adjacency matrix:\n";
    for(int i=0;i<nvertices;i++)
    {
        for(int j=0;j<nvertices;j++)
            cin>>a[i][j];
    }

    int source;
    cout<<"Please enter the source :";
    cin>>source;

    queue<int> q;
    q.push(source);
    d[source] = 0;

    int u = source;

    while(!q.empty())
    {
        for(int i = 0;i<nvertices;i++)
        {
            if(a[u][i] != 999)
            {
                int v = i;
                if( d[v] > d[u]+ a[u][v] )
                {
                    d[v] = d[u] + a[u][v];
                    q.push(v);
                }
            }
        }

        q.pop();
        u = q.front();
    }

    printf("\n The shortest routes for all the nodes from the source is given below \n");
    for(int i=0;i<nvertices;i++)
    {
        printf("\n %d -- > %d = %d ",source,i,d[i]);
    }
}

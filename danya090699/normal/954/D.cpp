#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    s--, t--;
    bool sm[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) sm[a][b]=0;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sm[u][v]=1, sm[v][u]=1;
    }
    int d[n], d2[n];
    queue <int> qu;
    for(int a=0; a<n; a++)
    {
        d[a]=inf, d2[a]=inf;
    }
    d[s]=0, qu.push(s);
    while(qu.size())
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int v=qu.front();
            for(int a=0; a<n; a++)
            {
                if(sm[v][a] and d[a]==inf)
                {
                    d[a]=d[v]+1, qu.push(a);
                }
            }
            qu.pop();
        }
    }
    d2[t]=0, qu.push(t);
    while(qu.size())
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int v=qu.front();
            for(int a=0; a<n; a++)
            {
                if(sm[v][a] and d2[a]==inf)
                {
                    d2[a]=d2[v]+1, qu.push(a);
                }
            }
            qu.pop();
        }
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            if(sm[a][b]==0)
            {
                int x=min(d[a]+1+d2[b], d[b]+1+d2[a]);
                if(x>=d[t]) an++;
            }
        }
    }
    cout<<an;
}
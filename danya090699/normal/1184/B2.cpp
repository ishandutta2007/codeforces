#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10, sz=1e3+10;
vector <int> sv[sz];
int to[sz];
bool us[sz];
bool kuhn(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(to[ne]==-1)
        {
            to[ne]=v;
            return true;
        }
        else
        {
            if(us[to[ne]]==0)
            {
                if(kuhn(to[ne]))
                {
                    to[ne]=v;
                    return true;
                }
            }
        }
    }
    return false;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int sm[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) sm[a][b]=(a==b) ? 0 : inf;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sm[u][v]=1, sm[v][u]=1;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<n; c++) sm[b][c]=min(sm[b][c], min(sm[b][a]+sm[a][c], inf));
        }
    }
    int shq, baq, k, h;
    cin>>shq>>baq>>k>>h;
    int sh[shq][3];
    for(int a=0; a<shq; a++)
    {
        for(int b=0; b<3; b++) cin>>sh[a][b];
        sh[a][0]--;
    }
    for(int a=0; a<baq; a++)
    {
        int v, d;
        cin>>v>>d;
        v--;
        for(int b=0; b<shq; b++)
        {
            int v2=sh[b][0], d2=sh[b][1], di=sh[b][2];
            if(d2>=d and di>=sm[v][v2]) sv[b].push_back(a);
        }
    }
    for(int a=0; a<baq; a++) to[a]=-1;
    int pq=0;
    for(int a=0; a<shq; a++)
    {
        for(int b=0; b<shq; b++) us[b]=0;
        if(kuhn(a)) pq++;
    }
    long long an=1e18;
    for(int a=0; a<=shq; a++)
    {
        an=min(an, 1ll*h*a+1ll*k*min(shq-a, pq));
    }
    cout<<an;
}
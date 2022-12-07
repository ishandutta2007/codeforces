#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10, mod=1e9+7;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int sum(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
int dif(int a, int b)
{
    return (a-b>=0) ? a-b : a-b+mod;
}
int mul(int a, int b)
{
    return (1ll*a*b)%mod;
}
int us[sz], h[sz], pr[sz], cynu[sz], near[sz], cq=0;
vector <int> sv[sz], cy[sz];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) pr[ne]=v, h[ne]=h[v]+1, dfs(ne);
    }
}
int del(int x, int y)
{
    return (1ll*x*po(y, mod-2))%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int st[n+1];
    st[0]=1, st[1]=po(2, mod-2);
    for(int a=2; a<=n; a++) st[a]=mul(st[a-1], st[1]);
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0);
    int cysum=0;
    for(int a=0; a<n; a++) cynu[a]=-1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int v=sv[a][b];
            if(h[a]+1<h[v])
            {
                while(v!=a)
                {
                    cy[cq].push_back(v), cynu[v]=cq, v=pr[v];
                }
                cy[cq].push_back(a);
                for(int c=0; c<cy[cq].size(); c++)
                {
                    int u=cy[cq][c];
                    near[u]=sum(near[u], st[cy[cq].size()]);
                }
                cysum=sum(cysum, st[cy[cq].size()]);
                cq++;
            }
        }
    }
    int an=0, an2=0;
    for(int a=0; a<n; a++)
    {
        an=sum(an, st[1]);
        an2=sum(an2, mul(st[2], n-1));
        an2=sum(an2, st[1]);

        int add=sum(mul(sv[a].size(), st[2]), mul(m-sv[a].size(), st[3]));
        an2=dif(an2, mul(add, 2));

        an2=sum(an2, sum(cysum, near[a]));
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int v=sv[a][b];
            if(h[a]<h[v])
            {
                an=dif(an, st[2]);

                an2=sum(an2, st[2]);
                an2=sum(an2, mul(st[3], sv[a].size()+sv[v].size()-2));
                an2=sum(an2, mul(st[4], m-sv[a].size()-sv[v].size()+1));

                int add=sum(cysum, sum(near[a], near[v]));
                if(cynu[v]!=-1) add=sum(add, st[cy[cynu[v]].size()]);
                an2=dif(an2, mul(st[1], add));
            }
        }
    }
    for(int a=0; a<cq; a++)
    {
        an=sum(an, st[cy[a].size()]);

        an2=sum(an2, st[cy[a].size()]);
        int add=dif(cysum, st[cy[a].size()]);
        for(int b=0; b<cy[a].size(); b++)
        {
            int v=cy[a][b];
            add=sum(add, dif(near[v], st[cy[a].size()]));
        }
        an2=sum(an2, mul(add, st[cy[a].size()]));
    }
    cout<<dif(an2, mul(an, an));
}
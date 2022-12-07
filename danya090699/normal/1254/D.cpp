#include <bits/stdc++.h>
using namespace std;
const int sz=2e5, mod=998244353;
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
vector <int> sv[sz];
int pr[sz], si[sz], tin[sz], timer=0, hld[sz], su[sz];
bool comp(int a, int b)
{
    return si[a]<si[b];
}
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        if(sv[v][a]==pr[v]) sv[v].erase(sv[v].begin()+a);
    }
    tin[v]=timer++;
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        pr[ne]=v, dfs(ne), si[v]+=si[ne];
    }
    sort(sv[v].begin(), sv[v].end(), comp);
}
void dfs2(int v)
{
    for(int a=0; a+1<sv[v].size(); a++) hld[sv[v][a]]=sv[v][a];
    if(sv[v].size()) hld[sv[v].back()]=hld[v];
    for(int a=0; a<sv[v].size(); a++) dfs2(sv[v][a]);
}

int dot[sz*4], add[sz*4];
void push(int nu)
{
    add[nu*2]=(add[nu*2]+add[nu])%mod;
    add[nu*2+1]=(add[nu*2+1]+add[nu])%mod;
    add[nu]=0;
}
void recalc(int nu, int q)
{
    dot[nu]=(dot[nu*2]+1ll*(q-q/2)*add[nu*2]+dot[nu*2+1]+1ll*(q/2)*add[nu*2+1])%mod;
}
int lg, rg, val;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]=(add[nu]+val)%mod;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu, r-l+1);
    }
}
int p;
int que(int nu, int l, int r)
{
    if(l==r) return (dot[nu]+add[nu])%mod;
    else
    {
        int mid=(l+r)>>1, re;
        push(nu);
        if(p<=mid) re=que(nu*2, l, mid);
        else re=que(nu*2+1, mid+1, r);
        recalc(nu, r-l+1);
        return re;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0), dfs2(0);
    int rev=po(n, mod-2);
    for(int a=0; a<q; a++)
    {
        int ty, v;
        scanf("%d%d", &ty, &v);
        v--;
        if(ty==1)
        {
            int d;
            scanf("%d", &d);
            lg=0, rg=n-1, val=(1ll*d*((1ll*rev*si[v])%mod))%mod;
            cha(1, 0, n-1);
            lg=tin[v], rg=tin[v]+si[v]-1, val=(mod-val)%mod;
            cha(1, 0, n-1);

            if(sv[v].size())
            {
                int u=sv[v].back();
                lg=tin[u], rg=tin[u]+si[u]-1, val=(1ll*d*((1ll*rev*(n-si[u]))%mod))%mod;
                cha(1, 0, n-1);
            }
            su[v]=(su[v]+d)%mod;
        }
        else
        {
            p=tin[v];
            int an=(que(1, 0, n-1)+su[v])%mod;
            while(v)
            {
                v=hld[v];
                an=(an+1ll*su[pr[v]]*((1ll*rev*(n-si[v]))%mod))%mod;
                v=pr[v];
            }
            printf("%d\n", an);
        }
    }
}
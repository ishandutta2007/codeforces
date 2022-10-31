#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int maxn=2e5+7;
vector<int> G[maxn];
int n,q;
int far[maxn][19],dep[maxn];
int sz[maxn];
int st[maxn],ed[maxn];
int ti=0;
void db()
{
    for(int j=1;j<19;j++)
        for(int i=1;i<=n;i++)
            far[i][j]=far[far[i][j-1]][j-1];
}
void dfs(int u,int fa=0)
{
    st[u]=++ti;
    sz[u]=1;
    far[u][0]=fa;
    for(auto& v:G[u])if(v!=fa)
    {
        dep[v]=dep[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    ed[u]=ti;
}
int sum[maxn];
void add(int x,int val)
{
    if(!x) return;
    while(x<=n)
    {
        sum[x]=(sum[x]+val)%mod;
        x+=x&-x;
    }
}
int query(int x)
{
    int ret=0;
    while(x)
    {
        ret=(ret+sum[x])%mod;
        x-=x&-x;
    }
    return ret;
}
inline void add(int l,int r,int val)
{
    add(l,val);
    add(r+1,mod-val);
}
vector<int> sp;
int d[maxn];
int var;
int cont(int u,int v)
{
    if(v==u) return 1LL*n*d[u]%mod;
    int jj=18;
    while(jj>=0&&dep[v]>dep[u])
    {
        if(dep[far[v][jj]]>dep[u]) v=far[v][jj];
        jj--;
    }
    if(far[v][0]!=u||dep[v]<dep[u]) return 1LL*sz[u]*d[u]%mod;
    return 1LL*(n-sz[v])*d[u]%mod;
}
inline int getans(int v)
{
    int ret=query(st[v]);
    //dbg(ret);
    for(auto& u:sp)
        ret=(ret+cont(u,v))%mod;
    return ret;
}
inline ll inv(ll a)
{
    int b=mod-2;
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&q);
    var=sqrt(n);
    for(int i=1,u,v;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(G[i].size()>=var) sp.push_back(i);
    dep[1]=1;
    dfs(1);
    db();
    int invn=inv(n);
    while(q--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int v,dd;
            scanf("%d%d",&v,&dd);
            if(G[v].size()<var)
            {
                for(auto u:G[v])
                {
                    if(u!=far[v][0])
                        add(st[u],ed[u],1LL*(n-sz[u])*dd%mod);
                    else{
                        add(1,n,1LL*sz[v]*dd%mod);
                        add(st[v],ed[v],(mod-1LL*sz[v]*dd%mod));
                    }
                }
                add(st[v],st[v],1LL*dd*n%mod);
            }
            else d[v]=(d[v]+dd)%mod;
        }
        else{
            int v;
            scanf("%d",&v);
            printf("%lld\n",1LL*getans(v)*invn%mod);
        }
    }
}
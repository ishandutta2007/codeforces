#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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
const int maxn=1e6+7;
bool vis[maxn];
vi prime;
void db()
{
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
            for(int j=i+i;j<maxn;j+=i) vis[j]=1;
        }
    }
}
vi G[maxn];
int id[maxn];
vi all;
int dis[maxn];
int fa[maxn];
inline int getid(int x)
{
    if(id[x]!=-1) return id[x];
    return id[x]=lower_bound(all.begin(),all.end(),x)-all.begin();
}
inline void addedge(int u,int v)
{
    //dbg(u,v);
    all.push_back(u);
    all.push_back(v);
    G[u].push_back(v);
    G[v].push_back(u);
}
int solve(int x)
{
    int mi=0x3f3f3f3f;
    for(int i=0;i<all.size();i++) dis[i]=-1;
    dis[x]=0;
    fa[x]=-1;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        if(dis[u]>mi) break;
        bool fi=1;
        for(auto v:G[all[u]])
        {
            int vv=getid(v);
            //dbg(u,vv);
            if(dis[vv]==-1)
            {
                dis[vv]=dis[u]+1;
                q.push(vv);
                fa[vv]=u;
            }
            else{
                if(vv==fa[u]&&fi) fi^=1;
                else{
                    //dbg(u,vv,1);
                    mi=min(mi,dis[u]+dis[vv]+1);
                }
            }
        }
    }
    //dbg(x,mi);
    return mi;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    db();
    memset(id,-1,sizeof(id));
    int n;
    cin>>n;
    vi a(n);
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int x=a[i];
        static vi fac;
        fac.clear();
        for(auto p:prime)
        {
            if(p*p>x) break;
            if(x%p==0)
            {
                int cc=0;
                while(x%p==0)
                {
                    cc++;
                    x/=p;
                }
                if(cc&1)
                    fac.push_back(p);
            }
        }
        if(x>1) fac.push_back(x);
        if(fac.size()==0) ans=1;
        else if(fac.size()==1) addedge(1,fac[0]);
        else if(fac.size()==2) addedge(fac[0],fac[1]);
        else assert(false);
    }
    if(ans!=-1) print(ans);
    else{
        int ans=0x3f3f3f3f;
        mkuni(all);
        for(int i=0;i<all.size();i++)
        {
            if(all[i]>1050) break;
            ans=min(ans,solve(i));
        }
        if(ans==0x3f3f3f3f) print(-1);
        else print(ans);
    }
}
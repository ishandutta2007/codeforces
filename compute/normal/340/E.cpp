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
const int maxn=2e3+7;
const int mod=1e9+7;
ll C[maxn][maxn],fac[maxn];
void db()
{
    fac[0]=1;
    for(int i=0;i<maxn;i++)
    {
        if(i) fac[i]=fac[i-1]*i%mod;
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}
int main()
{
    db();
    int n;
    cin>>n;
    ll ans=0;
    vi a(n);
    vi vis(n+1);
    int tot=0,canuse=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>0) vis[a[i]]=1;
        else canuse++;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]&&a[i-1]==-1) tot++;
    for(int k=0;k<=tot;k++)
    {
        ll cur=C[tot][k]*fac[canuse-k]%mod;
        if(k&1) ans=(ans-cur+mod)%mod;
        else ans=(ans+cur)%mod;
    }
    print(ans);
}
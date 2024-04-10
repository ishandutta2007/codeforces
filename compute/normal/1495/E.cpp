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
const int mod=1e9+7;
int seed=0,base=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vc<ll> a(n);
    vi t(n);
    auto rnd=[&](){
        int ret = seed;
        seed = (1LL*seed*base+233)%mod;
        return ret;
    };
    int pre=0;
    for(int i=0;i<m;i++)
    {
        int p,k,b,w;
        cin>>p>>k>>b>>w;
        seed=b,base=w;
        for(int j=pre;j<p;j++)
        {
            t[j]=(rnd()%2);
            a[j]=(rnd()%k)+1;
        }
        pre=p;
    }
    dbg(t);
    dbg(a);
    vc<ll> ans(n);
    vc<ll> cnt(2);
    for(int i=0;i<n;i++) cnt[t[i]]+=a[i];
    int lose=-1;
    if(cnt[t[0]]>cnt[t[0]^1])
    {
        lose=t[0]^1;
        ans[0]++;
        a[0]--;
    }
    else lose=t[0];
    ll sum=0;
    for(int i=0;i<2*n;i++)
    {
        int cur=i%n;
        if(t[cur]==lose)
        {
            sum+=a[cur];
            ans[cur]+=a[cur];
            a[cur]=0;
        }
        else{
            ll cc=min(a[cur],sum);
            ans[cur]+=cc;
            sum-=cc;
            a[cur]-=cc;
        }
    }
    ll op=1;
    dbg(ans);
    for(int i=0;i<n;i++)
    {
        op=(((1LL*(i+1)*(i+1))^ans[i])+1)%mod*op%mod;
    }
    print(op);

}
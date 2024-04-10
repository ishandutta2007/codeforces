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
const int maxn=4e5+7;
ll inv[maxn],finv[maxn],f[maxn];
void init() //inv,f,finv ll
{
    inv[1] = 1;
    for (int i = 2; i < maxn; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod; //inv: 
    f[0] = finv[0] = 1;                                //f:     finv:(1/f)
    for (int i = 1; i < maxn; i++)
    {
        f[i] = f[i - 1] * i % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
ll C(int n, int m) //C(n,m)
{
    if (m < 0 || m > n)
        return 0;
    return f[n] * finv[n - m] % mod * finv[m] % mod;
}
int a[maxn],b[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        ans=(ans+C(i+a[i],i+1))%mod;
        dbg(i,ans);
    }
    print(ans);
}
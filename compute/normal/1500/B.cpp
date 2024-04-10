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
ll exgcd(ll a, ll b, ll &x, ll &y) //gcd(a,b)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
}
ll CRT(ll *m, ll *r, ll n)
{
    if (!n)
        return 0;
    ll M = m[0], R = r[0], x, y, d;
    for (int i = 1; i < n; i++)
    {
        d = exgcd(M, m[i], x, y);
        if ((r[i] - R) % d)
            return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
    return R >= 0 ? R : R + M;
}
ll md[2],r[2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vi a(n);
    vi b(m);
    vi pos(2*max(n,m)+1,-1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++)
    {
        cin>>b[j];
        pos[b[j]]=j;
    }
    vc<ll> tr(n,-1);
    md[0]=n,md[1]=m;
    ll M=1LL*n/__gcd(n,m)*m;
    for(int i=0;i<n;i++)
    {
        if(pos[a[i]]!=-1)
        {
            r[0]=i;
            r[1]=pos[a[i]];
            tr[i]=CRT(md,r,2);
            dbg(i,a[i],tr[i]);
        }
    }
    ll L=0,R=1e18,ans=-1;
    while(L<=R)
    {
        ll mid=L+R>>1;
        ll cnt=0;
        ll tt=mid/M;
        for(int i=0;i<n;i++)
        {
            if(tr[i]!=-1)
                cnt+=tt+((tt*M+tr[i])<=mid);
        }
        if(mid+1-cnt>=k)
        {
            R=mid-1;
            ans=mid;
        }
        else L=mid+1;
    }
    print(ans+1);
}
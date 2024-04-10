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
const int maxn=2e5+7;
const int mod=1e9+7;
ll fac[maxn],invfac[maxn];
int mu[maxn];
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
void db()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    invfac[maxn-1]=quick(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
    mu[1]=1;
    for(int i=2;i<maxn;i++)
    {
        int tmp=i;
        int cc=0;
        for(int j=2;j*j<=tmp;j++)
        {
            if(tmp%j==0)
            {
                int cnt=0;
                cc++;
                while(tmp%j==0)
                {
                    tmp/=j;
                    cnt++;
                }
                if(cnt>1)
                {
                    cc=-2;
                    break;
                }
            }
        }
        if(tmp>1) cc++;
        if(cc>=0)
        {
            if(cc&1) mu[i]=-1;
            else mu[i]=1;
        }
    }
}
inline ll C(int n,int m)
{
    if(m>n) return 0;
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int n,f;
ll solve(int x)
{
    int cc=n/x;
    //dbg(x,mu[x]*C(cc-1,f-1));
    return (mu[x]*C(cc-1,f-1)+mod)%mod;
}
int main()
{
    db();
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n>>f;
        ll ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ans=(ans+solve(i))%mod;
                if(i*i!=n) ans=(ans+solve(n/i))%mod;
            }
        }
        print(ans);
    }
}
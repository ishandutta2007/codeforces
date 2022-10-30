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
int vis[maxn*20];
vi fac[maxn];
int cc[maxn];
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=2;i<maxn;i++)
    {
        bool isp=(fac[i].size()==0);
        for(int j=i;j<maxn;j+=i)
        {
            if(isp) fac[j].push_back(i);
        }
    }
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i*j])
            {
                cc[i]++;
                vis[i*j]=1;
            }
        }
    }
    ll ans=1;
    for(int i=2;i<=n;i++)
    {
        // vc<pi> cc;
        int x=i;
        int g=0;
        for(auto v:fac[i])
        {
            int cnt=0;
            while(x%v==0)
            {
                x/=v;
                cnt++;
            }
            g=__gcd(g,cnt);
            // cc.push_back({v,cnt});
        }
        dbg(i,g);
        ans+=cc[g];
    }
    print(ans);
}
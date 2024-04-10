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
typedef vector<ll> vi;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        vc<vi> c(n,vi(m));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            cin>>c[i][j];
        int cnt=0,ans=1;
        ll tans=0;
        for(int i=1;i<n;i++)
        {
            ll d=0,L=0,R=0;
            for(int j=0;j<m;j++)
            {
                d+=c[i][j]-c[0][j];
                if(d>0) L+=d;
                else R-=d;
            }
            dbg(i,L,R);
            if(L!=R)
            {
                cnt++;
                ans=i+1;
                tans=abs(R-L);
            }
        }
        if(cnt==n-1) ans=1;
        dbg(cnt);
        cout<<ans<<" "<<tans<<'\n';
    }
}
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
vc<ll> res(ll v)
{
    vc<ll> fac;
    for(int i=2;1LL*i*i<=v;i++)
    {
        if(v%i==0)
        {
            while(v%i==0) v/=i;
            fac.push_back(i);
        }
    }
    if(v>1) fac.push_back(v);
    return fac;
}
int main()
{
    int n;
    cin>>n;
    vc<ll> a(n);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=(a[i]&1);
    }
    auto test=[&](ll x)
    {
        ll sum=0;
        for(auto u:a)
        {
            if(u<x) sum+=x-u;
            else sum+=min(u%x,x-u%x);
        }
        ans=min(ans,sum);
    };
    for(int i=0;i<30;i++)
    {
        int cur=rand_int(0,n-1);
        for(int d=-1;d<=1;d++)
        {
            ll v=a[cur]+d;
            if(v<2) continue;
            vc<ll> fac=res(v);
            for(auto u:fac) test(u);
        }
    }
    print(ans);
}
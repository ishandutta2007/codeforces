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

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        vi a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n==1)
        {
            print(d-1);
            continue;
        }
        vi cf(n);
        for(int i=1;i<=n;i++)
            cf[i-1]=a[i]-a[i-1]-1;
        int ans=*min_element(cf.begin(),cf.end());
        multiset<int> all;
        for(int i=0;i<n;i++) all.insert(cf[i]);
        for(int i=1;i<n;i++)
        {
            // dbg(i);
            all.erase(all.find(cf[i-1]));
            int ns=cf[i-1];
            all.erase(all.find(cf[i]));
            ns+=1+cf[i];
            all.insert(ns);
            int mx=*all.rbegin();
            int cans=min(*all.begin(),max((mx-1)/2, d-a.back()-1));
            // dbg(i,cans);
            ans=max(ans,cans);
            all.erase(all.find(ns));
            all.insert(cf[i]);
            all.insert(cf[i-1]);
        }
        int len=d-a[n-1];
        all.erase(all.find(cf[n-1]));
        int mx=*all.rbegin();
        ans=max(ans,min(max(len-1,(mx-1)/2),*all.begin()));
        print(ans);
    }
}
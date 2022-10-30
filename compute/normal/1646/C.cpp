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
    int T;
    cin>>T;
    ll mx=1e12;
    vc<ll> all;
    ll c=1;
    while(c<=mx)
    {
        all.push_back(c);
        c*=2;
    }
    c=2;
    vc<ll> fac;
    for(int i=3;c<=mx;i++)
    {
        fac.push_back(c);
        c*=i;
    }
    dbg(all.size(), fac.size());
    while(T--)
    {
        ll n;
        cin>>n;
        int ans=100;
        for(int S=0;S<(1<<fac.size());S++)
        {
            int cur=0;
            ll cnum=n;
            for(int i=0;i<fac.size();i++)
            {
                if(S>>i&1)
                {
                    cur++;
                    cnum-=fac[i];
                }
            }
            if(cnum>=0)
            {
                for(int j=all.size()-1;j>=0;j--)
                {
                    if(cnum>=all[j])
                    {
                        cnum-=all[j];
                        cur++;
                    }
                }
                assert(cnum==0);
                ans=min(ans,cur);
            }
        }
        print(ans);
    }
}
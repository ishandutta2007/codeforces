#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
const int INF=0x3f3f3f3f;

int main()
{
    ll n;
    cin>>n;
    vector<ll> fac;
    ll sv=n;
    for(ll i=2;i*i<=sv;i++)
    {
        if(sv%i==0)
        {
            fac.push_back(i);
            while(sv%i==0)
                sv/=i;
        }
    }
    if(sv!=1) fac.push_back(sv);
    if(fac.size()==1)
        cout<<fac[0]<<endl;
    else{
        cout<<1<<endl;
    }
}
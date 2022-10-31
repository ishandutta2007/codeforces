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
ll a,m;
vc<ll> fac;
ll getans(ll x)
{
    ll ret=0;
    int sz=fac.size();
    for(int i=0;i<(1<<sz);i++)
    {
        int cc=0;
        ll tmp=1;
        for(int j=0;j<sz;j++)
            if(i>>j&1) tmp=tmp*fac[j],cc++;
        if(cc&1) ret=ret-x/tmp;
        else ret=ret+x/tmp;
    }
    //dbg(x,ret);
    return ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>m;
        fac.clear();
        ll g=__gcd(a,m);
        m/=g;
        a/=g;
        ll mm=m;
        for(int i=2;1LL*i*i<=mm;i++)
        {
            if(mm%i==0)
            {
                fac.push_back(i);
                while(mm%i==0) mm/=i;
            }
        }
        if(mm>1) fac.push_back(mm);
        //dbg(fac);
        cout<<getans(m+a-1)-getans(a-1)<<'\n';
    }
}
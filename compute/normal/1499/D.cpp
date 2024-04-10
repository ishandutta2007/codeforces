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
const int maxn = 2e7 + 10;
int prime[maxn] = {0}, phi[maxn] = {0}, tot;ll op[maxn];

void euler()
{
    phi[1] = 1;
    op[1]=1;
    for (int i = 2; i < maxn; i++)
    {
        if (!phi[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
            op[i]=2;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++)
        {
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                op[i*prime[j]]=op[i];
                break;
            }
            op[i*prime[j]]=op[i]*2;
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}
void solve()
{
    int c,d,x;
    cin>>c>>d>>x;
    ll ans=0;
    auto go=[&](int t){
        int xx=x/t;
        int tar=xx+d;
        if(tar%c!=0) return;
        ans+=op[tar/c];
    };
    for(int t=1;t*t<=x;t++)
    {
        if(x%t==0)
        {
            go(t);
            if(x/t!=t) go(x/t);
        }
    }
    print(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    euler();
    int T;
    cin>>T;
    while(T--) solve();
}
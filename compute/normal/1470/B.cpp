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
const int maxn = 1e6 + 10;
int prime[maxn], tot = 0, mu[maxn],tar[maxn];
bool check[maxn];

void mobius()
{
    mu[1] = 1;
    tar[1]=1;
    for (int i = 2; i < maxn; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++)
        {
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
        tar[i]=i;
        if(!mu[i]){
            for (int j = 0; j < tot && prime[j] <= tar[i]; j++)
            {
                int cc=0;
                while(tar[i]%prime[j]==0)
                {
                    tar[i]/=prime[j];
                    cc++;
                }
                if(cc&1) tar[i]*=prime[j];
                if(tar[i]<i)
                {
                    tar[i]=tar[tar[i]];
                    break;
                }
            }
            //dbg(i,tar[i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mobius();
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vi a(n);
        map<int,int> cnt;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            dbg(tar[a[i]]);
            cnt[tar[a[i]]]++;
        }
        int ans0=0;
        for(auto &u:cnt) ans0=max(ans0,u.second);
        int c1=0,ct=0;
        for(auto &u:cnt)
        {
            if(u.second%2==0||u.first==1) c1+=u.second;
            else ct=max(ct,u.second);
        }
        int q;
        cin>>q;
        while(q--)
        {
            ll w;
            cin>>w;
            if(w==0) print(ans0);
            else{
                print(max(c1,ct));
            }
        }
    }
}
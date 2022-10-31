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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vvc<int> a(n,vi(m));
    auto b=a;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>b[i][j];
    }
    vi cnt(m);
    vi cut(n);
    vi ans;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i][j]>b[i+1][j]) cnt[j]++;
        }
    }
    while(true)
    {
        int tar=-1;
        for(int i=0;i<m;i++)
        {
            if(!cnt[i])
            {
                tar=i;
                cnt[tar]=-1;
                break;
            }
        }
        if(tar==-1) break;
        ans.push_back(tar);
        for(int i=0;i<n-1;i++)
        {
            if(!cut[i]&&b[i][tar]<b[i+1][tar])
            {
                cut[i]=1;
                for(int j=0;j<m;j++)
                {
                    if(b[i][j]>b[i+1][j]) cnt[j]--;
                }
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto u:ans)
    {
        stable_sort(a.begin(),a.end(),[&](const vi &x,const vi &y){
            return x[u]<y[u];
        });
    }
    if(a==b)
    {
        print(ans.size());
        for(auto &u:ans) u++;
        print(ans);
    }
    else print(-1);
}
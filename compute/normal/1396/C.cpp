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
    int n,r1,r2,r3,d;
    cin>>n>>r1>>r2>>r3>>d;
    vc<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vvc<ll> dp(n+1,vc<ll>(2,1e18));
    dp[0][0]=0;
    ll ans=1e18;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=min({dp[i-1][0]+a[i]*r1+r3,dp[i-1][1]+r2+d+r1+d+r1,dp[i-1][1]+r1*(a[i]+3)+d+d,dp[i-1][0]+r2+d+r1+d});
        dp[i][1]=min({dp[i-1][0]+r2+d,dp[i-1][0]+r1*a[i]+r1+d/*,dp[i-1][1]+r2+r1+d+d,dp[i-1][1]+r1*(a[i]+2)+d+d*/});
        if(i==n) ans=min({ans,dp[i][0],dp[i][1]+d+r1});
        else{
            ll rem=n-i;
            ans=min({ans,min(dp[i][0],dp[i][1]+r1)+(rem-1)*(r2+r1)+(2*rem-1)*d+min(min(ll(r2),r1*(a[n]+1))+d+d+r1,r1*a[n]+r3)});
            //dbg(i,min(dp[i][0],dp[i][1]+r1),(rem-1)*r2+(2*rem-1)*d,min(min(ll(r2),r1*(a[n]+1))+r1+r1+d,r1*a[n]+r3));
        }
        dp[i][0]+=d;
        //dbg(i,dp[i][0],dp[i][1]);
    }
    print(ans);
}
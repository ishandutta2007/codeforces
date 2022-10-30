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
const int mod=998244353;
const int maxn=1e3+7;
int dp[26][maxn][maxn];
void solve()
{
    string x,y;
    cin>>x>>y;
    int n=x.length(),m=y.length();
    vi nx(n),ny(m);
    for(int i=0;i<n;i++)
    {
        nx[i]=n-i;
        for(int j=i+1;j<n;j++)
        {
            if(x[j]==x[j-1])
            {
                nx[i]=j-i;
                break;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        ny[i]=m-i;
        for(int j=i+1;j<m;j++)
        {
            if(y[j]==y[j-1])
            {
                ny[i]=j-i;
                break;
            }
        }
    }
    //dbg(nx);dbg(ny);
    ll ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            ll cur=(dp[x[i]-'a'][i+1][j]+dp[y[j]-'a'][i][j+1])%mod;
            //dbg(cur,i,j,x[i],y[j]);
            if(x[i]!=y[j])
                cur=(cur+nx[i]+ny[j])%mod;
            for(int k=0;k<26;k++)
            {
                if(k!=(x[i]-'a'))
                    dp[k][i][j]=dp[x[i]-'a'][i+1][j];
                if(k!=(y[j]-'a'))
                    dp[k][i][j]=(dp[k][i][j]+dp[y[j]-'a'][i][j+1])%mod;
                if(x[i]!=y[j])
                {
                    if(k!=x[i]-'a')
                        dp[k][i][j]=(dp[k][i][j]+ny[j])%mod;
                    if(k!=y[j]-'a')
                        dp[k][i][j]=(dp[k][i][j]+nx[i])%mod;
                }
            }
            //dbg(i,j,cur);
            ans=(ans+cur)%mod;
        }
    }
    print(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;T=1;
    while(T--) solve();
}
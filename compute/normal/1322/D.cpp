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
const int maxn=4e3+7;
int dp[maxn][maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    vi l(n),s(n),c(n+m);
    for(int i=n-1;i>=0;i--) cin>>l[i];
    for(int i=n-1;i>=0;i--) cin>>s[i];
    for(int i=0;i<n+m;i++) cin>>c[i];
    vi mxcnt(n+m+1);
    vi cnt(m+1);
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        cnt[l[i]]++;
        for(int i=1;i<=n+m;i++) mxcnt[i]=mxcnt[i-1]/2+(i<=m?cnt[i]:0);
        //dbg(i,mxcnt);
        for(int k=mxcnt[l[i]];k>=1;k--)
            dp[l[i]][k]=max(dp[l[i]][k-1]-s[i]+c[l[i]-1],dp[l[i]][k]);
        for(int j=0;j<l[i];j++)
            for(int k=0;k<=1;k++)
                dp[l[i]][1]=max(dp[j][k]-s[i]+c[l[i]-1],dp[l[i]][1]);
        for(int j=1;j<n+m;j++)
        {
            for(int k=0;k<=mxcnt[j];k++)
            {
                dp[j+1][k/2]=max(dp[j+1][k/2],dp[j][k]+c[j]*(k/2));
                //dbg(i,j,k,dp[j][k]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n+m;i++) ans=max(ans,dp[n+m][i]);
    print(ans);
}
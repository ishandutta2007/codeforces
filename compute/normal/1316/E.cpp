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
const int maxn=1e5+7;
ll dp[maxn][1<<7];
int s[maxn][7];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,p,k;
    cin>>n>>p>>k;
    vi a(n),id(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        id[i]=i;
    }
    memset(dp,-0x3f,sizeof(dp));
    sort(id.begin(),id.end(),[&](int i,int j){return a[i]>a[j];});
    for(int i=0;i<n;i++)
        for(int j=0;j<p;j++)
            cin>>s[i][j];
    dp[0][0]=0;
    for(int i=0;i<k;i++) dp[0][0]+=a[id[i]];
    for(int i=1;i<=n;i++)
    {
        int cur=id[i-1];
        for(int S=0;S<(1<<p);S++)
        {
            if(dp[i-1][S]==-0x3f3f3f3f3f3f3f3f) continue;
            dp[i][S]=max(dp[i][S],dp[i-1][S]);
            int cc=__builtin_popcount(S);
            int cnt=i-cc;
            for(int j=0;j<p;j++)
            {
                if(!(S>>j&1))
                    dp[i][S|(1<<j)]=max(dp[i][S|(1<<j)],dp[i-1][S]+s[cur][j]+(cnt<=k?a[id[k+cc]]-a[cur]:0));
            }
            //dbg(i,S,dp[i][S]);
        }
    }
    cout<<dp[n][(1<<p)-1]<<'\n';

}
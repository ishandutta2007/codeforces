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
const int maxn=505;
int val[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        vi cnt(1505);
        for(int j=i;j<n;j++)
        {
            cnt[a[j]]++;
            static vi tmp;
            tmp=cnt;
            int mx=0;
            for(int k=1;k<1505;k++)
            {
                tmp[k]+=tmp[k-1]/2;
                if(tmp[k])
                    mx=k;
            }
            val[i][j]=mx;
           // dbg(i,j,mx);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int l=0,r=l+len-1;r<n;l++,r++)
        {
            for(int k=l;k<r;k++)
            {
                if(dp[l][k]==1&&dp[k+1][r]==1&&val[l][k]==val[k+1][r])
                    dp[l][r]=1;
                else dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
            //dbg(l,r,dp[l][r]);
        }
    }
    print(dp[0][n-1]);
}
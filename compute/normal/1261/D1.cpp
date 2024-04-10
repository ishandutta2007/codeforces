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
typedef pair<int,int> PII;
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
const int INF=0x3f3f3f3f;
const int maxn=2e3+7;
const int mod=998244353;
ll dp[maxn][maxn*2];
int h[maxn];
int n,k;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    dp[0][maxn]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<2*maxn-1;j++)
        {
            if(h[i]==h[i%n+1])
                dp[i][j]=dp[i-1][j]*k%mod;
            else{
                dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%mod;
                if(j)
                    dp[i][j-1]=(dp[i][j-1]+dp[i-1][j])%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j]*(k-2)%mod)%mod;
            }
        }
    }
    ll ans=0;
    for(int i=maxn+1;i<2*maxn;i++) ans=(ans+dp[n][i])%mod;
    cout<<ans<<endl;
    
}
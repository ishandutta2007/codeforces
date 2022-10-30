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
const int maxn = 1e7 + 10;
int prime[maxn] = {0}, phi[maxn] = {0}, tot;
int tar[maxn];
void euler()
{
    phi[1] = 1;
    tar[1]=1;
    for (int i = 2; i < maxn; i++)
    {
        if (!phi[i])
        {
            prime[tot++] = i;
            tar[i]=i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot && i * prime[j] < maxn; j++)
        {
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                if(tar[i]%prime[j]==0) tar[i*prime[j]]=tar[i]/prime[j];
                else tar[i*prime[j]]=tar[i]*prime[j];
                break;
            }
            tar[i*prime[j]]=tar[i]*prime[j];
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    euler();
    //for(int i=1;i<=100;i++) dbg(i,tar[i]);
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        vi a(n+1);
        int ans=1;
        map<int,int> ext;
        vvc<int> pos(n+1,vi(k+1,n+1));
        vi pre(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]=tar[a[i]];
            if(ext.count(a[i]))
                pre[i]=ext[a[i]];
            ext[a[i]]=i;
        }
        pos[0][0]=0;
        vvc<int> dp(n+1,vi(k+1,1e9));
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int ps=pos[i-1][j];
                if(pre[i]<=ps)
                    pos[i][j]=min(pos[i][j],ps);
                else{
                    if(j<k)
                        pos[i][j+1]=min(pos[i][j+1],pos[i-1][j]);
                    pos[i][j]=min(pos[i][j],pre[i]);
                }
            }
            for(int t=0;t<=k;t++)
            {
                for(int p=0;p+t<=k;p++)
                {
                    if(pos[i][t]>=0&&pos[i][t]<=n)
                        dp[i][p+t]=min(dp[i][p+t],dp[pos[i][t]][p]+1);
                }
            }
        }
        print(*min_element(dp[n].begin(),dp[n].end()));
    }
}
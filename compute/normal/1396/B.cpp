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
map<vi,int>dp;
int solve(vi a)
{
    if(dp.count(a)) return dp[a];
    int ret=0;
    for(int i=0;i<4;i++)
    {
        if(i==a[4]) continue;
        if(a[i])
        {
            vi nxt=a;
            nxt[i]=a[i]-1;
            nxt[4]=i;
            if(!solve(nxt)) ret=1;
        }
    }
    return dp[a]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*vi a(5);
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            for(int k=0;k<=10;k++)
            {
                for(int l=0;l<=0;l++)
                {
                    a[0]=i,a[1]=j,a[2]=k,a[3]=l,a[4]=5;
                    int sum=a[0]+a[1]+a[2]+a[3];
                    if(a[0]*2>sum||a[1]*2>sum||a[2]*2>sum||a[3]*2>sum) continue;
                    //dbg(a);
                    //dbg(solve(a));
                    if(!solve(a))
                    {
                        dbg(a);
                        dbg(sum);
                    }
                }
            }
        }
    }
    return 0;*/
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vi a(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        bool ok=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]*2>sum) ok=1;
        }
        if(ok||sum&1) cout<<"T\n";
        else cout<<"HL\n";
    }
    
}
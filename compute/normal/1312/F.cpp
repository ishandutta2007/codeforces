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
const int maxn=555;
int dp[maxn][3];
int v[3];
int lp;
int getsg(int u,int pre)
{
    if(dp[u][pre]!=-1) return dp[u][pre];
    int &ret=dp[u][pre];
    ret=0;
    if(u==0)
        return 0;
    set<int> all;
    for(int i=0;i<3;i++)
    {
        if(pre==0||i==0||i!=pre)
        {
            all.insert(getsg(max(0,u-v[i]),i));
        }
    }
    while(all.count(ret)) ret++;
    return ret;
}
void db()
{
    //dbg(v[0],v[1],v[2]);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<maxn;i++)
    {
        //dbg(i);
        for(int j=0;j<3;j++)
            getsg(i,j);
    }
    lp=-1;
    for(int i=2;i<=50;i++)
    {
        bool ok=1;
        for(int j=50;j<500;j++)
        {
            for(int k=0;k<3;k++)
                if(dp[j][k]!=dp[j+i][k]) ok=0;
            if(!ok) break;
        }
        if(ok)
        {
            lp=i;
            break;
        }
    }
    //dbg(lp);
    assert(lp!=-1);
}
int gv(ll x,int tp)
{
    if(x<0) return 0;
    if(x>500)
        x-=(x-500)/lp*lp;
    return dp[x][tp];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*for(v[0]=1;v[0]<=5;v[0]++)
    {
        for(v[1]=1;v[1]<=5;v[1]++)
            for(v[2]=1;v[2]<=5;v[2]++)
                db();
    }*/
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<3;i++) cin>>v[i];
        db();
        int s=0;
        int ans=0;
        vc<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s^=gv(a[i],0);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(!(s^gv(a[i],0)^gv(a[i]-v[j],j))) ans++;
            }
        }
        print(ans);
    }
}
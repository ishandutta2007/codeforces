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
const int maxn=4e4+7;
int a[maxn],b[maxn],pre[maxn],pb[maxn];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=m;i++) pb[i]=pb[i-1]+b[i];
    ll ans=0;
    for(int i=1;i*i<=k;i++)
    {
        if(k%i==0)
        {
            int x=i,y=k/i;
            int c1=0,c2=0;
            for(int j=x;j<=n;j++)
            {
                if(pre[j]-pre[j-x]==x) c1++;
            }
            for(int j=y;j<=m;j++)
            {
                if(pb[j]-pb[j-y]==y) c2++;
            }
            //dbg(x,y,c1,c2);
            ans+=(ll)c1*c2;
            if(i*i!=k)
            {
                swap(x,y);
                c1=0,c2=0;
                for(int j=x;j<=n;j++)
                {
                    if(pre[j]-pre[j-x]==x) c1++;
                }
                for(int j=y;j<=m;j++)
                {
                    if(pb[j]-pb[j-y]==y) c2++;
                }
                ans+=(ll)c1*c2;
            }
        }
    }
    print(ans);
}
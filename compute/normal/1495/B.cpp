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
    int n;
    cin>>n;
    vi p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    vi pre(n+2);
    vi suf(n+2);
    vi pmx(n+2),smx(n+2);
    for(int i=1;i<=n;i++)
    {
        if(p[i]>p[i-1]) pre[i]=pre[i-1]+1;
        else pre[i]=1;
    }
    for(int i=n;i>=1;i--)
    {
        if(p[i]>p[i+1]) suf[i]=suf[i+1]+1;
        else suf[i]=1;
    }
    for(int i=1;i<=n;i++)
        pmx[i]=max({pmx[i-1],pre[i],suf[i]});
    for(int i=n;i>=1;i--)
        smx[i]=max({smx[i+1],suf[i],pre[i]});
    auto isp=[&](int x){
        return p[x]>p[x-1]&&p[x]>p[x+1];
    };
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(isp(i))
        {
            int ylen=max(pmx[i-pre[i]],smx[i+suf[i]]);
            dbg(i,ylen);
            if(ylen>=max(pre[i],suf[i]));
            else{
                if(pre[i]==1||suf[i]==1);
                else{
                    if(pre[i]==suf[i])
                    {
                        if(pre[i]&1) ans++;
                    }
                    /*else{
                        int len=max(pre[i],suf[i]);
                        if(len&1) len--;
                        if(len==min(pre[i],suf[i]))
                        {
                            if(len&1) ans++;
                        }
                        else{

                        }
                    }*/
                }
            }
        }
    }
    print(ans);
}
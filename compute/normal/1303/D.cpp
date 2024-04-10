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
    int T;
    cin>>T;
    while(T--)
    {
        ll n;
        int m;
        cin>>n>>m;
        vi a(m);
        for(int i=0;i<m;i++) cin>>a[i];
        vi cnt(64);
        for(int i=0;i<m;i++)
        {
            int tmp=a[i];
            int cc=0;
            while(tmp>1)
            {
                tmp/=2;
                cc++;
            }
            cnt[cc]++;
        }
        int ans=0;
        bool ok=1;
        for(int i=0;i<60;i++)
        {
            if(n>>i&1)
            {
                if(cnt[i])
                    cnt[i]--;
                else{
                    int fd=0;
                    for(int j=i+1;j<30;j++)
                    {
                        if(cnt[j])
                        {
                            cnt[j]--;
                            fd=j;
                            ans++;
                            break;
                        }
                    }
                    if(!fd)
                    {
                        ok=0;
                        break;
                    }
                    for(int j=i+1;j<fd;j++) cnt[j]++,ans++;
                }
            }
            //dbg(i,cnt);
            cnt[i+1]+=cnt[i]/2;
        }
        if(!ok) ans=-1;
        print(ans);
    }
}
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
bool ok(int cnt,int tot,int dis,int d)
{
    if(tot>dis) return false;
    //dbg(cnt,tot,dis);
    tot-=cnt;
    dis-=tot;
    //dbg((dis+d-1)/d,cnt);
    return (dis+d-1)/d-1<=cnt;
}
int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    vi c(m);
    vi ans(n+1);
    int sum=0;
    for(int i=0;i<m;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }
    if(!ok(m,sum,n+1,d)) cout<<"NO\n";
    else{
        cout<<"YES\n";
        int cc=0;
        for(int i=1;i<=n;i++)
        {
            if(cc==m) break;
            if(ok(m-cc-1,sum-c[cc],n+1-(i-1)-c[cc],d))
            {
                for(int j=i;j<i+c[cc];j++)
                    ans[j]=cc+1;
                sum-=c[cc];
                i=i+c[cc]-1;
                cc++;
            }
        }
        assert(cc==m);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    }
    
}
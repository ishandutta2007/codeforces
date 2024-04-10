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
const int maxn=5e6+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n);
    map<int,vi> pos;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    vi big;
    for(auto &u:pos)
    {
        if(u.second.size()>=4)
        {
            cout<<"YES\n";
            vi op;
            for(int i=0;i<4;i++)
                op.push_back(u.second[i]+1);
            print(op);
            return 0;
        }
        else if(u.second.size()>=2)
            big.push_back(u.first);
    }
    if(big.size()>=2)
    {
        cout<<"YES\n";
        vi op;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                op.push_back(pos[big[j]][i]+1);
        }
        print(op);
    }
    else{
        int tar=-1;
        if(big.size()==1)
        {
            tar=big[0];
            int p1=pos[big[0]][0],p2=pos[big[0]][1];
            vi pre(maxn,-1);
            for(int i=0;i<n;i++)
            {
                if(a[i]==tar) continue;
                if(a[i]>=2*tar) continue;
                int cc=2*tar-a[i];
                if(pre[cc]!=-1)
                {
                    cout<<"YES\n";
                    cout<<p1+1<<" "<<p2+1<<" "<<pre[cc]+1<<" "<<i+1<<'\n';
                    return 0;
                }
                pre[a[i]]=i;
            }
        }
        vc<pi> pre(maxn,{-1,-1});
        int tp=-1;
        if(tar!=-1)
            tp=pos[tar][0];
        for(int i=0;i<n;i++)
        {
            if(a[i]==tar&&i!=tp) continue;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]==tar&&j!=tp) continue;
                int cur=a[i]+a[j];
                if(pre[cur].first!=-1)
                {
                    cout<<"YES\n";
                    cout<<i+1<<" "<<j+1<<" "<<pre[cur].first+1<<" "<<pre[cur].second+1<<'\n';
                    return 0;
                }
                pre[cur]=make_pair(i,j);
            }
        }
        cout<<"NO\n";
    }
}
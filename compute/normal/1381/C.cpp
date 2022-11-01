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
    int T;
    cin>>T;
    while(T--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        vi b(n);
        vc<vi> cnt(n+1);
        for(int i=0;i<n;i++)
        {
            cin>>b[i],b[i]--;
            cnt[b[i]].push_back(i);
        }
        int unuse=-1;
        for(int i=0;i<=n;i++)
        {
            if(!cnt[i].size())
            {
                unuse=i;
                break;
            }
        }
        priority_queue<pi> q;
        for(int i=0;i<=n;i++)
            q.emplace(cnt[i].size(),i);
        vi vis(n);
        y-=x;
        int rem=n-x;
        while(x--)
        {
            auto u=q.top();
            q.pop();
            int col=u.second;
            vis[cnt[col].back()]=1;
            cnt[col].pop_back();
            q.emplace(cnt[col].size(),col);
        }
        assert(y<=rem);
        while(rem>y&&q.top().first*2>rem)
        {
            auto u=q.top();
            q.pop();
            int col=u.second;
            b[cnt[col].back()]=unuse;
            vis[cnt[col].back()]=1;
            cnt[col].pop_back();
            q.emplace(cnt[col].size(),col);
            rem--;
        }
        int mx=q.top().first;
        if(mx*2>rem) cout<<"NO\n";
        else{
            cout<<"YES\n";
            vi all;
            for(int i=0;i<=n;i++)
            {
                for(auto u:cnt[i]) all.push_back(u);
            }
            int var=rem/2;
            if(y==rem)
            {
                for(int i=0;i<rem/2+(rem&1);i++)
                    swap(b[all[i]],b[all[i+var]]);
            }
            else{
                int cc=y/2;
                for(int i=0;i<cc;i++)
                {
                    swap(b[all[i]],b[all[i+var]]);
                    vis[all[i]]=1;
                    vis[all[i+var]]=1;
                }
                if(y&1)
                {
                    swap(b[all[cc]],b[all[cc+var]]);
                    vis[all[cc+var]]=1;
                }
                for(int i=0;i<n;i++)
                {
                    if(!vis[i]) b[i]=unuse;
                }
            }
            for(auto&u:b) u++;
            print(b);
        }
    }
}
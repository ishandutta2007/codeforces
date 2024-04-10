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
    int n,m,k;
    cin>>n>>m>>k;
    int tot=4*n*m-2*n-2*m;
    if(k>tot) cout<<"NO\n";
    else{
        vc<pair<int,char>> ans;
        int all=0;
        cout<<"YES\n";
        for(int i=1;i<n;i++)
        {
            if(m-1)
            {
                ans.push_back(make_pair(m-1,'R'));
                ans.push_back(make_pair(m-1,'L'));
            }
            ans.push_back(make_pair(1,'D'));
        }
        for(int i=2;i<=m;i++)
        {
            ans.push_back(make_pair(1,'R'));
            if(n-1)
            {
                ans.push_back(make_pair(n-1,'U'));
                ans.push_back(make_pair(n-1,'D'));
            }
        }
        if(m-1)
            ans.push_back(make_pair(m-1,'L'));
        if(n-1)
            ans.push_back(make_pair(n-1,'U'));
        vc<pair<int,char>> op;
        for(auto u:ans)
        {
            int step=min(k,u.first);
            op.push_back(make_pair(step,u.second));
            k-=step;
            if(!k) break;
        }
        print(op.size());
        for(auto u:op)
            cout<<u.first<<" "<<u.second<<'\n';
    }
}
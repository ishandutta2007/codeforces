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
const int maxn=2e5+7;
int pre[maxn][26];
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        pre[i+1][s[i]-'a']++;
        for(int j=0;j<26;j++) pre[i+1][j]+=pre[i][j];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int cur[26];
        for(int i=0;i<26;i++) cur[i]=pre[r][i]-pre[l-1][i];
        int tp=0;
        for(int i=0;i<26;i++)
        {
            if(cur[i]) tp++;
        }
        if(l==r)
            cout<<"Yes\n";
        else if(tp==1)
            cout<<"No\n";
        else{
            if(tp>=3)
                cout<<"Yes\n";
            else{
                if(s[l-1]==s[r-1]) cout<<"No\n";
                else cout<<"Yes\n";
            }
        }
    }
}
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
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
        cin>>n>>x;
        int c1=0,c0=0;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') c0++;
            else c1++;
        }
        if(c0==c1&&!x) print(-1);
        else{
            int d=c0-c1;
            int cur=0;
            int ans=0;
            if(x==0) ans++;
            bool ok=1;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0') cur++;
                else cur--;
                if(d>0&&x>=cur)
                {
                    if((x-cur)%d==0) ans++;
                }
                else if(d==0)
                {
                    if(x==cur)
                    {
                        ok=0;
                        break;
                    }
                }
                else if(d<0&&x<=cur)
                {
                    if((cur-x)%(-d)==0) ans++;
                }
            }
            if(!ok) print(-1);
            else print(ans);
        }
    }
}
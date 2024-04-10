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
        int n;
        cin>>n;
        string s;
        cin>>s;
        pi curpos={0,0};
        map<pi,int> pre;
        pre[curpos]=0;
        int milen=0x3f3f3f3f,l=-1,r=-1;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='L') curpos.first--;
            else if(s[i-1]=='R') curpos.first++;
            else if(s[i-1]=='U') curpos.second++;
            else curpos.second--;
            if(pre.count(curpos))
            {
                if(i-pre[curpos]<milen)
                {
                    milen=i-pre[curpos];
                    l=pre[curpos]+1;
                    r=i;
                }
            }
            pre[curpos]=i;
        }
        dbg(milen);
        if(milen==0x3f3f3f3f) cout<<"-1\n";
        else cout<<l<<" "<<r<<'\n';

    }
}
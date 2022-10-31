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
        int sum=0;
        for(int i=0;i<n;i++) sum+=s[i]-'0';
        string ans="";
        for(int i=n-1;i>=0;i--)
        {
            int v=s[i]-'0';
            if(v&1)
            {
                if(sum%2==0)
                {
                    ans=s;
                    break;
                }
                for(int j=i-1;j>=0;j--)
                {
                    int vv=s[j]-'0';
                    if(vv&1)
                    {
                        ans=s.substr(0,j)+s.substr(j+1,i-j);
                        break;
                    }
                }
            }
            if(ans!="") break;
            sum-=v;
            s.pop_back();
        }
        if(ans=="") print(-1);
        else cout<<ans<<'\n';
    }
}
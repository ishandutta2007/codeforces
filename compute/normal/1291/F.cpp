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
bool inline ask(int u)
{
    cout<<"? "<<u<<endl;
    string ret;
    cin>>ret;
    return ret=="Y";
}
int main()
{
    int n,k;
    cin>>n>>k;
    int var=max(1,k/2);
    int cnt=(n+var-1)/var;
    vi ok(n+1,1);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(ask(i)) ok[i]=0;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=i+2;j<=cnt;j++)
        {
            cout<<"R"<<endl;
            int l=(i-1)*var+1,r=i*var;
            for(int i=l;i<=r;i++)
                ask(i);
            l=(j-1)*var+1,r=min(n,j*var);
            for(int i=l;i<=r;i++)
                if(ask(i))ok[i]=0;
        }
    }
    for(int i=1;i<=n;i++) ans+=ok[i];
    cout<<"! "<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
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
const int INF=0x3f3f3f3f;

inline ll asks(int i,int j,int k)
{
    cout<<1<<" "<<i<<" "<<j<<" "<<k<<endl;
    ll ret;
    cin>>ret;
    return ret;
}

inline int askside(int j,int k)
{
    cout<<2<<" "<<1<<" "<<j<<" "<<k<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int main()
{
    int n;
    cin>>n;
    vi lj,ly,rj,ry;
    int lp=-1,rp=-1;
    srand(time(NULL));
    int tar=rand()%n+1;
    while(tar==1) tar=rand()%n+1;
    vector<pair<ll,int> > all;
    for(int i=2;i<=n;i++)
    {
        if(i==tar) continue;
        ll tmp=asks(1,tar,i);
        all.push_back(make_pair(tmp,i));
    }
    sort(all.begin(),all.end(),greater<pair<ll,int> >());
    for(int i=0;i<all.size();i++)
    {
        auto u=all[i];
        int f=askside(u.second,tar);
        if(f==1)
        {
            if(rp==-1)
                rp=u.second;
            else{
                f=askside(rp,u.second);
                if(f==1)
                    rj.push_back(u.second);
                else ry.push_back(u.second);
            }
        }
        else{
            if(lp==-1) lp=u.second;
            else{
                f=askside(lp,u.second);
                if(f==1)
                    ly.push_back(u.second);
                else lj.push_back(u.second);
            }
        }
        
    }
    cout<<"0 1 ";
        for(int i=ry.size()-1;i>=0;i--) cout<<ry[i]<<" ";
        if(rp!=-1) cout<<rp<<" ";
        for(auto u:rj) cout<<u<<" ";
        cout<<tar<<" ";
        for(int i=lj.size()-1;i>=0;i--) cout<<lj[i]<<" ";
        if(lp!=-1) cout<<lp<<" ";
        for(auto u:ly) cout<<u<<" ";
        cout<<endl;
}
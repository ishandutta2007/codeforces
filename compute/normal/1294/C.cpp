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
        int sv=n;
        vi all;
        vi fac;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                fac.push_back(i);
                while(n%i==0)
                {
                    n/=i;
                    all.push_back(i);
                }
            }
        }
        if(n>1)
        {
            fac.push_back(n);
            all.push_back(n);
        }
        if(all.size()>=6)
        {
            int a=all[0];
            int b=all[2]*all[1];
            int c=sv/a/b;
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<'\n';
        }
        else{
            bool ok=0;
            int a,b,c;
            if(fac.size()==2)
            {
                a=fac[0];
                b=fac[1];
                c=sv/a/b;
                if(c!=a&&c!=b&&c!=1) ok=1;
            }
            else if(fac.size()>=3)
            {
                ok=1;
                a=fac[0];
                b=fac[1];
                c=sv/a/b;
            }
            if(!ok) cout<<"NO\n";
            else{
                cout<<"YES\n";
                cout<<a<<" "<<b<<" "<<c<<'\n';
            }
        }
    }
}
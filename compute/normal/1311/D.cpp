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
        int a,b,c;
        cin>>a>>b>>c;
        int aa=1,bb=1,cc=1;
        int ans=a-1+b-1+c-1;
        for(int x=1;x<=20000;x++)
        {
            int cura=1;
            int curc=x;
            for(int i=1;i*i<=x;i++)
            {
               if(x%i==0)
               {
                   if(abs(i-a)<abs(cura-a)) cura=i;
                   if(abs(x/i-a)<abs(cura-a)) cura=x/i;
               }
            }
            int tar=c/x;
            curc=x*(tar+1);
            if(tar)
            {
                if(abs(curc-c)>abs(x*tar-c)) curc=x*tar;
            }
            int cur=abs(x-b)+abs(cura-a)+abs(curc-c);
            assert(x%cura==0&&curc%x==0);
            if(cur<ans)
            {
                ans=cur;
                aa=cura;
                bb=x;
                cc=curc;
            }
        }
        print(ans);
        cout<<aa<<" "<<bb<<" "<<cc<<'\n';
    }
}
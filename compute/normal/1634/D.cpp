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
int ask(int i,int j,int k)
{
    cout<<"? "<<i+1<<" "<<j+1<<" "<<k+1<<endl;
    int ret;
    cin>>ret;
    if(ret==-1) exit(0);
    return ret;
}
void answer(int x,int y)
{
    cout<<"! "<<x+1<<" "<<y+1<<endl;
}
int pre[4][4][4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<4;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                for(int k=j+1;k<4;k++)
                    pre[i][j][k]=pre[i][k][j]=pre[j][i][k]=pre[j][k][i]=pre[k][i][j]=pre[k][j][i]=ask(i,j,k);
            }
        }
        int l=0,r=0,val=0,div=-1;
        bool suc=0;
        for(int i=0;i<4;i++)
        {
            for(int j=i+1;j<4;j++)
            {
                int v1=-1,v2=-1;
                for(int k=0;k<4;k++)
                {
                    if(k!=i&&k!=j)
                    {
                        if(v1==-1) v1=k;
                        else v2=k;
                    }
                }
                assert(v1!=-1&&v2!=-1);
                if(pre[i][j][v1]==pre[i][j][v2])
                {
                    if(pre[i][j][v1]>div)
                    {
                        l=i,r=j;
                        val=v1;
                        div=pre[i][j][v1];
                        suc=1;
                    }
                    break;
                }
            }
        }
        //dbg(l, r);
        assert(suc);
        for(int i=4;i<n;i++)
        {
            int v1=ask(l,val,i),v2=ask(r,val,i);
            if(v1>div||v2>div)
            {
                if(v1>v2)
                    r=i;
                else l=i;
                div=max(v1,v2);
            }
        }
        answer(l,r);
    }
}
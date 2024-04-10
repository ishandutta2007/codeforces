#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int maxn=505;
int mazea[maxn][maxn],mazeb[maxn][maxn];
int col[maxn],row[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>mazea[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mazeb[i][j];
            mazeb[i][j]^=mazea[i][j];
            row[i]+=mazeb[i][j];
            col[j]+=mazeb[i][j];
        }
    }
    bool ok=1;
    for(int i=0;i<n;i++)
    {
        if(row[i]%2!=0) ok=0;
    }
    for(int i=0;i<m;i++) if(col[i]%2!=0) ok=0;
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
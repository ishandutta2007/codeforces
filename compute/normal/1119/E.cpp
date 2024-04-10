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
const int maxn=3e5+7;
int arr[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    long long res=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long cnt=min(1LL*arr[i]/2,res);
        ans+=cnt;
        arr[i]-=cnt*2;
        res-=cnt;
        ans+=arr[i]/3;
        res+=arr[i]%3;
    }
    printf("%lld\n",ans);
    
}
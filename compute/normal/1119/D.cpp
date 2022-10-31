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
const int maxn=1e5+7;
long long arr[maxn];
long long chafen[maxn];
long long pre[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    int q;
    scanf("%d",&q);
    sort(arr,arr+n);
    for(int i=1;i<n;i++) chafen[i]=arr[i]-arr[i-1];
    sort(chafen+1,chafen+1+n);
    for(int i=1;i<=n+1;i++) pre[i]=pre[i-1]+chafen[i];
    while(q--)
    {
        long long l,r;
        scanf("%lld%lld",&l,&r);
        long long delta=r-l+1;
        int pos=lower_bound(chafen+1,chafen+1+n,delta)-chafen;
        long long ans=(n-pos+1+1)*delta;
        ans+=pre[pos-1];
        printf("%lld ",ans);
    }
    puts("");
}
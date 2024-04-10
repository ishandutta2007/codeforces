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
const int maxn=1e3+7;
int arr[maxn];
int n,h;
bool check(int cur)
{
    vector<int> all;
    for(int i=1;i<=cur;i++) all.push_back(arr[i]);
    sort(all.begin(),all.end());
    reverse(all.begin(),all.end());
    long long ret=0;
    for(int i=0;i<all.size();i+=2) ret+=all[i];
    return ret<=h;
}
int main()
{
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    int l=0,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%d\n",ans);
}
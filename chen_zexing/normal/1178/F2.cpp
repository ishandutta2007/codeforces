#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[1000005],b[1000005];
long long mod=998244353;
long long dp[1005][1005];
vector <int> v[505];
long long dfs(int l,int r){
    if(dp[l][r]!=-1) return dp[l][r];
    int p=0,mn=INT_MAX;
    for(int i=l;i<=r;i++)
        if(mn>a[i]){
            p=i;
            mn=a[i];
        }
    if(v[mn][0]<l||v[mn][v[mn].size()-1]>r) return dp[l][r]=0;
    int p1=v[mn][0],p2=v[mn][v[mn].size()-1];
    long long c1=0,c2=0,c3=1;
    for(int i=l;i<p1-1;i++) c1+=dfs(l,i)*dfs(i+1,p1-1),c1%=mod;
    if(p1>l) c1+=2*dfs(l,p1-1),c1%=mod;
    else c1=1;
    for(int i=p2+1;i<r;i++) c2+=dfs(p2+1,i)*dfs(i+1,r),c2%=mod;
    if(p2<r) c2+=2*dfs(p2+1,r),c2%=mod;
    else c2=1;
    for(int i=0;i<v[mn].size()-1;i++) c3*=dfs(v[mn][i]+1,v[mn][i+1]-1),c3%=mod;
    return dp[l][r]=c1*c2%mod*c3%mod;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        int x=0;
        for(int i=1;i<=m;i++)
            if(i==1||b[i]!=b[i-1])
                a[++x]=b[i];
        m=x;
        if(m>n*2){
            puts("0");
            continue;
        }
        for(int i=1;i<=m;i++) v[a[i]].push_back(i);
        printf("%lld\n",dfs(1,m));
    }
    return 0;
}
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
int a[505];
long long mod=998244353;
long long dp[505][505];
long long dfs(int l,int r){
    if(dp[l][r]) return dp[l][r];
    if(l==r) return dp[l][r]=1;
    int p=0,mn=INT_MAX;
    for(int i=l;i<=r;i++)
        if(mn>a[i]){
            p=i;
            mn=a[i];
        }
    long long c1=0,c2=0;
    for(int i=l;i<p-1;i++) c1+=dfs(l,i)*dfs(i+1,p-1),c1%=mod;
    if(p>l) c1+=2*dfs(l,p-1),c1%=mod;
    else c1=1;
    for(int i=p+1;i<r;i++) c2+=dfs(p+1,i)*dfs(i+1,r),c2%=mod;
    if(p<r) c2+=2*dfs(p+1,r),c2%=mod;
    else c2=1;
    return dp[l][r]=c1*c2%mod;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        printf("%lld\n",dfs(1,n));
    }
    return 0;
}
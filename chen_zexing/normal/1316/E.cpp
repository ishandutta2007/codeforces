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
struct person{
    long long au;
    long long p[10];
}a[100005];
long long dp[100005][300];
bool cmp(person a,person b){
    return a.au>b.au;
}
int main() {
    int n,p,k;
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].au);
    for(int i=1;i<=n;i++)
        for(int j=0;j<p;j++)
            scanf("%lld",&a[i].p[j]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<p);j++){
            int c=0,t=j;
            while(t) c+=t%2,t>>=1;
            if(c>i) continue;
            if(c<i&&i-c<=k) dp[i][j]=dp[i-1][j]+a[i].au;
            else if(c<i) dp[i][j]=dp[i-1][j];
            else dp[i][j]=0;
            for(int l=0;l<p;l++)
                if((1<<l)&j)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-(1<<l)]+a[i].p[l]);
        }
    cout<<dp[n][(1<<p)-1]<<endl;
    return 0;
}
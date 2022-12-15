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
int a[1000005],cnt[1000005];
int dp[1000005][6][6];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=1;i<=m;i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<6;k++)
                        dp[i][j][k]=-999999;
        for(int i=0;i<=min(5,cnt[1]);i++) dp[1][0][i]=(cnt[1]-i)/3;
        for(int i=2;i<=m;i++){
            for(int j=0;j<=min(5,cnt[i-1]);j++)
                for(int k=0;k<=min(5,cnt[i]);k++)
                    for(int l=0;l<=min(5,cnt[i]-k)&&l+j<=5;l++)
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][l][l+j]+l+(cnt[i]-k-l)/3);
        }
        int ans=0;
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)
                ans=max(ans,dp[m][i][j]);
        cout<<ans<<endl;
    }
    return 0;
}
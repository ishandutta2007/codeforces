/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-05 00:32:52
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,p,k;
long long dp[100010][1<<7];
struct node{int val,s[8];}pl[100010];
bool cmp(node x,node y){return x.val>y.val;}
int main(){
    scanf("%d %d %d",&n,&p,&k);
    for(int i=1;i<=n;i++) scanf("%d",&pl[i].val);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++) scanf("%d",&pl[i].s[j]);
    }
    sort(pl+1,pl+n+1,cmp);
    for(int i=0;i<(1<<p);i++) dp[0][i]=-1e18;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int now=0;now<(1<<p);now++){
            dp[i][now]=-1e18;
            int cnt=0;
            for(int l=1;l<=p;l++){
                if((1<<(l-1))&now) cnt++;
                if((1<<(l-1))&now) dp[i][now]=max(dp[i][now],dp[i-1][now-(1<<(l-1))]+pl[i].s[l]);
            }
            if(i-cnt<k+1) dp[i][now]=max(dp[i][now],dp[i-1][now]+pl[i].val);
            else dp[i][now]=max(dp[i][now],dp[i-1][now]);
        }
    }
    printf("%lld",dp[n][(1<<p)-1]);
    return 0;
}
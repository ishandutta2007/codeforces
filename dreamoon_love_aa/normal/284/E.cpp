#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define MOD 1000000007
int last[311],next[311],a[311];
bool used[311];
long long dp[100001];
int main(){
    int i,j,k,n,q;
    long long t;
    scanf("%d%d%I64d",&n,&q,&t);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        next[x]=y;
        last[y]=x;
    }
    for(i=1;i<=n;i++){
        if(!last[i]){
            used[i]=1;
            int v=0;
            int now=i;
            v+=a[now];
            t-=v;
            while(next[now]){
                now=next[now];
                used[now]=1;
v+=a[now];
                a[now]=v;
                t-=v;
            }
            t+=v;
        }
    }
    for(i=1;i<=n;i++)
        if(!used[i])break;
    if(t<0||i<=n){
        puts("0");
        return 0;
    }
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=a[i];j<=t;j++){
            dp[j]+=dp[j-a[i]];
            if(dp[j]>=MOD)dp[j]-=MOD;
        }
    }
    cout<<dp[t]<<endl;
    return 0;
}
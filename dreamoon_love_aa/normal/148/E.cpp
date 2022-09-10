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
int dp[10001],a[101],b[101];
inline void handle1(int n){
    int i,j,now1=0,now2;
    memset(b,0,sizeof(b));
    for(i=0;i<=n;i++){
        now2=0;
        for(j=0;i+j<=n;j++){
            b[i+j]=max(b[i+j],now1+now2);
            now2+=a[n-j];
        }
        now1+=a[i+1];
    }
}
inline void fresh(int &x,int v){
    if(x<v)x=v;
}
inline void handle2(int k,int num){
    int i,j;
    for(i=num;i>=0;i--){
        for(j=0;j<=k&&j<=i;j++)
            if(dp[i-j]!=-1)fresh(dp[i],dp[i-j]+b[j]);
    }
}
int main(){ 
    int i,j,k,n,m,num=0;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        for(j=1;j<=k;j++)scanf("%d",&a[j]);
        handle1(k);
        num+=k;
        handle2(k,num);
    }
    printf("%d\n",dp[m]);
    return 0;
}
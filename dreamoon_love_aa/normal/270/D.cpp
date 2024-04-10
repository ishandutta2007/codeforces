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
int dp[5001][5001],sum[5001],a[5001];
void go(int ll,int rr,int lidx,int ridx,int from[],int to[]){
    int mm=(ll+rr)>>1;
    int res=-1,i,idx=-1;
    for(i=lidx;i<=ridx&&i<=mm;i++){
        if(from[i]+sum[mm]-sum[i]>res){
            res=from[i]+sum[mm]-sum[i];
            idx=i;
        }
    }
    to[mm]=res;
    if(ll<mm)go(ll,mm-1,lidx,idx,from,to);
    if(mm<rr)go(mm+1,rr,idx,ridx,from,to);
}
int main(){
    int i,j,k,n,m;
    double nouse;
    cin>>n>>m;
    for(i=1;i<=n;i++)scanf("%d%lf",&a[i],&nouse);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)sum[j]=sum[j-1]+(a[j]==i);
        go(1,n,0,n,dp[i-1],dp[i]);
    }
    printf("%d\n",n-dp[m][n]);
    return 0;
}
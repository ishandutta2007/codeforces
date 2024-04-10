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
#define SIZE 501
#define MAX 1000000000
int d[SIZE][SIZE],dp[2][SIZE][SIZE],a[SIZE][SIZE];
int get(int x,int y,int sz){
    return d[x][y]+d[x-sz][y-sz]-d[x][y-sz]-d[x-sz][y];
}
int main(){
    int i,j,k,n,m,now,an=-MAX;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            d[i][j]=a[i][j];
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)d[i][j]+=d[i][j-1];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)d[i][j]+=d[i-1][j];
    now=0;
    for(i=3;i<=m;i++){
        dp[now][i][3]=get(3,i,3)-a[2][i-1]-a[2][i-2];
        an=max(an,dp[now][i][3]);
    }
    for(i=4;i<=n;i++){
        for(j=3;j<=m;j++){
            dp[now^1][j][3]=get(i,j,3)-a[i-1][j-1]-a[i-1][j-2];
            an=max(dp[now^1][j][3],an);
            for(k=5;k<=i&&k<=j;k+=2){
                dp[now^1][j][k]=get(i,j,k)-dp[now][j-1][k-2]-a[i-k+2][j-k+1];
                an=max(an,dp[now^1][j][k]);
            }
        }
        now^=1;
    }
    printf("%d\n",an);
    return 0;
}
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
#define MAX 1000000
string str;
int dp[666][666],last[666][666];
void back(int x,int y){
    if(y!=1){
        back(last[x][y],y-1);
        printf("+");
    }
    int i,ll=last[x][y];
    for(i=1;ll+i<=x;i++){
        putchar(str[ll+i]);
        if(ll+i<x+1-i)str[x+1-i]=str[ll+i];
    }
}
int main(){
    int i,j,k,n,cc;
    cin>>str>>cc;
    n=str.size();
    for(i=0;i<=n;i++)
        for(j=0;j<=cc;j++)dp[i][j]=MAX;
    str=" "+str;
    dp[0][0]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<i;j++){
            int cnt=0;
            for(k=0;j+k+1<i-k;k++){
                if(str[j+k+1]!=str[i-k])cnt++;
            }
            for(k=0;k<=j&&k<cc;k++){
                if(dp[j][k]+cnt<dp[i][k+1]){
                    dp[i][k+1]=dp[j][k]+cnt;
                    last[i][k+1]=j;
                }
            }
        }
    }
    int mi=MAX,now;
    for(i=1;i<=cc;i++){
        if(dp[n][i]<mi){
            mi=dp[n][i];
            now=i;
        }
    }
    printf("%d\n",mi);
    back(n,now);
    return 0;
}
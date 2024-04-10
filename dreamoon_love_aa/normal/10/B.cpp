#include<stdio.h>
#include<stdlib.h>
#define SIZE 128
#define MAX 2147483647
bool seat[SIZE][SIZE];
int dp[SIZE][SIZE],dp2[SIZE][SIZE];
void Go(int x,int K){
    int mi=MAX,tmp,i,j,an1,an2,an3;
    for(i=1;i<=K;i++){
        for(j=x;j<=K;j++){
            if(dp[i][j]-dp[i][j-x]==0){
                if(mi>(tmp=dp2[i][j]-dp2[i][j-x])){
                    mi=tmp;
                    an1=i;
                    an2=j-x+1;
                    an3=j;
                }
            }
        }
    }
    if(mi==MAX)puts("-1");
    else{
        printf("%d %d %d\n",an1,an2,an3);
        for(i=0;i<x;i++)dp[an1][an2+i]+=i+1;
        for(i=an3+1;i<=K;i++)dp[an1][i]+=x;
    }
        
}
main(){
    int N,K,x,i,j;
    scanf("%d%d",&N,&K);
    for(i=1;i<=K;i++)
        for(j=1;j<=K;j++)
            dp2[i][j]=abs(i-(K+1)/2)+abs(j-(K+1)/2);
    for(i=1;i<=K;i++)
        for(j=1;j<=K;j++)
            dp2[i][j]+=dp2[i][j-1];
    for(i=0;i<N;i++){
        scanf("%d",&x);
        Go(x,K);
    }
}
#include<stdio.h>
#define SIZE 1024
double dp[SIZE][SIZE],A[SIZE][SIZE],a[SIZE];
main(){
    int N,M,i,j,k,x,y;
    scanf("%d%d",&N,&M);
    if(M==1){
        scanf("%d%d",&i,&j);
        printf("%lf\n",2*(1.*N-i));
    }
    else{
        scanf("%d%d",&x,&y);
        for(i=N-1;i>=x;i--){
            for(j=1;j<=M;j++)A[i][j]=A[i+1][j]+4;
            for(k=0;k<100;k++)
                for(j=1;j<=M;j++){
                    if(j==1)A[i][j]=A[i][j]/3+A[i][j+1]/3+A[i+1][j]/3+1;
                    else if(j==M)A[i][j]=A[i][j]/3+A[i][j-1]/3+A[i+1][j]/3+1;
                    else A[i][j]=A[i][j]*0.25+A[i][j+1]*0.25+A[i][j-1]*0.25+A[i+1][j]*0.25+1;
                }
        }
        printf("%lf\n",A[x][y]);
    }
}
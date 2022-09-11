#include<stdio.h>
int dp[21][12][5][5];
main(){
    int n,t,i,j,ii,jj,k,an=0;
    for(i=1;i<=4;i++)
        for(j=i+1;j<=4;j++)dp[2][0][i][j]=1;
    scanf("%d%d",&n,&t);
    for(i=2;i<n;i++)
        for(j=0;j<=t;j++)
            for(ii=1;ii<=4;ii++)
                for(jj=1;jj<=4;jj++){
                    if(ii==jj)continue;
                    for(k=1;k<=4;k++){
                        if(k==jj)continue;
                        if(k<jj){
                            if(jj>ii)dp[i+1][j+1][jj][k]+=dp[i][j][ii][jj];
                            else dp[i+1][j][jj][k]+=dp[i][j][ii][jj];
                        }
                        else{
                            dp[i+1][j][jj][k]+=dp[i][j][ii][jj];
                        }
                    }
                }
    for(i=4;i>1;i--)
        for(j=1;j<i;j++)an+=dp[n][t][i][j];
    printf("%d\n",an);
}
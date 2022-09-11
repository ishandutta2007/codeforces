#include<stdio.h>
#define SIZE 1500
long long a[SIZE][SIZE],dp[SIZE][SIZE];
main(){
    int n,m,i,j;
    long long an;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%I64d",&a[i][j]);
            if(j)a[i][j]+=a[i][j-1];
        }
    for(i=0;i<n;i++){
        if(i&1){
            for(j=0;j<m-1;j++){
                dp[i][j]=a[i][j];
                if(i&&j+1<m)dp[i][j]+=dp[i-1][j+1];
                if(j&&dp[i][j]<dp[i][j-1])dp[i][j]=dp[i][j-1];
            }
        }
        else{
            for(j=m-1;j>0;j--){
                dp[i][j]=a[i][j];
                if(i&&j)dp[i][j]+=dp[i-1][j-1];
                if(j+1<m&&dp[i][j]<dp[i][j+1])dp[i][j]=dp[i][j+1];
            }
        }
    }
    if(n%2==0)an=dp[n-1][m-2];
    else an=dp[n-1][1];
    printf("%I64d\n",an);
}
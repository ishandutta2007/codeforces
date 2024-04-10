#include<cstdio>
int i,j,dp[1555][1555],n,k,K;
main(){
  dp[0][0]=1;
  scanf("%d%d",&n,&K);
  for(int kk=0;kk<n;kk++){
    int x;
    scanf("%d",&x);
    for(i=500;i>=0;i--)
      for(j=500;j>=0;j--)
        if(dp[i][j])dp[i+x][j]=dp[i][j+x]=1;
  }
  for(i=0;i<=K;i++)
    k+=dp[i][K-i];
  printf("%d\n",k);
  for(i=0;i<=K;i++)
    if(dp[i][K-i])printf("%d ",i);
}
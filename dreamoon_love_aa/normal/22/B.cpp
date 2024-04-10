  #include<stdio.h>
  #include<algorithm>
  using namespace std;
  char Map[32][32];
  int dp[32][32];
  main(){
      int n,m,i,j,ii,jj,an=0;
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;i++)scanf("%s",Map[i]+1);
      for(i=1;i<=n;i++)
          for(j=1;j<=m;j++){
              if(Map[i][j]=='0')dp[i][j]=dp[i-1][j]+1;
              else dp[i][j]=0;
          }
      for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)dp[i][j]+=dp[i][j-1];
      for(i=1;i<=n;i++)
          for(j=1;j<=m;j++){
              for(ii=0;ii<i;ii++)
                  for(jj=0;jj<j;jj++)
                      if(dp[i][j]+dp[ii][jj]-dp[i][jj]-dp[ii][j]==(i-ii)*(j-jj))
                          an=max(an,i+j-ii-jj);
          }
      printf("%d\n",an*2);
  }
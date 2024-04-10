#include <stdio.h>
using namespace std;

double dp[3][1001][1001];

double rec(int h,int w,int b)
{
      if (dp[h][w][b]!=-1.0) return dp[h][w][b];
      if (w==0)
      {
               dp[h][w][b]=0.0;
               return 0.0;
      }
      if (b==0)
      {
                             dp[h][w][b]=1.0;
                             return 1.0;
      }
      
      double ww = 1.0*w/(w+b), bb = 1.0*b/(w+b);
      if (h==1)
      {
               dp[h][w][b]=ww+bb*(1-rec(2,w,b-1));
               return dp[h][w][b];
      }
      if (h==2)
      {
               dp[h][w][b]=ww;
               double www = 1.0*w/(w+b-1), bbb = 1.0*(b-1)/(w+b-1);
               dp[h][w][b]+=bb*www*(1-rec(1,w-1,b-1));
               if (b>1)dp[h][w][b]+=bb*bbb*(1-rec(1,w,b-2));
               return dp[h][w][b];
      }
}

int main()
{
    int w,b;
    scanf("%d%d",&w,&b);
    for (int h=1;h<=2;h++)
        for (int i=0;i<=w;i++)
            for (int j=0;j<=b;j++)
                dp[h][i][j]=-1.0;
    printf("%.9lf",rec(1,w,b));
    return 0;
}
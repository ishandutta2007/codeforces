#include <stdio.h>
#include <stdlib.h>

int N,K;

int dp[501][501];
int coins[500];
int out[501];
int out_cnt=0;

int comp(const void* a,const void *b)
{
  if(*(int*)a<*(int*)b)
    return -1;
  if(*(int*)a>*(int*)b)
    return 1;
  return 0;
}

int main()
{
  int i,j,k;
  scanf("%d %d",&N,&K);
  for(k=0;k<N;k++)
    scanf("%d",&coins[k]);
  dp[0][0]=1;
  for(k=0;k<N;k++)
    for(i=K;i>=0;i--)
      for(j=0;j<=K;j++)
	if(dp[i][j])
	  {
	    if(i+coins[k]<=K)
	      {
		dp[i+coins[k]][j]=1;
		if(j+coins[k]<=K)
		  dp[i+coins[k]][j+coins[k]]=1;
	      }
	  }
  for(i=0;i<=K;i++)
    if(dp[K][i]==1)
      out[out_cnt++]=i;
  qsort(out,out_cnt,sizeof(int),comp);
  printf("%d\n",out_cnt);
  for(i=0;i<out_cnt;i++)
    printf("%d\n",out[i]);
  return 0;
}
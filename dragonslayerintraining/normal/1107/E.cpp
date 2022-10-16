#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e9+7;

int64_t as[105];
char str[105];

int64_t dp1[105][105][105][2];
int64_t dp2[105][105];

void setmax(int64_t& x,int64_t y){
  x=std::max(x,y);
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  scanf("%s",str);
  for(int64_t i=0;i<N;i++){
    str[i]-='0';
  }
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t l=0;l<=N;l++){
    for(int64_t r=l;r<=N;r++){
      for(int64_t run=0;run<=N;run++){
	for(int64_t t=0;t<2;t++){
	  dp1[l][r][run][t]=-INF;
	}
      }
      dp2[l][r]=-INF;
    }
  }
  for(int64_t l=0;l<=N;l++){
    for(int64_t t=0;t<2;t++){
      dp1[l][l][0][t]=0;
    }
    dp2[l][l]=0;
  }
  for(int64_t l=N-1;l>=0;l--){
    for(int64_t r=l+1;r<=N;r++){
      for(int64_t run=1;run<=r-l;run++){
	setmax(dp1[l][r][run][str[l]],dp1[l+1][r][run-1][str[l]]);
      }
      for(int64_t run=0;run<=r-l;run++){
	for(int64_t t=0;t<2;t++){
	  for(int64_t m=l+1;m<=r;m++){
	    setmax(dp1[l][r][run][t],dp2[l][m]+dp1[m][r][run][t]);
	  }
	  //printf("dp1[%I64d,%I64d) run=%I64d, '%I64d': %I64d\n",l,r,run,t,dp1[l][r][run][t]);
	  setmax(dp2[l][r],dp1[l][r][run][t]+as[run]);
	}
      }
      //printf("dp2[%I64d,%I64d)=%I64d\n",l,r,dp2[l][r]);
    }
  }
  printf("%I64d\n",dp2[0][N]);
  return 0;
}
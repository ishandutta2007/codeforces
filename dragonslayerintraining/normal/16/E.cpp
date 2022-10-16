#include <cstdio>
#include <algorithm>

double as[18][18];

double dp[1<<18];
bool pop1[1<<18];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%lf",&as[i][j]);
    }
  }
  for(int k=0;k<N;k++){
    pop1[1<<k]=true;
  }
  for(int i=0;i<N;i++){
    std::fill(dp,dp+(1<<N),0);
    for(int mask=1;mask<(1<<N);mask++){
      if(pop1[mask]){
	dp[mask]=(mask==(1<<i));
	continue;
      }
      int cnt=0;
      for(int a=0;a<N;a++){
	if((mask&(1<<a))==0) continue;
	for(int b=a+1;b<N;b++){
	  if((mask&(1<<b))==0) continue;
	  dp[mask]+=as[a][b]*dp[mask&~(1<<b)]
	    +as[b][a]*dp[mask&~(1<<a)];
	  cnt++;
	}
      }
      dp[mask]/=cnt;
    }
    if(i) printf(" ");
    printf("%.10lf",dp[(1<<N)-1]);
  }
  printf("\n");
  return 0;
}
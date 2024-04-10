#include <cstdio>
#include <algorithm>
#include <cassert>

int as[2005],bs[2005];
long long A,B;
bool dp[2001][2001];//dp[index][#red berries in shrub basket mod K]

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d %d",&as[i],&bs[i]);
    A+=as[i],B+=bs[i];
  }
  dp[0][0]=true;
  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      if(dp[i][j]){
	dp[i+1][j]=true;
	continue;
      }
      for(int x=std::max(0,K-bs[i]);x<=std::min(K,as[i]);x++){
	if(dp[i][((j-x)%K+K)%K]){
	  dp[i+1][j]=true;
	  break;
	}
      }
    }
    assert(dp[i+1][0]);
  }
  long long best=A/K+B/K;
  for(int i=1;i<K;i++){
    if(dp[N][i]){
      assert(A>=i&&B>=K-i);
      best=std::max(best,1LL+(A-i)/K+(B-(K-i))/K);
    }
  }
  printf("%lld\n",best);
}
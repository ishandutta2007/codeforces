#include <cstdio>
#include <cassert>

long long dp[55]={1,1};
int ps[55];

int main(){
  int N;
  long long K;
  scanf("%d %lld",&N,&K);
  K--;
  for(int i=2;i<=50;i++){
    dp[i]=dp[i-1]+dp[i-2];
    //fprintf(stderr,"dp[%d]=%lld\n",i,dp[i]);
  }
  for(int i=0;i<N;i++){
    assert(K<dp[N-i]);
    if(K<dp[N-i-1]){
      ps[i]=i;
    }else{
      K-=dp[N-i-1];
      assert(i+1<N);
      ps[i]=i+1;
      ps[i+1]=i;
      i++;
    }
  }
  for(int i=0;i<N;i++){
    printf("%d ",ps[i]+1);
  }
  printf("\n");
}
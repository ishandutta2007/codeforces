#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>

std::vector<int64_t> factors;

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  if(K>2e5){
    printf("-1\n");
    return 0;
  }
  for(int64_t i=1;i<=100000;i++){
    if(N%i==0){
      factors.push_back(i);
      factors.push_back(N/i);
    }
  }
  std::sort(factors.begin(),factors.end());
  std::reverse(factors.begin(),factors.end());
  
  for(int64_t f:factors){
    if(K*(K+1)/2<=N/f&&K*(K+1)/2*f<=N){
      for(int64_t i=1;i<K;i++){
	printf("%I64d ",i*f);
      }
      printf("%I64d\n",N-(K-1)*K/2*f);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
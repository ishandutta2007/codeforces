#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[200000];
int64_t bs[200000];
int64_t N;

int64_t get(int64_t i){
  return bs[(i%N+N)%N];
}

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&bs[i]);
  }
  for(int64_t i=0;i<N;i++){
    if(get(i-1)<get(i)){
      as[i]=bs[i];
      for(int64_t j=(i+N-1)%N;j!=i;j=(j+N-1)%N){
	int64_t k=std::max<int64_t>(0,get(j-1)-get(j)+as[(j+1)%N])/as[(j+1)%N];
	as[j]=bs[j]+k*as[(j+1)%N];
      }
      printf("YES\n");
      for(int64_t j=0;j<N;j++){
	if(j) printf(" ");
	printf("%I64d",as[j]);
      }
      printf("\n");
      return 0;
    }
  }
  if(bs[0]==0){
    printf("YES\n");
    for(int i=0;i<N;i++){
      if(i) printf(" ");
      printf("1");
    }
    printf("\n");
  }else{
    printf("NO\n");
  }
  return 0;
}
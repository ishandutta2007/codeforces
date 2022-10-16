#include <cstdio>
#include <set>
#include <stdint.h>

std::set<int64_t> fun;
int N;

void add(int64_t k){
  fun.insert(((N/k-1)*k+2)*(N/k)/2);
}

int main(){
  scanf("%d",&N);
  for(int i=1;i*i<=N;i++){
    if(N%i==0){
      add(i);
      add(N/i);
    }
  }
  for(int64_t x:fun){
    printf("%I64d ",x);
  }
  printf("\n");
  return 0;
}
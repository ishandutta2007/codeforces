#include <cstdio>
#include <map>
#include <stdint.h>

std::map<int64_t,int64_t> best;
void read(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t A,X;
    scanf("%I64d %I64d",&A,&X);
    best[A]=std::max(best[A],X);
  }
}

int main(){
  read();
  read();
  int64_t total=0;
  for(auto it:best){
    total+=it.second;
  }
  printf("%I64d\n",total);
  return 0;
}
#include <cstdio>
#include <vector>
#include <stdint.h>
#include <cstdlib>

std::vector<int64_t> factors;

int64_t as[150005];
int64_t bs[150005];
int64_t N;

void factorize(int64_t Y){
  int64_t X=Y;
  for(int64_t i=2;i*i<=Y;i++){
    while(X%i==0){
      factors.push_back(i);
      X/=i;
    }
  }
  factors.push_back(X);
}

void check(int64_t X){
  for(int64_t i=0;i<N;i++){
    if(as[i]%X!=0&&bs[i]%X!=0) return;
  }
  printf("%I64d\n",X);
  exit(0);
}

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d %I64d",&as[i],&bs[i]);
  }
  factorize(as[0]);
  factorize(bs[0]);
  for(int64_t f:factors){
    if(f!=1) check(f);
  }
  printf("-1\n");
  return 0;
}
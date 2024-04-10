#include <cstdio>
#include <vector>
#include <stdint.h>

int64_t zcy(int64_t num){
  int64_t pal=num;
  std::vector<int> digits;
  while(num>0){
    digits.push_back(num%10);
    num/=10;
  }
  for(int d:digits){
    pal=pal*10+d;
  }
  return pal;
}

int main(){
  int K,P;
  scanf("%d %d",&K,&P);
  int64_t sum=0;
  for(int64_t i=1;i<=K;i++){
    sum=(sum+zcy(i))%P;
  }
  printf("%I64d\n",sum);
  return 0;
}
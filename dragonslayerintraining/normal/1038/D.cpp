#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stdint.h>

int as[500005];
int had=0;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if(N==1){
    printf("%d\n",as[0]);
    return 0;
  }
  int ex=1e9;
  int64_t sum=0;
  for(int i=0;i<N;i++){
    ex=std::min(ex,std::abs(as[i]));
    sum+=std::abs(as[i]);
    if(as[i]<=0) had|=1;
    if(as[i]>=0) had|=2;
  }
  if(had==3) ex=0;
  printf("%I64d\n",sum-ex*2);
  return 0;
}
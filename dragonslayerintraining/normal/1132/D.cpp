#include <cstdio>
#include <stdint.h>
#include <algorithm>

int64_t as[200005];
int64_t bs[200005];
int N,T;
int charge[200005];

bool check(int64_t x){
  std::fill(charge,charge+T,0);
  int cost=0;
  for(int i=0;i<N;i++){
    for(int k=0;;k++){
      int64_t at=(x*k+as[i])/bs[i];
      if(at>=T-1) break;
      //printf("charge %d at time %I64d\n",i,at);
      charge[at]++;
      cost++;
      if(cost>T) return false;
    }
    if(cost>T) return false;
  }
  int total=0;
  for(int t=0;t<T-1;t++){
    total+=charge[t];
    if(total>t+1) return false;
  }
  return true;
}

int main(){
  scanf("%d %d",&N,&T);
  for(int i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%I64d",&bs[i]);
  }
  int64_t low=-1,high=3e12;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    //printf("check(%I64d)\n",mid);
    if(check(mid)){
      high=mid;
    }else{
      low=mid;
    }
  }
  if(high<2.5e12){
    printf("%I64d\n",high);
  }else{
    printf("-1\n");
  }
  return 0;
}
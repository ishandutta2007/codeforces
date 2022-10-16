#include <cstdio>
#include <vector>
#include <stdint.h>

int64_t as[200005];
int64_t N;

int64_t bit[200005];

void add(int64_t i,int64_t v){
  for(i++;i<=N;i+=(i&-i)){
    bit[i]+=v;
  }
}

int64_t prefix(int64_t i){
  int64_t ac=0;
  for(i++;i>0;i-=(i&-i)){
    ac+=bit[i];
  }
  return ac;
}

std::vector<int64_t> erase[200005];

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
    if(as[i]<=N){
      erase[as[i]].push_back(i);
    }
  }
  for(int64_t i=0;i<N;i++){
    add(i,1);
  }
  int64_t sum=0;
  for(int64_t i=0;i<N;i++){
    for(int64_t v:erase[i]){
      //printf("ERASE %I64d\n",v);
      add(v,-1);
    }
    //printf("%I64d-%I64d\n",prefix(std::min(as[i]-1,N-1)),prefix(i));
    sum+=std::max<int64_t>(0,prefix(std::min(as[i]-1,N-1))-prefix(i));
  }
  printf("%I64d\n",sum);
  return 0;
}
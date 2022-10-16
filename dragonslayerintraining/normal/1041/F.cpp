#include <cstdio>
#include <stdint.h>
#include <map>

int64_t as[100005];
int64_t bs[100005];
int64_t N,M;

int64_t best=0;

void test(int64_t d){
  std::map<int64_t,int64_t> cnt;
  for(int64_t i=0;i<N;i++){
    cnt[as[i]%(2*d)]++;
  }
  for(int64_t i=0;i<M;i++){
    cnt[(bs[i]+d)%(2*d)]++;
  }
  for(auto it:cnt){
    best=std::max(best,it.second);
  }
}

std::map<int64_t,int64_t> vert;

int main(){
  int64_t Y1;
  scanf("%I64d %I64d",&N,&Y1);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
    vert[as[i]]++;
  }
  int64_t Y2;
  scanf("%I64d %I64d",&M,&Y2);
  for(int64_t i=0;i<M;i++){
    scanf("%I64d",&bs[i]);
    vert[bs[i]]++;
  }
  for(auto it:vert){
    best=std::max(best,it.second);
  }
  for(int64_t k=0;k<35;k++){
    test(1LL<<k);
  }
  printf("%I64d\n",best);
  return 0;
}
#include <cstdio>
#include <stdint.h>

int64_t as[100005];
int64_t ans;
int64_t L;

void change(int64_t i,int64_t v){
  if(as[i]<=L&&as[i+1]>L){
    ans+=v;
  }
}

int main(){
  int64_t N,M;
  scanf("%I64d %I64d %I64d",&N,&M,&L);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<=N;i++){
    change(i,1);
  }
  while(M-->0){
    int64_t T;
    scanf("%I64d",&T);
    if(T==0){
      printf("%I64d\n",ans);
    }else{
      int64_t P,D;
      scanf("%I64d %I64d",&P,&D);
      change(P-1,-1);
      change(P  ,-1);
      as[P]+=D;
      change(P-1,1);
      change(P  ,1);
    }
  }
  return 0;
}
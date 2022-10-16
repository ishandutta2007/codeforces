#include <cstdio>
#include <stdint.h>
#include <map>

int64_t as[200005];
int64_t ds[200005];

int main(){
  int64_t N,MOD;
  scanf("%I64d %I64d",&N,&MOD);
  for(int i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  int64_t ans=0;
  for(int64_t p=10;p<=10000000000LL;p*=10){
    std::map<int64_t,int64_t> ls;
    for(int i=0;i<N;i++){
      ls[(MOD-as[i]*(p%MOD)%MOD)%MOD]++;
    }
    for(int i=0;i<N;i++){
      if(as[i]<p&&!ds[i]){
	ds[i]=p;
	ans+=ls[as[i]%MOD];
      }
    }
  }
  for(int i=0;i<N;i++){
    if(as[i]*((ds[i]+1)%MOD)%MOD==0){
      ans--;
    }
  }
  printf("%I64d\n",ans);
  return 0;
}
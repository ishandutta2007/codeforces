#include <cstdio>
#include <map>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t as[100005];

int64_t bit[100006];
int64_t raw[100006];

void add(int64_t i,int64_t v){
  raw[i]=(raw[i]+v)%MOD;
  for(i++;i<100006;i+=(i&-i)){
    bit[i]=(bit[i]+v)%MOD;
  }
}

void set(int64_t i,int64_t v){
  add(i,(v+MOD-raw[i])%MOD);
}

int64_t prefix(int64_t i){
  int64_t ac=0;
  for(i++;i>0;i-=(i&-i)){
    ac=(ac+bit[i])%MOD;
  }
  return ac;
}

int64_t total=0;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  std::map<int64_t,int64_t> cps;
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
    cps[as[i]];
  }
  int64_t last=1;
  for(auto& pair:cps){
    pair.second=last++;
  }
  add(0,1);
  for(int64_t i=0;i<N;i++){
    int64_t x=cps[as[i]];
    int64_t q=prefix(x);
    set(x,q*as[i]%MOD);
  }
  printf("%I64d\n",(prefix(last)+MOD-1)%MOD);
  return 0;
}
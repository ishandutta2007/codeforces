#include <cstdio>
#include <stdint.h>
#include <algorithm>

const int64_t MOD=1e9+7;

int64_t pow2[100]={1};

void addmod(int64_t& x,int64_t y){x=(x+y)%MOD;}

int64_t prefix(int64_t X){
  int64_t next[2]={1,2};
  int64_t ans=0;
  for(int64_t k=0;X;k++){
    int64_t use=std::min<int64_t>(1LL<<k,X);
    X-=use;
    use%=MOD;
    addmod(ans,(next[k&1]+use-1)*use%MOD);
    addmod(next[k&1],2*use);
  }
  return ans;
}

int main(){
  int64_t L,R;
  scanf("%I64d %I64d",&L,&R);
  printf("%I64d\n",(prefix(R)+MOD-prefix(L-1))%MOD);
  return 0;
}
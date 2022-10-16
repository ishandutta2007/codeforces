#include <cstdio>
#include <valarray>
#include <stdint.h>

int N,K;
int ps[100005];

std::valarray<int64_t> bit[100005];
std::valarray<int64_t> dp[100005];

void update(int i,std::valarray<int64_t> v){
  for(;i<=N;i+=(i&-i)){
    bit[i]+=v;
  }
}

std::valarray<int64_t> query(int i){
  std::valarray<int64_t> res(K+1);
  for(;i>0;i-=(i&-i)){
    res+=bit[i];
  }
  return res;
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=1;i<=N;i++){
    scanf("%d",&ps[i]);
  }
  for(int i=1;i<=N;i++){
    bit[i]=std::valarray<int64_t>(K+1);
  }
  for(int i=1;i<=N;i++){
    dp[i]=query(ps[i]).shift(-1);
    dp[i][0]=1;
    update(ps[i],dp[i]);
  }
  printf("%I64d\n",query(N)[K]);
  return 0;
}
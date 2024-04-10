#include <cstdio>
#include <stdint.h>

const int64_t MOD=1e9+7;

const int LIMIT=1e5;

int64_t cnt[LIMIT+1];
int64_t pow2[LIMIT+1];

int main(){
  pow2[0]=1;
  for(int64_t i=1;i<=LIMIT;i++){
    pow2[i]=pow2[i-1]*2%MOD;
    //printf("2^%ld=%ld\n",i,pow2[i]);
  }
  
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    cnt[A]++;
  }
  for(int64_t i=1;i<=LIMIT;i++){
    for(int64_t k=i*2;k<=LIMIT;k+=i){
      cnt[i]+=cnt[k];
    }
  }
  for(int64_t i=1;i<=LIMIT;i++){
    cnt[i]=(pow2[cnt[i]]+MOD-1)%MOD;
    //printf("CNT %ld : %ld\n",i,cnt[i]);
  }
  for(int64_t i=LIMIT;i>=1;i--){
    for(int64_t k=i*2;k<=LIMIT;k+=i){
      cnt[i]=(cnt[i]-cnt[k]+MOD)%MOD;
    }
  }
  printf("%I64d\n",cnt[1]);
  return 0;
}
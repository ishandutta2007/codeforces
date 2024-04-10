#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t as[5005];
int64_t root[10005];
int64_t overlap[10005];
int64_t total[10005];
int64_t single[10005];


int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  std::reverse(as,as+N+1);
  for(int64_t i=0;i<N;i++){
    //printf(">%I64d\n",as[i]);
    for(int64_t j=i*2;j>=0;j--){
      root[j+2]=overlap[j]*((as[i]*(as[i]-1)/2)%MOD)%MOD;
      overlap[j+2]=overlap[j]*as[i]%MOD*as[i]%MOD;
    }
    for(int64_t j=0;j<=i*2;j++){
      total[j]=total[j]*as[i]%MOD;
    }
    root[1]=0;
    root[0]=1;
    overlap[1]=0;
    overlap[0]=1;
    for(int64_t j=0;j<i;j++){
      root[j+1]=(root[j+1]+single[j]*as[i])%MOD;
      overlap[j+1]=(overlap[j+1]+single[j]*as[i]*2)%MOD;
    }
    for(int64_t j=0;j<=i*2;j++){
      total[j]=(total[j]+root[j])%MOD;
      //printf("single[%I64d]=%I64d\toverlap[%I64d]=%I64d\troot[%I64d]=%I64d\ttotal[%I64d]=%I64d\n",j,single[j],j,overlap[j],j,root[j],j,total[j]);
    }
    for(int64_t j=i-1;j>=0;j--){
      single[j+1]=single[j]*as[i]%MOD;
    }
    single[0]=1;
  }
  for(int64_t i=1;i<=N*2-2;i++){
    if(i>1) printf(" ");
    printf("%I64d",total[i]);
  }
  printf("\n");
  return 0;
}
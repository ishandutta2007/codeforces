#include <cstdio>
#include <map>
#include <stdint.h>

const int64_t MOD=1e9+7;
const int64_t BASE1=618033993;
int64_t BASE2=1;

char A[2001][2001];
char B[2001][2001];

int64_t rowA[2001];
int64_t colB[2001];

std::map<int64_t,int64_t> id;

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=1;i<=M;i++){
    BASE2=BASE2*BASE1%MOD;
  }
  for(int64_t i=1;i<=N;i++){
    scanf("%s",A[i]+1);
  }
  for(int64_t i=1;i<=M;i++){
    scanf("%s",B[i]+1);
  }
  for(int64_t i=1;i<=N;i++){
    for(int64_t j=1;j<=M;j++){
      rowA[i]=(rowA[i]*BASE1+A[i][j])%MOD;
    }
  }
  for(int64_t i=1;i<=M;i++){
    for(int64_t j=1;j<=N;j++){
      colB[j]=(colB[j]*BASE2+B[i][j])%MOD;
    }
  }
  for(int64_t i=1;i<=N-M+1;i++){
    int64_t hash=0;
    for(int64_t j=0;j<M;j++){
      hash=(hash*BASE2+rowA[i+j])%MOD;
    }
    id[hash]=i;
  }
  for(int64_t i=1;i<=N-M+1;i++){
    int64_t hash=0;
    for(int64_t j=0;j<M;j++){
      hash=(hash*BASE1+colB[i+j])%MOD;
    }
    if(id.count(hash)){
      printf("%I64d %I64d\n",id[hash],i);
      return 0;
    }
  }
  return 0;
}
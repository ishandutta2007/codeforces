#include <iostream>
#include <cstdio>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t border[100001];
int64_t match[100001];
int64_t dp[100001];

int main(){
  std::string S,T;
  std::cin>>S>>T;
  border[0]=-1;
  for(int64_t i=0;i<T.size();i++){
    int64_t k=border[i];
    while((k>=0)&&(T[i]!=T[k])){
      k=border[k];
    }
    border[i+1]=k+1;
    //printf("border[%I64d]: %I64d\n",i+1,k+1);
  }
  for(int64_t i=0;i<S.size();i++){
    int64_t m=match[i];
    while((m>=0)&&(S[i]!=T[m])){
      m=border[m];
    }
    match[i+1]=m+1;
    //printf("match[%I64d]: %I64d\n",i+1,m+1);
  }
  int64_t j=0;
  int64_t sum=0;
  dp[0]=1;
  for(int64_t i=1;i<=S.size();i++){
    if(match[i]==T.size()){
      while(j<=i-T.size()){
	sum=(sum+dp[j++])%MOD;
      }
    }
    dp[i]=(dp[i-1]+sum)%MOD;
    //printf("sum[%I64d]=%I64d\n",i,sum);
    //printf("dp[%I64d]=%I64d\n",i,dp[i]);
  }
  printf("%I64d\n",(dp[S.size()]+MOD-1)%MOD);
  return 0;
}
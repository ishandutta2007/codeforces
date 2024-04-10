#include <iostream>
#include <stdint.h>
#include <cassert>

const int64_t MOD=1e9+7;

int64_t dp[16]={1};

struct matrix{
  int64_t mat[16][16];
  int N;
  matrix(int64_t N):N(N){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	mat[i][j]=(i==j);
      }
    }
  }
  void walks(){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	if((j==i+1)||(j==i)||(j==i-1)){
	  mat[i][j]=1;
	}else{
	  mat[i][j]=0;
	}
      }
    }
  }
  matrix(struct matrix a,struct matrix b):N(a.N){
    assert(a.N==b.N);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	mat[i][j]=0;
	for(int k=0;k<N;k++){
	  mat[i][j]=(mat[i][j]+a.mat[i][k]*b.mat[k][j])%MOD;
	}
      }
    }
  }
};

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    int64_t A,B,C;
    std::cin>>A>>B>>C;
    C++;
    std::fill(dp+C,dp+16,0);
    
    int64_t L=std::min(B,K)-A;
    struct matrix base(C);
    base.walks();
    struct matrix ac(C);
    for(int k=0;k<61;k++){
      if(L&(1LL<<k)){
	ac=matrix(ac,base);
      }
      base=matrix(base,base);
    }
    int64_t copy[16];
    for(int i=0;i<C;i++){
      copy[i]=0;
      for(int j=0;j<C;j++){
	copy[i]=(copy[i]+dp[j]*ac.mat[i][j])%MOD;
      }
    }
    for(int i=0;i<C;i++){
      dp[i]=copy[i];
    }
  }
  std::cout<<dp[0]<<std::endl;
  return 0;
}
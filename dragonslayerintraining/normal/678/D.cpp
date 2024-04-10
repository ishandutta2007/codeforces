#include <cstdio>

const int MOD=1e9+7;

struct Matrix{
  int mat[2][2];
  Matrix operator*(Matrix other)const{
    Matrix res{{{0,0},{0,0}}};
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
	for(int k=0;k<2;k++){
	  res.mat[i][k]=(res.mat[i][k]+1LL*mat[i][j]*other.mat[j][k])%MOD;
	}
      }
    }
    return res;
  }
};

int main(){
  int A,B,X;
  long long N;
  scanf("%d %d %lld %d",&A,&B,&N,&X);
  struct Matrix base{{{A,B},{0,1}}};
  struct Matrix ac{{{1,0},{0,1}}};
  for(;N;N>>=1){
    if(N&1) ac=ac*base;
    base=base*base;
  }
  printf("%lld\n",(1LL*ac.mat[0][0]*X+ac.mat[0][1])%MOD);
}
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <cassert>

const int64_t MOD=1e9+7;

int64_t matrix[100][101];
int64_t lap[100][100];

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      ac=ac*base%MOD;
    }
    base=base*base%MOD;
  }
  return ac;
}

int64_t inverse(int64_t a){
  return modpow(a,MOD-2);
}

void swaprows(int64_t i,int64_t k,int64_t N){
  for(int j=0;j<N;j++){
    std::swap(matrix[k][j],matrix[i][j]);
  }
}

void addrow(int64_t i,int64_t k,int64_t scale,int64_t N){
  for(int j=0;j<N;j++){
    matrix[k][j]=(matrix[k][j]+matrix[i][j]*scale)%MOD;
  }
}

void scalerow(int64_t i,int64_t scale,int64_t N){
  for(int j=0;j<N;j++){
    matrix[i][j]=(matrix[i][j]*scale)%MOD;
  }
}

int64_t det(int64_t N){
  int64_t res=1;
  for(int64_t i=0;i<N;i++){
    if(matrix[i][i]==0){
      for(int64_t k=i+1;k<N;k++){
	if(matrix[k][i]!=0){
	  swaprows(i,k,N);
	  res=(MOD-res)%MOD;
	  break;
	}
      }
    }
    
    if(matrix[i][i]==0) return 0;
    res=res*matrix[i][i]%MOD;
    scalerow(i,inverse(matrix[i][i]),N);
    
    for(int64_t k=i+1;k<N;k++){
      addrow(i,k,(MOD-matrix[k][i])%MOD,N);
    }
  }
  return res;
}

void solve(int64_t N){
  for(int64_t i=0;i<N;i++){
    for(int64_t k=i;k<N;k++){
      if(matrix[k][i]!=0){
	swaprows(i,k,N+1);//N+1 to include augment
	break;
      }
    }
    assert(matrix[i][i]!=0);//Vandermonde matrix has an inverse
    
    scalerow(i,inverse(matrix[i][i]),N+1);
    
    for(int64_t k=i+1;k<N;k++){
      addrow(i,k,(MOD-matrix[k][i])%MOD,N+1);
    }
  }
  for(int64_t i=N-1;i>=0;i--){
    for(int64_t k=i-1;k>=0;k--){
      addrow(i,k,(MOD-matrix[k][i])%MOD,N+1);
    }
  }
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    lap[U][V]--;
    lap[V][U]--;
    lap[U][U]++;
    lap[V][V]++;
  }
  for(int64_t x=0;x<N;x++){
    for(int64_t i=0;i<N;i++){
      for(int64_t j=0;j<N;j++){
	if(i==j){
	  matrix[i][j]=((x-1)*lap[i][j]+N-1+MOD)%MOD;
	}else{
	  matrix[i][j]=((x-1)*lap[i][j]-1+MOD)%MOD;
	}
      }
    }
    //Augment matrix for solving system
    matrix[x][N]=det(N-1);
  }
  //Vandermonde matrix
  for(int64_t i=0;i<N;i++){
    int64_t pow=1;
    for(int64_t j=0;j<N;j++){
      matrix[i][j]=pow;
      pow=pow*i%MOD;
    }
  }
  solve(N);
  for(int64_t i=0;i<N;i++){
    if(i) printf(" ");
    printf("%I64d",matrix[i][N]);
  }
  printf("\n");
  return 0;
}
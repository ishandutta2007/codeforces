#include <iostream>
#include <stdint.h>
#include <cassert>

const int64_t MOD=1e9+7;

struct Matrix{
  int64_t* mat;
  int rows,cols;
  int64_t& operator()(int r,int c){
    return mat[r*cols+c];
  }
  int64_t operator()(int r,int c)const{
    return mat[r*cols+c];
  }
  Matrix(const Matrix& other):rows(other.rows),cols(other.cols){
    mat=new int64_t[rows*cols];
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
	(*this)(i,j)=other(i,j);
      }
    }
  }
  struct Matrix& operator=(const Matrix& other){
    Matrix(other).swap(*this);
  }
  void swap(Matrix& other){
    std::swap(mat,other.mat);
    std::swap(rows,other.rows);
    std::swap(cols,other.cols);
  }
  Matrix(int rows,int cols):rows(rows),cols(cols){
    mat=new int64_t[rows*cols];
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
	(*this)(i,j)=0;
      }
    }
  }
  ~Matrix(){
    delete mat;
  }
  struct Matrix operator*(struct Matrix other){
    assert(cols==other.rows);
    struct Matrix ret(rows,other.cols);
    for(int i=0;i<rows;i++){
      for(int j=0;j<other.cols;j++){
	for(int k=0;k<cols;k++){
	  ret(i,j)+=((*this)(i,k)*other(k,j))%MOD;
	}
	ret(i,j)%=MOD;
      }
    }
    return ret;
  }
};

int alphaToInt(char c){
  if(std::islower(c)){
    return c-'a';
  }else{
    return c-'A'+26;
  }
}

int main(){
  int64_t N,M,K;
  std::cin>>N>>M>>K;
  struct Matrix base(M,M);
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      base(i,j)=1;
    }
  }
  for(int i=0;i<K;i++){
    std::string forbid;
    std::cin>>forbid;
    base(alphaToInt(forbid[0]),alphaToInt(forbid[1]))=0;
  }
  struct Matrix exp(M,M);
  for(int i=0;i<M;i++){
    exp(i,i)=1;
  }
  for(int k=0;k<50;k++){
    if((N-1)&(1LL<<k)){
      exp=exp*base;
    }
    base=base*base;
  }
  int64_t sum=0;
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      sum+=exp(i,j);
    }
  }
  std::cout<<sum%MOD<<std::endl;
}
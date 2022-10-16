#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <map>
#include <stdint.h>

const double PI=4*atan(1);

typedef struct Complex{
  double real,imag;
  Complex(double real,double imag):real(real),imag(imag){
  }
  Complex():Complex(0,0){
  }
  struct Complex operator+(struct Complex other)const{
    return Complex(real+other.real,imag+other.imag);
  }
  struct Complex operator-(struct Complex other)const{
    return Complex(real-other.real,imag-other.imag);
  }
  struct Complex operator*(struct Complex other)const{
    return Complex(real*other.real-imag*other.imag,real*other.imag+imag*other.real);
  }
  struct Complex operator/(double other)const{
    return Complex(real/other,imag/other);
  }
  static struct Complex polar(double magn,double angle){
    return Complex(magn*std::cos(angle),magn*std::sin(angle));
  }
}Complex;

class FFT{
  int Z;
  std::vector<int> rev;
  std::vector<Complex> omega;
public:
  FFT(int Z):Z(Z),rev(1<<Z),omega(1<<Z){
    rev[1]=1;
    for(int k=0;k<Z;k++){
      for(int i=0;i<(1<<k);i++){
	rev[i]<<=1;
      }
      for(int i=(1<<k);i<(2<<k);i++){
	rev[i]=rev[i-(1<<k)]|1;
      }
    }
    for(int i=0;i<(1<<Z);i++){
      omega[i]=Complex::polar(1,2*PI*i/(1<<Z));
    }
  }
  void fft(std::vector<Complex>& as){
    assert(as.size()<=(1<<Z));
    as.resize(1<<Z);
    for(int i=0;i<(1<<Z);i++){
      if(i<rev[i]) std::swap(as[i],as[rev[i]]);
    }
    for(int k=0;k<Z;k++){
      for(int i=0;i<(1<<Z);i++){
	if(i&(1<<k)){
	  int j=i&~(1<<k);
	  int p=(i&((1<<k)-1));
	  Complex x=as[j],y=as[i];
	  as[j]=x+omega[p<<(Z-k-1)]*y;
	  as[i]=x-omega[p<<(Z-k-1)]*y;
	}
      }
    }
  }
  void ifft(std::vector<Complex >& as){
    assert(as.size()<=(1<<Z));
    as.resize(1<<Z);
    std::reverse(as.begin()+1,as.end());
    fft(as);
    for(int i=0;i<(1<<Z);i++){
      as[i]=as[i]/(1<<Z);
    }
  }
};

int as[200005];
int64_t total[200005];

void solve(int L,int R){
  if(L>R) return;
  int M=(L+R)/2;
  std::vector<struct Complex> left(M-L+1),right(R-M+1);
  {
    int pow=0;
    left[pow].real++;
    for(int i=M-1;i>=L;i--){
      pow+=as[i];
      left[pow].real++;
    }
  }
  {
    int pow=0;
    right[pow].real++;
    for(int i=M+1;i<=R;i++){
      pow+=as[i];
      right[pow].real++;
    }
  }
  int k=0;
  while((1<<k)<=(R-L+1)) k++;
  struct FFT fft(k);
  fft.fft(left);
  fft.fft(right);
  for(int i=0;i<(1<<k);i++){
    left[i]=left[i]*right[i];
  }
  fft.ifft(left);
  for(int i=0;i<=(R-L+1);i++){
    total[i+as[M]]+=(int64_t)(left[i].real+0.5);
  }
  solve(L,M-1);
  solve(M+1,R);
}

int main(){
  int N,X;
  scanf("%d %d",&N,&X);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]=(as[i]<X);
  }
  solve(0,N-1);
  for(int i=0;i<=N;i++){
    if(i) printf(" ");
    printf("%I64d",total[i]);
  }
  printf("\n");
  return 0;
}
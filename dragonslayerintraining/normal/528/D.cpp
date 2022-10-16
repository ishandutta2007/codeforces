#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <map>

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

int K;
std::string atgc="ATGC";

std::vector<Complex> fuzzy(std::string S,char c){
  std::vector<int> prefix(S.length()+1);
  std::vector<Complex> ret(S.length());
  //printf("K=%d\n",K);
  for(int i=0;i<S.length();i++){
    if(S[i]==c){
      prefix[std::max<int>(0,i-K)]++;
      prefix[std::min<int>(S.length(),i+K+1)]--;
    }
  }
  for(int i=0;i<S.length();i++){
    prefix[i+1]+=prefix[i];
    //printf("%d",prefix[i]);
  }
  //printf("\n");
  for(int i=0;i<S.length();i++){
    ret[i]=Complex(prefix[i]>0,0);
  }
  return ret;
}

int main(){
  /*
  std::vector<Complex > as(1<<Z),bs(1<<Z);
  as[0]=1;
  as[1]=1;
  fft(as);
  fft(bs);
  
  for(int i=0;i<(1<<Z);i++){
    printf("as[%d]= %lf %lf\n",i,as[i].real,as[i].imag);
  }
  for(int i=0;i<(1<<Z);i++){
    as[i]*=as[i];
  }
  ifft(as);
  ifft(bs);
  for(int i=0;i<(1<<Z);i++){
    printf("as[%d]= %lf %lf\n",i,as[i].real,as[i].imag);
  }
  
  return 0;
  */
  int S_len,T_len;
  std::cin>>S_len>>T_len>>K;
  std::string S,T;
  std::cin>>S>>T;
  std::reverse(T.begin(),T.end());
  std::vector<Complex> polyS(S.size()),polyT(T.size());
  std::vector<int> sum(S.size()+T.size());
  struct FFT fft(19);
  for(char c:atgc){
    polyS=fuzzy(S,c);
    polyT.clear();
    polyT.resize(T.size());
    for(int i=0;i<T.size();i++){
      polyT[i]=Complex(T[i]==c,0);
    }
    fft.fft(polyS);
    fft.fft(polyT);
    for(int i=0;i<(1<<19);i++){
      polyS[i]=polyS[i]*polyT[i];
    }
    fft.ifft(polyS);
    for(int i=0;i<S.size()+T.size();i++){
      sum[i]+=(int)(polyS[i].real+0.5);
      //printf("%c %d: %d\n",c,i,(int)(polyS[i].real+0.5));
    }
  }
  /*
  for(int i=0;i<S.size();i++){
    printf("%d: %d\n",i,sum[i]);
  }
  */
  printf("%d\n",(int)std::count(sum.begin(),sum.end(),T.size()));
  return 0;
}
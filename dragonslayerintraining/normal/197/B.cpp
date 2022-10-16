#include <iostream>
#include <vector>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

void output(int num,int den){
  int sgn=1;
  if(num<0){num=-num,sgn=-sgn;}
  if(den<0){den=-den,sgn=-sgn;}
  int g=gcd(num,den);
  num/=g,den/=g;
  num*=sgn;
  std::cout<<num<<"/"<<den<<std::endl;
}

int N,M;
std::vector<int> a,b;

int main(){
  std::cin>>N>>M;
  int L=std::max(N,M);
  a.resize(L+1);
  b.resize(L+1);
  for(int i=L-N;i<=L;i++){
    std::cin>>a[i];
  }
  for(int i=L-M;i<=L;i++){
    std::cin>>b[i];
  }
  int bsign;
  for(int i=0;i<=L;i++){
    if(b[i]>0){
      bsign=1;
      break;
    }
    if(b[i]<0){
      bsign=-1;
      break;
    }
  }
  for(int i=0;i<=L;i++){
    if(b[i]!=0){
      output(a[i],b[i]);
      return 0;
    }
    if(a[i]*bsign>0){
      std::cout<<"Infinity"<<std::endl;
      return 0;
    }else if(a[i]*bsign<0){
      std::cout<<"-Infinity"<<std::endl;
      return 0;
    }
  }
  return 0;
}
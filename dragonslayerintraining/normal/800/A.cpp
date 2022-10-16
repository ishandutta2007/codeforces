#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdint.h>

int64_t N,P;
struct device{
  int64_t A,B;
  bool operator<(struct device other)const{
    return B*other.A<A*other.B;
  }
}devices[100000];


int main(){
  std::cin>>N>>P;
  for(int64_t i=0;i<N;i++){
    std::cin>>devices[i].A>>devices[i].B;
  }
  std::sort(devices,devices+N);
  int64_t A=0,B=0;
  double res=-1;
  for(int64_t i=0;i<N;i++){
    B+=devices[i].B;
    A+=devices[i].A;
    if(A>P){
      double t=double(B)/(A-P);
      if(res<0){
	res=t;
      }else{
	res=std::min(res,t);
      }
    }
  }
  if(res>=0){
    std::cout<<std::fixed<<std::setprecision(10)<<res<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}
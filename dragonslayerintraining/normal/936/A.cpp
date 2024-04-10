#include <iostream>
#include <iomanip>
#include <stdint.h>

int main(){
  int64_t K,D,T;
  std::cin>>K>>D>>T;
  if(D<=K){
    D=(K+D-1)/D*D;
  }
  double first=double(K)/T;
  double second=double(D-K)/2/T;
  int64_t cycles=(int64_t)(1/(first+second));
  double time=cycles*D;
  double left=1-cycles*(first+second);
  if(left<=first){
    time+=T*left;
  }else{
    time+=K;
    left-=first;
    time+=2*T*left;
  }
  std::cout<<std::fixed<<std::setprecision(10)<<time<<std::endl;
  return 0;
}
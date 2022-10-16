#include <iostream>
#include <iomanip>
#include <cmath>

int xs[100],ys[100];

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>xs[i]>>ys[i];
  }
  double sum=0;
  for(int i=1;i<N;i++){
    double dx=xs[i]-xs[i-1];
    double dy=ys[i]-ys[i-1];
    sum+=std::sqrt(dx*dx+dy*dy);
  }
  std::cout<<std::setprecision(7)<<sum*K/50<<std::endl;
  return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <algorithm>

double pyth(double x,double y){
  return std::sqrt(x*x+y*y);
}

int main(){
  int A,B;
  std::cin>>A>>B;
  int N;
  std::cin>>N;
  double min=INFINITY;
  for(int i=0;i<N;i++){
    int X,Y,V;
    std::cin>>X>>Y>>V;
    min=std::min(min,pyth(X-A,Y-B)/V);
  }
  std::cout<<std::fixed<<std::setprecision(10)<<min<<std::endl;
  return 0;
}
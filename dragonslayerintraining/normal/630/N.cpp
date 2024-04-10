#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
  int A,B,C;
  std::cin>>A>>B>>C;
  double disc=std::sqrt(B*B-4*A*C);
  double r1=(-B+disc)/2/A,r2=(-B-disc)/2/A;
  std::cout<<std::fixed<<std::setprecision(10)<<std::max(r1,r2)<<std::endl<<std::min(r1,r2)<<std::endl;
  return 0;
}
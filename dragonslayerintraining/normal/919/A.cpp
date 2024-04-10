#include <iostream>
#include <iomanip>

int main(){
  int N,M;
  std::cin>>N>>M;
  double best=1e9;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    best=std::min(best,double(A)/B);
  }
  std::cout<<std::fixed<<std::setprecision(10)<<M*best<<std::endl;
  return 0;
}
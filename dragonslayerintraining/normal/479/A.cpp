#include <iostream>
#include <algorithm>

int main(){
  int A,B,C;
  int best=0;
  std::cin>>A>>B>>C;
  best=std::max(best,A+B+C);
  best=std::max(best,A+B*C);
  best=std::max(best,A*B+C);
  best=std::max(best,A*B*C);
  best=std::max(best,(A+B)*C);
  best=std::max(best,A*(B+C));
  std::cout<<best<<std::endl;
  return 0;
}
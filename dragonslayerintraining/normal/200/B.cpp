#include <iostream>
#include <iomanip>

int main(){
  int N;
  std::cin>>N;
  int sum=0;
  for(int i=0;i<N;i++){
    int orange;
    std::cin>>orange;
    sum+=orange;
  }
  std::cout<<std::fixed<<std::setprecision(10)<<double(sum)/N<<std::endl;
  return 0;
}
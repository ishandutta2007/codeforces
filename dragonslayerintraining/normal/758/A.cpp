#include <iostream>
#include <algorithm>

int as[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int max=*std::max_element(as,as+N);
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=max-as[i];
  }
  std::cout<<sum<<std::endl;
  return 0;
}
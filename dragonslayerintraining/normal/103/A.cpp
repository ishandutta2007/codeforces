#include <iostream>

int main(){
  int N;
  std::cin>>N;
  long long clicks=0;
  for(int i=0;i<N;i++){
    long long A;
    std::cin>>A;
    clicks+=(i+1)*(A-1)+1;
  }
  std::cout<<clicks<<std::endl;
  return 0;
}
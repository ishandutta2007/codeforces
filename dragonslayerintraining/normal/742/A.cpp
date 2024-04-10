#include <iostream>

int ans[]={1,8,4,2,6};

int main(){
  int N;
  std::cin>>N;
  std::cout<<ans[(N-1)%4+1]<<std::endl;
  return 0;
}
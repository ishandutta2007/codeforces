#include <iostream>

int main(){
  int N,A;
  std::cin>>N>>A;
  std::cout<<"2 1 "<<std::max(3,std::min(N,(N*A+90)/180+2))<<std::endl;
  return 0;
}
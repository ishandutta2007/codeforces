#include <iostream>

int N;

int prefix[101];

int main(){
  std::cin>>N;
  prefix[0]=0;
  for(int i=1;i<N;i++){
    int D;
    std::cin>>D;
    prefix[i]=prefix[i-1]+D;
  }
  int A,B;
  std::cin>>A>>B;
  std::cout<<prefix[B-1]-prefix[A-1]<<std::endl;
  return 0;
}
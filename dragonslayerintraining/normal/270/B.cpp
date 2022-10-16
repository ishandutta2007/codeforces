#include <iostream>

int as[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    A--;
    as[i]=A;
  }
  int i;
  for(i=N-1;(i>0)&&(as[i-1]<as[i]);i--);
  std::cout<<i<<std::endl;
  return 0;
}
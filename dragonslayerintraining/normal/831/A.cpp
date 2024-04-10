#include <iostream>

int N;

int as[100];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int i=1;
  for(;(i<N)&&(as[i-1]<as[i]);i++);
  for(;(i<N)&&(as[i-1]==as[i]);i++);
  for(;(i<N)&&(as[i-1]>as[i]);i++);
  std::cout<<((i==N)?"YES":"NO")<<std::endl;
  return 0;
}
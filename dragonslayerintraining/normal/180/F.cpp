#include <iostream>

int where[100000];
int to[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    A--;
    where[A]=i;
  }
  for(int i=0;i<N;i++){
    int B;
    std::cin>>B;
    B--;
    to[i]=where[B];
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<to[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}
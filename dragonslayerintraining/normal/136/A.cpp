#include <iostream>

int from[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    from[A-1]=i;
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<from[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}
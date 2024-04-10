#include <iostream>
#include <algorithm>

int main(){
  int N,X;
  std::cin>>N>>X;
  int min=0,max=1e9;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    if(A>B){
      std::swap(A,B);
    }
    min=std::max(min,A);
    max=std::min(max,B);
  }
  if(min>max){
    std::cout<<-1<<std::endl;
  }else if(X<min){
    std::cout<<min-X<<std::endl;
  }else if(X>max){
    std::cout<<X-max<<std::endl;
  }else{
    std::cout<<0<<std::endl;
  }
  return 0;
}
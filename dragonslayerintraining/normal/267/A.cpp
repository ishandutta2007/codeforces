#include <iostream>
#include <tuple>

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    if(A<B){
      std::swap(A,B);
    }
    int cnt=0;
    while(B>0){
      cnt+=A/B;
      std::tie(A,B)=std::make_tuple(B,A%B);
    }
    std::cout<<cnt<<std::endl;
  }
}
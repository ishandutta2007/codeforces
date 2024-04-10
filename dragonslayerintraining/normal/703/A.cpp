#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int diff=0;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    diff+=(A>B)-(A<B);
  }
  if(diff>0){
    std::cout<<"Mishka"<<std::endl;
  }else if(diff<0){
    std::cout<<"Chris"<<std::endl;
  }else{
    std::cout<<"Friendship is magic!^^"<<std::endl;
  }
  return 0;
}
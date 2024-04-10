#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  int pos=0;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    if(A>pos){
      break;
    }
    pos=std::max(pos,B);
  }
  if(pos>=M){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}
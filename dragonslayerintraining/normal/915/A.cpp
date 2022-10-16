#include <iostream>

int best=0;

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(K%A==0){
      best=std::max(best,A);
    }
  }
  std::cout<<K/best<<std::endl;
  return 0;
}
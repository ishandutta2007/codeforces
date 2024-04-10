#include <iostream>

int rs[300];

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<2*N+1;i++){
    std::cin>>rs[i];
  }
  for(int i=1;i<2*N+1;i+=2){
    if(K==0){
      break;
    }
    if((rs[i]>rs[i-1]+1)&&(rs[i]>rs[i+1]+1)){
      rs[i]--;
      K--;
    }
  }
  for(int i=0;i<2*N+1;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<rs[i];
  }
  std::cout<<std::endl;
  
  return 0;
}
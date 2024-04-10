#include <iostream>

int big=0;

int log4roof(int num){
  int k;
  for(k=0;(1<<(k*2))<num;k++);
  return k;
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int K,A;
    std::cin>>K>>A;
    if(A>1){
      big=std::max(big,K+log4roof(A));
    }else{
      big=std::max(big,K+1);
    }
  }
  std::cout<<big<<std::endl;
  return 0;
}
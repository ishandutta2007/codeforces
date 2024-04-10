#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int prev=1e9+1;
  int run=0;
  int best=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A>prev){
      run++;
    }else{
      run=1;
    }
    best=std::max(best,run);
    prev=A;
  }
  std::cout<<best<<std::endl;
  return 0;
}
#include <iostream>

int main(){
  int N,T,C;
  std::cin>>N>>T>>C;
  int run=0;
  int cnt=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A>T){
      run=0;
    }else{
      run++;
      cnt+=(run>=C);
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
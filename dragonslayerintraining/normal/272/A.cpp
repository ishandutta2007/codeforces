#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int T=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    T+=A;
  }
  int cnt=0;
  for(int i=1;i<=5;i++){
    if((T+i)%(N+1)!=1){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
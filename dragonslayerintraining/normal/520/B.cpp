#include <iostream>

int N,M;
int main(){
  std::cin>>N>>M;
  int cnt=0;
  while(M>N){
    if(M%2==1){
      M++;
      cnt++;
    }
    M/=2;
    cnt++;
  }
  std::cout<<cnt+N-M<<std::endl;
  return 0;
}
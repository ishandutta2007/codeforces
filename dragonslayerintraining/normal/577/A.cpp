#include <iostream>

int main(){
  int N,X;
  std::cin>>N>>X;
  int cnt=0;
  for(int i=1;i<=N;i++){
    if((X%i==0)&&(X/i<=N)){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
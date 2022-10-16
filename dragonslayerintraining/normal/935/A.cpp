#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int cnt=0;
  for(int l=1;l<N;l++){
    if(N%l==0){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
#include <iostream>

int as[1000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int cnt=0;
  for(int i=1;i<N-1;i++){
    if(((as[i]>as[i-1])&&(as[i]>as[i+1]))||
       ((as[i]<as[i-1])&&(as[i]<as[i+1]))){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
#include <iostream>

int popcnt(int X){
  int cnt=0;
  for(;X>0;X>>=1){
    cnt+=(X&1);
  }
  return cnt;
}

int player[1000];

int main(){
  int N,M,K;
  std::cin>>N>>M>>K;
  for(int i=0;i<M;i++){
    std::cin>>player[i];
  }
  int fedor;
  std::cin>>fedor;
  int cnt=0;
  for(int i=0;i<M;i++){
    if(popcnt(player[i]^fedor)<=K){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
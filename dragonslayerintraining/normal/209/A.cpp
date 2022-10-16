#include <iostream>

const int MOD=1e9+7;

int main(){
  int N;
  std::cin>>N;
  int state[2]={0,0};
  for(int i=0;i<N;i++){
    state[i%2]=(state[i%2]+state[(i+1)%2]+1)%MOD;
  }
  std::cout<<(state[0]+state[1])%MOD<<std::endl;
  return 0;
}
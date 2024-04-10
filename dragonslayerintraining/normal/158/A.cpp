#include <iostream>

int scores[100];

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>scores[i];
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if(scores[i]>=std::max(scores[K-1],1)){
      cnt++;
    }else{
      break;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
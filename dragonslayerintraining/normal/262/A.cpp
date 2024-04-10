#include <iostream>

int lucky(int num){
  int cnt=0;
  for(;num>0;num/=10){
    switch(num%10){
    case 4:
    case 7:
      cnt++;
      break;
    }
  }
  return cnt;
}

int main(){
  int N,K;
  std::cin>>N>>K;
  int cnt=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(lucky(A)<=K){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
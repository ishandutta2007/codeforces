#include <iostream>

int digits(int num){
  int mask=0;
  for(;num>0;num/=10){
    mask|=(1<<(num%10));
  }
  return mask;
}

int main(){
  int N;
  std::cin>>N;
  int cnt=0;
  for(int i=1;i*i<=N;i++){
    if(N%i!=0){
      continue;
    }
    if(digits(N)&digits(i)){
      cnt++;
    }
    if(i<N/i){
      if(digits(N)&digits(N/i)){
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
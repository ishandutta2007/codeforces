#include <iostream>

bool isalmostprime(int num){
  int cnt=0;
  for(int i=2;num>1;i++){
    if(num%i==0){
      cnt++;
      while(num%i==0){
	num/=i;
      }
    }
  }
  return cnt==2;
}

int main(){
  int N;
  std::cin>>N;
  int cnt=0;
  for(int i=1;i<=N;i++){
    cnt+=isalmostprime(i);
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
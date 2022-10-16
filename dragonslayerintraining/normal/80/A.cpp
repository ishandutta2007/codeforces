#include <iostream>

bool isprime(int num){
  for(int i=2;i*i<=num;i++){
    if(num%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=N+1;i<=M;i++){
    if(isprime(i)){
      if(i==M){
	std::cout<<"YES"<<std::endl;
	return 0;
      }
      break;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}
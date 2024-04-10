#include <iostream>

bool islucky(int n){
  for(;n>0;n/=10){
    switch(n%10){
    case 4:case 7:break;
    default:return false;
    }
  }
  return true;
}

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<=N;i++){
    if(N%i==0){
      if(islucky(i)){
	std::cout<<"YES"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}
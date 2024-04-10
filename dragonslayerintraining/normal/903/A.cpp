#include <iostream>

bool check(int X){
  if(X>=21){
    return true;
  }
  for(int a=0;a<=X/3;a++){
    for(int b=0;b<=X/7;b++){
      if(a*3+b*7==X){
	return true;
      }
    }
  }
  return false;
}

int main(){
  int N;
  std::cin>>N;
  while(N-->0){
    int X;
    std::cin>>X;
    if(check(X)){
      std::cout<<"YES"<<std::endl;
    }else{
      std::cout<<"NO"<<std::endl;
    }
  }
  return 0;
}
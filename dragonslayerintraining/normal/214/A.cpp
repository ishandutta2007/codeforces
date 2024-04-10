#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  int cnt=0;
  for(int a=0;a<=1000;a++){
    for(int b=0;b<=1000;b++){
      if((a*a+b==N)&&(a+b*b==M)){
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
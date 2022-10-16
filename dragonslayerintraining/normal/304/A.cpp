#include <iostream>

int cnt=0;

int main(){
  int N;
  std::cin>>N;
  for(int a=1;a<=N;a++){
    int c=0;
    for(int b=a;a*a+b*b<=N*N;b++){
      while(a*a+b*b>c*c){
	c++;
      }
      if(a*a+b*b==c*c){
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
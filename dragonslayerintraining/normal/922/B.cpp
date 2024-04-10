#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int cnt=0;
  for(int a=1;a<=N;a++){
    for(int b=a;b<=N;b++){
      int c=a^b;
      if((c>=b)&&(c<=N)&&
	 (a+b>c)&&(a+c>b)&&(b+c>a)){
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
#include <iostream>

int N,A,B;

int main(){
  std::cin>>N>>A>>B;
  int X=1;
  while(((A/X+B/X)>=N)&&(X<=A)&&(X<=B)){
    X++;
  }
  std::cout<<X-1<<std::endl;
  return 0;
}
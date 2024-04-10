#include <iostream>

int main(){
  int N;
  std::cin>>N;
  std::string name(N,'o');
  int a=1,b=1;
  while(a<=name.size()){
    name[a-1]='O';
    int c=a+b;
    a=b,b=c;
  }
  std::cout<<name<<std::endl;
  return 0;
}
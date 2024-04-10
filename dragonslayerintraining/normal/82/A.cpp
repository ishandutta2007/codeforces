#include <iostream>

std::string f(int N){
  switch(N){
  case 0:return "Sheldon";
  case 1:return "Leonard";
  case 2:return "Penny";
  case 3:return "Rajesh";
  case 4:return "Howard";
  }
  return f((N-5)/2);
}

int main(){
  int N;
  std::cin>>N;
  std::cout<<f(N-1)<<std::endl;
  return 0;
}
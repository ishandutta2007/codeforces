#include <iostream>

bool nodupdigits(int N){
  bool has[10]={false,false,false,false,false,
		false,false,false,false,false};
  for(;N>0;N/=10){
    if(has[N%10]){
      return false;
    }
    has[N%10]=true;
  }
  return true;
}

int main(){
  int N;
  std::cin>>N;
  for(N++;!nodupdigits(N);N++);
  std::cout<<N<<std::endl;
  return 0;
}
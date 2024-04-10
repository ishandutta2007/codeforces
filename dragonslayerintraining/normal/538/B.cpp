#include <iostream>

int max=0;
int quasi[10];

int main(){
  std::string N;
  std::cin>>N;
  for(char c:N){
    for(int d=1;d<10;d++){
      quasi[d]=quasi[d]*10+(c-'0'>=d);
    }
    max=std::max(max,c-'0');
  }
  std::cout<<max<<std::endl;
  for(int i=1;i<=max;i++){
    if(i>1){
      std::cout<<" ";
    }
    std::cout<<quasi[i];
  }
  std::cout<<std::endl;
  return 0;
}
#include <iostream>

int sum=0;

int main(){
  for(int i=0;i<5;i++){
    int C;
    std::cin>>C;
    sum+=C;
  }
  if((sum>0)&&(sum%5==0)){
    std::cout<<sum/5<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}
#include <iostream>

int main(){
  int M,S;
  std::cin>>M>>S;
  if((S==0)&&(M==1)){
    std::cout<<0<<" "<<0<<std::endl;
    return 0;
  }
  if((S==0)||(S>9*M)){
    std::cout<<-1<<" "<<-1<<std::endl;
    return 0;
  }
  {
    int rem=S;
    for(int i=0;i<M;i++){
      int digit=std::max(rem-9*(M-i-1),0);
      if(i==0){
	digit=std::max(digit,1);
      }
      std::cout<<digit;
      rem-=digit;
    }
  }
  std::cout<<" ";
  {
    int rem=S;
    for(int i=0;i<M;i++){
      int digit=std::min(rem,9);
      std::cout<<digit;
      rem-=digit;
    }
  }
  std::cout<<std::endl;
  return 0;
}
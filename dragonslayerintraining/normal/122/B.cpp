#include <iostream>
#include <cctype>

int cnt[10];
int main(){
  char c;
  while(std::isdigit(c=std::cin.get())){
    cnt[c-'0']++;
  }
  if((cnt[4]==0)&&(cnt[7]==0)){
    std::cout<<-1<<std::endl;
  }else if(cnt[4]>=cnt[7]){
    std::cout<<4<<std::endl;
  }else{
    std::cout<<7<<std::endl;
  }
  return 0;
}
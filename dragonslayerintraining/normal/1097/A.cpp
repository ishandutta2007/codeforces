#include <iostream>

std::string table,card[5];

int main(){
  std::cin>>table;
  for(int i=0;i<5;i++){
    std::cin>>card[i];
    if(card[i][0]==table[0]||card[i][1]==table[1]){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}
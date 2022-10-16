#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int x=0;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    if((str=="++X")||(str=="X++")){
      x++;
    }else if((str=="--X")||(str=="X--")){
      x--;
    }
  }
  std::cout<<x<<std::endl;
  return 0;
}
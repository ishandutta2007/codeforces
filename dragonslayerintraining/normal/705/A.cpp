#include <iostream>

int main(){
  int N;
  std::cin>>N;
  for(int i=0;;i++){
    if(i%2==0){
      std::cout<<"I hate ";
    }else{
      std::cout<<"I love ";
    }
    if(i==N-1){
      std::cout<<"it"<<std::endl;;
      return 0;
    }else{
      std::cout<<"that ";
    }
  }
}
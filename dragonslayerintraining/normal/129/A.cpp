#include <iostream>

int oddcnt,evencnt;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A%2==0){
      evencnt++;
    }else{
      oddcnt++;
    }
  }
  std::cout<<((oddcnt%2==0)?evencnt:oddcnt)<<std::endl;
  
  return 0;
}
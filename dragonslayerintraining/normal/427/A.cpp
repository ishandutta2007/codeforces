#include <iostream>

int untreated=0;
int open=0;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A<0){
      if(open>0){
	open--;
      }else{
	untreated++;
      }
    }else{
      open+=A;
    }
  }
  std::cout<<untreated<<std::endl;
  return 0;
}
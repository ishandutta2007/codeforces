#include <iostream>

int A,B,C;

int deny=0;

int main(){
  int N;
  std::cin>>N>>A>>B;
  for(int i=0;i<N;i++){
    int T;
    std::cin>>T;
    switch(T){
    case 1:
      if(A>0){
	A--;
      }else if(B>0){
	B--;
	C++;
      }else if(C>0){
	C--;
      }else{
	deny++;
      }
      break;
    case 2:
      if(B>0){
	B--;
      }else{
	deny+=2;
      }
      break;
    }
  }
  std::cout<<deny<<std::endl;
  return 0;
}
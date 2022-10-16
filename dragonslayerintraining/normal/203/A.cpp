#include <iostream>

int main(){
  int X,T,A,B,DA,DB;
  std::cin>>X>>T>>A>>B>>DA>>DB;
  for(int i=0;i<=T;i++){
    for(int j=0;j<=T;j++){
      int score=0;
      if(i<T){
	score+=A-i*DA;
      }
      if(j<T){
	score+=B-j*DB;
      }
      if(X==score){
	std::cout<<"YES"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}
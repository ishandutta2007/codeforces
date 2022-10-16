#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int sum=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int A;
      std::cin>>A;
      if((i==j)||(i==(N/2))||(i+j==N-1)||(j==(N/2))){
	sum+=A;
      }
    }
  }
  std::cout<<sum<<std::endl;
  return 0;
}
#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int sum=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    sum+=A;
  }
  if(sum%N==0){
    std::cout<<N<<std::endl;
  }else{
    std::cout<<N-1<<std::endl;
  }
  return 0;
}
#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int cnt=0;
  for(int i=0;i<N;i++){
    int A,B,C;
    std::cin>>A>>B>>C;
    cnt+=((A+B+C)>=2);
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
#include <iostream>
#include <algorithm>

int ac;
int max;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    ac-=A;
    max=std::max(max,ac);
    ac+=B;
    max=std::max(max,ac);
  }
  std::cout<<max<<std::endl;
  return 0;
}
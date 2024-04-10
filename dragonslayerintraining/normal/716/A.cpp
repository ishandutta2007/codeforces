#include <iostream>
#include <algorithm>

int main(){
  int N,C;
  std::cin>>N>>C;
  int words=0;
  int last=-1e9;
  for(int i=0;i<N;i++){
    int T;
    std::cin>>T;
    if(T-last>C){
      words=0;
    }
    words++;
    last=T;
  }
  std::cout<<words<<std::endl;
  return 0;
}
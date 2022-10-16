#include <iostream>

int main(){
  int N,D;
  std::cin>>N>>D;

  int start;
  int cnt=0;
  std::cin>>start;
  for(int i=1;i<N;i++){
    int next;
    std::cin>>next;
    if(next<=start){
      int times=(start-next)/D+1;
      next+=times*D;
      cnt+=times;
    }
    start=next;
  }

  std::cout<<cnt<<std::endl;
  return 0;
}
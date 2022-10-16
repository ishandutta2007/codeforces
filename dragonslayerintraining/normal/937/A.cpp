#include <iostream>
#include <set>

int main(){
  std::set<int> distinct;
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A) distinct.insert(A);
  }
  std::cout<<distinct.size()<<std::endl;
  return 0;
}
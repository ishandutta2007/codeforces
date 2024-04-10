#include <iostream>
#include <set>

std::multiset<int> as,bs;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    as.insert(A);
  }
  for(int i=0;i<N-1;i++){
    int B;
    std::cin>>B;
    bs.insert(B);
    as.erase(as.find(B));
  }
  for(int i=0;i<N-2;i++){
    int C;
    std::cin>>C;
    bs.erase(bs.find(C));
  }
  std::cout<<*as.begin()<<std::endl;
  std::cout<<*bs.begin()<<std::endl;
  return 0;
}
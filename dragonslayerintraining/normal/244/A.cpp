#include <iostream>
#include <set>

int first[30];

int main(){
  int N,K;
  std::cin>>N>>K;
  std::set<int> all;
  for(int i=1;i<=N*K;i++){
    all.insert(i);
  }
  for(int i=0;i<K;i++){
    std::cin>>first[i];
    all.erase(first[i]);
  }
  for(int i=0;i<K;i++){
    std::cout<<first[i];
    for(int j=1;j<N;j++){
      int piece=*all.begin();
      std::cout<<" "<<piece;
      all.erase(piece);
    }
    std::cout<<std::endl;
  }
  return 0;
}
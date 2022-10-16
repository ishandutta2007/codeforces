#include <iostream>
#include <set>

int as[100000];
int qs[100000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::set<int> set;
  for(int i=N-1;i>=0;i--){
    set.insert(as[i]);
    qs[i]=set.size();
  }
  for(int i=0;i<M;i++){
    int Q;
    std::cin>>Q;
    std::cout<<qs[Q-1]<<std::endl;
  }
  return 0;
}
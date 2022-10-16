#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int> > edges;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int X,W;
    std::cin>>X>>W;
    edges.emplace_back(X+W,X-W);
  }
  std::sort(edges.begin(),edges.end());
  int last=-1e9;
  int cnt=0;
  for(auto e:edges){
    if(e.second>=last){
      cnt++;
      last=e.first;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
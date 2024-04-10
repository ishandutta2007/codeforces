#include <iostream>

int parent[10000];
int color[10000];

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<N;i++){
    std::cin>>parent[i];
    parent[i]--;
  }
  for(int i=0;i<N;i++){
    std::cin>>color[i];
  }
  int cnt=1;
  for(int i=1;i<N;i++){
    if(color[i]!=color[parent[i]]){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
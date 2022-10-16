#include <iostream>

int parent[100000];
int deg[100000];
int leaves[100000];
int N;

int main(){
  std::cin>>N;
  for(int i=1;i<N;i++){
    std::cin>>parent[i];
    parent[i]--;
  }
  for(int i=N-1;i>0;i--){
    deg[parent[i]]++;
    if(deg[i]==0){
      leaves[parent[i]]++;
    }else if(leaves[i]<3){
      std::cout<<"No"<<std::endl;
      return 0;
    }
  }
  if(leaves[0]<3){
    std::cout<<"No"<<std::endl;
  }else{
    std::cout<<"Yes"<<std::endl;
  }
  return 0;
}
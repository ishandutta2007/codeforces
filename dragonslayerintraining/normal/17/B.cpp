#include <iostream>

int mincost[1000];

int main(){
  int N,M;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int q;
    std::cin>>q;
    mincost[i]=1e9;
  }
  std::cin>>M;
  for(int i=0;i<M;i++){
    int A,B,C;
    std::cin>>A>>B>>C;
    A--;B--;
    mincost[B]=std::min(mincost[B],C);
  }
  int cost=0;
  int root=0;
  for(int i=0;i<N;i++){
    if(mincost[i]==1e9){
      root++;
    }else{
      cost+=mincost[i];
    }
  }
  if(root!=1){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<cost<<std::endl;
  }
  return 0;
}
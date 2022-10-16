#include <iostream>

std::string grid[2000];

int main(){
  int N,M,K;
  std::cin>>N>>M>>K;
  for(int i=0;i<N;i++){
    std::cin>>grid[i];
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    int run=0;
    for(int j=0;j<M;j++){
      if(grid[i][j]=='.'){
	run++;
      }else{
	run=0;
      }
      cnt+=(run>=K);
    }
  }
  if(K==1){
    std::cout<<cnt<<std::endl;
    return 0;
  }
  for(int i=0;i<M;i++){
    int run=0;
    for(int j=0;j<N;j++){
      if(grid[j][i]=='.'){
	run++;
      }else{
	run=0;
      }
      cnt+=(run>=K);
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
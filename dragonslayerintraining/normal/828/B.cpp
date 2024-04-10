#include <iostream>

int N,M;

std::string grid[100];

int r0=100,r1=0,c0=100,c1=0;

int black=0;

int main(){
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>grid[i];
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='B'){
	r0=std::min(r0,i);
	r1=std::max(r1,i);
	c0=std::min(c0,j);
	c1=std::max(c1,j);
	black++;
      }
    }
  }
  if(black==0){
    std::cout<<1<<std::endl;
    return 0;
  }
  int side=std::max(r1-r0+1,c1-c0+1);
  if(side>std::min(N,M)){
    std::cout<<-1<<std::endl;
    return 0;
  }
  std::cout<<side*side-black<<std::endl;
  return 0;
}
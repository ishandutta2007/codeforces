#include <iostream>
#include <algorithm>
#include <vector>

int x0=1e9,y0=1e9,x1=0,y1=0;

void mark(int x,int y){
  x0=std::min(x0,x);
  y0=std::min(y0,y);
  x1=std::max(x1,x);
  y1=std::max(y1,y);
}

int main(){
  int N,M;
  std::cin>>N>>M;
  std::vector<std::string> lines;
  lines.resize(N);
  for(int i=0;i<N;i++){
    std::cin>>lines[i];
    for(int j=0;j<M;j++){
      if(lines[i][j]=='*'){
	mark(i,j);
      }
    }
  }
  for(int i=x0;i<=x1;i++){
    for(int j=y0;j<=y1;j++){
      std::cout<<lines[i][j];
    }
    std::cout<<std::endl;
  }
  return 0;
}
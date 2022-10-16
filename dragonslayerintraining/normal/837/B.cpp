#include <iostream>

std::string grid[100];

bool getrect(int x0,int x1,int y0,int y1,char& all){
  all=grid[x0][y0];
  for(int x=x0;x<x1;x++){
    for(int y=y0;y<y1;y++){
      if(grid[x][y]!=all){
	return false;
      }
    }
  }
  return true;
}

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>grid[i];
  }
  char a,b,c;
  if(N%3==0){
    int W=N/3;
    if(getrect(0,W,0,M,a)&&
       getrect(W,W*2,0,M,b)&&
       getrect(W*2,N,0,M,c)){
      if((a!=b)&&(b!=c)&&(a!=c)){
	std::cout<<"YES"<<std::endl;
	return 0;
      }
    }
  }
  if(M%3==0){
    int W=M/3;
    if(getrect(0,N,0,W,a)&&
       getrect(0,N,W,W*2,b)&&
       getrect(0,N,W*2,M,c)){
      if((a!=b)&&(b!=c)&&(a!=c)){
	std::cout<<"YES"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}
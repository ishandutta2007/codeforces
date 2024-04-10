#include <iostream>

std::string grid[10];

int main(){
  int N,M;
  std::cin>>N>>M;
  {
    std::string ign;
    std::getline(std::cin,ign);
  }
  for(int i=0;i<N;i++){
    std::getline(std::cin,grid[i]);
  }
  int total=0;
  for(int x=0;x<N;x++){
    for(int y=0;y<M;y++){
      if(grid[x][y]=='P'){
	for(int dx=-1;dx<=1;dx++){
	  for(int dy=-1;dy<=1;dy++){
	    if((dx*dy==0)&&((x+dx)>=0)&&((x+dx)<N)&&((y+dy)>=0)&&((y+dy)<M)){
	      if(grid[x+dx][y+dy]=='W'){
		grid[x+dx][y+dy]='.';
		total++;
	      }
	    }
	  }
	}
      }
    }
  }
  std::cout<<total<<std::endl;
  return 0;
}
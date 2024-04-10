#include <iostream>
#include <vector>

std::vector<std::string> grid;

int main(){
  grid.resize(8);
  for(int i=0;i<8;i++){
    std::cin>>grid[i];
  }
  int rows=0,cols=0;
  for(int i=0;i<8;i++){
    for(int j=0;grid[i][j]=='B';j++){
      if(j==7){
	rows++;
	break;
      }
    }
  }
  for(int i=0;i<8;i++){
    for(int j=0;grid[j][i]=='B';j++){
      if(j==7){
	cols++;
	break;
      }
    }
  }
  if(rows+cols==16){
    std::cout<<8<<std::endl;
  }else{
    std::cout<<rows+cols<<std::endl;
  }
  return 0;
}
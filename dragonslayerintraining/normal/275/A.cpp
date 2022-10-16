#include <iostream>

int grid[5][5];

int main(){
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      std::cin>>grid[i][j];
      grid[i][j]%=2;
    }
  }
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      std::cout<<(grid[i][j]^
		  grid[i-1][j]^
		  grid[i+1][j]^
		  grid[i][j-1]^
		  grid[i][j+1]^1);
    }
    std::cout<<std::endl;
  }
  return 0;
}
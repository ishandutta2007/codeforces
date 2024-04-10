#include <iostream>

int grid[3][3];
int row[3];
int magic=0;

int main(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      std::cin>>grid[i][j];
      row[i]+=grid[i][j];
      magic+=grid[i][j];
    }
  }
  magic/=2;
  for(int i=0;i<3;i++){
    grid[i][i]=magic-row[i];
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(j>0){
	std::cout<<" ";
      }
      std::cout<<grid[i][j];
    }
    std::cout<<std::endl;
  }
  return 0;
}
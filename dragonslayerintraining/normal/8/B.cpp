#include <iostream>

int grid[210][210];

int main(){
  std::string instr;
  std::cin>>instr;
  int x=105,y=105;
  for(int i=0;i<instr.length();i++){
    if(grid[x][y]==1){
      std::cout<<"BUG"<<std::endl;
      return 0;
    }
    grid[x][y]=1;
    switch(instr[i]){
    case 'L':x--;break;
    case 'R':x++;break;
    case 'U':y--;break;
    case 'D':y++;break;
    }
    if(grid[x-1][y]+grid[x+1][y]+grid[x][y-1]+grid[x][y+1]!=1){
      std::cout<<"BUG"<<std::endl;
      return 0;
    }
  }
  if(grid[x][y]==1){
    std::cout<<"BUG"<<std::endl;
    return 0;
  }
  std::cout<<"OK"<<std::endl;
  return 0;
}
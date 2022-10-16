#include <iostream>
#include <set>

int grid[2][2];

std::set<int> used;

int main(){
  int R[2],C[2],D[2];
  std::cin>>R[0]>>R[1]>>C[0]>>C[1]>>D[0]>>D[1];
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      grid[i][j]=(R[i]+C[j]-D[(i+j+1)%2])/2;
      if((grid[i][j]<1)||(grid[i][j]>9)){
	std::cout<<-1<<std::endl;
	return 0;
      }
      used.insert(grid[i][j]);
    }
  }
  if(used.size()!=4){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(int i=0;i<2;i++){
    if(grid[i][0]+grid[i][1]!=R[i]){
      std::cout<<-1<<std::endl;
      return 0;
    }
    if(grid[0][i]+grid[1][i]!=C[i]){
      std::cout<<-1<<std::endl;
      return 0;
    }
    if(grid[i][0]+grid[!i][1]!=D[i]){
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  
  for(int i=0;i<2;i++){
    std::cout<<grid[i][0]<<" "<<grid[i][1]<<std::endl;
  }
  return 0;
}
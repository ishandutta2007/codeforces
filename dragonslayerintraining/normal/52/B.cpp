#include <iostream>

std::string grid[1000];
int vcnt[1000];
int hcnt[1000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>grid[i];
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='*'){
	hcnt[i]++;
	vcnt[j]++;
      }
    }
  }
  long long total=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='*'){
	total+=(long long)(hcnt[i]-1)*(vcnt[j]-1);
      }
    }
  }
  std::cout<<total<<std::endl;
  return 0;
}
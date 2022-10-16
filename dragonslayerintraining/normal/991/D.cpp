#include <iostream>

std::string grid[2];

int open[101];

int main(){
  std::cin>>grid[0]>>grid[1];
  for(int i=0;i<grid[0].size();i++){
    open[i]=(grid[0][i]=='0')+(grid[1][i]=='0');
  }
  int cnt=0;
  for(int i=1;i<grid[0].size();i++){
    if(open[i-1]+open[i]>=3){
      if(open[i-1]==2){
	open[i-1]-=2;
	open[i]-=1;
	cnt++;
      }else{
	open[i-1]-=1;
	open[i]-=2;
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}
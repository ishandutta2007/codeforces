#include <iostream>
#include <vector>

std::vector<std::string> flag;

int main(){
  int N,M;
  std::cin>>N>>M;
  flag.resize(N);
  for(int i=0;i<N;i++){
    std::cin>>flag[i];
    for(int j=1;j<M;j++){
      if(flag[i][j]!=flag[i][0]){
	std::cout<<"NO"<<std::endl;
	return 0;
      }
    }
  }
  for(int i=1;i<N;i++){
    if(flag[i][0]==flag[i-1][0]){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}
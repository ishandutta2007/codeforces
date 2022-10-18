#include <iostream>

int main(){
  int N,M;
  std::cin>>N>>M;
  int x=0,y=0;
  for(int i=0;i<N;i++){
    std::string line;
    std::cin>>line;
    for(int j=0;j<M;j++){
      if(line[j]=='*'){
	x^=i;
	y^=j;
      }
    }
  }
  std::cout<<x+1<<" "<<y+1<<std::endl;
  return 0;
}
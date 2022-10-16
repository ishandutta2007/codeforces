#include <iostream>
#include <algorithm>

std::string grid[50];

int uf[100];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void unite(int a,int b){
  uf[find(a)]=find(b);
}

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>grid[i];
  }
  std::iota(uf,uf+N+M,0);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(grid[i][j]=='#'){
	unite(i,N+j);
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if((grid[i][j]=='#')^(find(i)==find(N+j))){
	std::cout<<"NO"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}
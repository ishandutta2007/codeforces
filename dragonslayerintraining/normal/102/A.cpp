#include <iostream>
#include <algorithm>

int cost[100];
bool match[100][100];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>cost[i];
  }
  for(int i=0;i<M;i++){
    int U,V;
    std::cin>>U>>V;
    U--,V--;
    match[U][V]=true;
    match[V][U]=true;
  }
  int best=1e9;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(match[i][j]){
	for(int k=0;k<N;k++){
	  if(match[i][k]&&match[j][k]){
	    best=std::min(best,cost[i]+cost[j]+cost[k]);
	  }
	}
      }
    }
  }
  std::cout<<((best<1e9)?best:-1)<<std::endl;
  return 0;
}
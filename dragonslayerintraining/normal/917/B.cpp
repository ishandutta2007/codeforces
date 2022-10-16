#include <iostream>
#include <vector>

std::vector<std::pair<int,int> > edges[100];

int dp[26][100][100];

//1 if current player wins
//2 otherwise
int get(int l,int a,int b){
  if(dp[l][a][b]){
    return dp[l][a][b];
  }
  dp[l][a][b]=2;
  for(auto e:edges[a]){
    if(e.second>=l){
      if(get(e.second,b,e.first)==2){
	dp[l][a][b]=1;
      }
    }
  }
  return dp[l][a][b];
}

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int V,U;
    std::string C;
    std::cin>>V>>U>>C;
    V--,U--;
    edges[V].emplace_back(U,C[0]-'a');
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      std::cout<<char('A'+get(0,i,j)-1);
    }
    std::cout<<std::endl;
  }
  return 0;
}
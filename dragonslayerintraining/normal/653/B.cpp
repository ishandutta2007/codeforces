#include <iostream>

int trans[6][6];

int dp[10][6];

int main(){
  int N,Q;
  std::cin>>N>>Q;
  while(Q-->0){
    std::string from,to;
    std::cin>>from>>to;
    trans[to[0]-'a'][from[0]-'a']++;
  }
  dp[1][0]=1;
  for(int i=1;i<N;i++){
    for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
	dp[i+1][b]+=dp[i][a]*trans[a][b];
      }
    }
  }
  int ans=0;
  for(int a=0;a<6;a++){
    ans+=dp[N][a];
  }
  std::cout<<ans<<std::endl;
  return 0;
}
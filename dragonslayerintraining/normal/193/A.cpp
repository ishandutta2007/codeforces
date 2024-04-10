#include <iostream>

std::string grid[52];
int N,M;

int shaded=0;

bool vis[52][52];

bool dfs(int i,int j){
  if(grid[i][j]!='#'||vis[i][j]){
    return false;
  }
  vis[i][j]=true;
  dfs(i-1,j);
  dfs(i+1,j);
  dfs(i,j-1);
  dfs(i,j+1);
  return true;
}

bool connected(){
  int cnt=0;
  for(int i=0;i<=N+1;i++){
    for(int j=0;j<=M+1;j++){
      vis[i][j]=false;
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      if(dfs(i,j)){
	cnt++;
      }
    }
  }
  return cnt<=1;
}

int main(){
  std::cin>>N>>M;
  grid[0]=std::string(M+2,'.');
  for(int i=1;i<=N;i++){
    std::cin>>grid[i];
    for(char c:grid[i]){
      shaded+=(c=='#');
    }
    grid[i]="."+grid[i]+".";
  }
  grid[N+1]=std::string(M+2,'.');
  if(shaded<=2){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      if(grid[i][j]=='#'){
	grid[i][j]='.';
	if(!connected()){
	  std::cout<<1<<std::endl;
	  return 0;
	}
	grid[i][j]='#';
      }
    }
  }
  std::cout<<2<<std::endl;
  return 0;
}
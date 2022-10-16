#include <iostream>

int N;
int p[200000];
int b[200000];
int total_flips=0;

int num_cycles=0;
int state[200000];

void dfs(int node){
  if(state[node]==2){
    return;
  }else if(state[node]==1){
    num_cycles++;
    return;
  }
  state[node]=1;
  dfs(p[node]);
  state[node]=2;
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>p[i];
    p[i]--;
  }
  for(int i=0;i<N;i++){
    std::cin>>b[i];
    total_flips+=b[i];
  }
  for(int i=0;i<N;i++){
    dfs(i);
  }
  int res=((num_cycles>1)?num_cycles:0)+(total_flips%2==0);
  std::cout<<res<<std::endl;
  return 0;
}
#include <iostream>
#include <vector>

std::vector<int> enem[100];
int visited[100];

int cnt=0;

void dfs(int node,int from,int len){
  if(visited[node]==2){
    return;
  }else if(visited[node]==1){
    if(len%2==1){
      cnt++;
    }
    return;
  }
  visited[node]=1;
  for(int next:enem[node]){
    if(next!=from){
      dfs(next,node,len+1);
    }
  }
  visited[node]=2;
}

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    enem[A].push_back(B);
    enem[B].push_back(A);
  }
  for(int i=0;i<N;i++){
    dfs(i,0,0);
  }
  std::cout<<cnt+(N+cnt)%2<<std::endl;
  return 0;
}
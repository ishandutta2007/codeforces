#include <iostream>
#include <vector>

int N;

int parent[5000];
std::vector<int> children[5000];
int size[5000];

int leaves=0;

void dfs1(int node){
  if(children[node].empty()){
    size[node]=1;
    leaves++;
  }else{
    size[node]=0;
    for(int child:children[node]){
      dfs1(child);
      size[node]+=size[child];
    }
  }
}

bool test(int A,int B,int C,int D){
  for(;parent[C]!=0;C=parent[C]);
  for(;parent[D]!=0;D=parent[D]);
  std::vector<int> extend;
  for(;parent[A]!=0;A=parent[A]){
    for(int child:children[parent[A]]){
      if(child!=A){
	extend.push_back(size[child]);
      }
    }
  }
  for(;parent[B]!=0;B=parent[B]){
    for(int child:children[parent[B]]){
      if(child!=B){
	extend.push_back(size[child]);
      }
    }
  }
  for(int child:children[0]){
    if((child!=A)&&(child!=B)&&(child!=C)&&(child!=D)){
      extend.push_back(size[child]);
    }
  }
  
  std::vector<int> dp(N);
  dp[size[C]]=1;
  for(int ext:extend){
    for(int i=N-1;i>=ext;i--){
      dp[i]|=dp[i-ext];
    }
  }
  if(dp[(leaves-2)/2]==1){
    return true;
  }else{
    return false;
  }
}

int main(){
  int A,B,C,D;
  std::cin>>N;
  std::cin>>A>>B>>C>>D;
  A--,B--,C--,D--;
  for(int i=1;i<N;i++){
    std::cin>>parent[i];
    parent[i]--;
    children[parent[i]].push_back(i);
  }
  dfs1(0);
  if((leaves%2==0)&&test(A,B,C,D)&&test(C,D,A,B)){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}
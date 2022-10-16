#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>

int N;
int as[100005];
std::vector<int> inv[100005];

int ft[100005];

void add(int i,int v){
  for(;i<=N;i+=(i&-i)){
    ft[i]+=v;
  }
}

int prefix(int i){
  int ac=0;
  for(;i>0;i-=(i&-i)){
    ac+=ft[i];
  }
  return ac;
}

int main(){
  std::cin>>N;
  for(int i=1;i<=N;i++){
    add(i,1);
  }
  for(int i=1;i<=N;i++){
    std::cin>>as[i];
    inv[as[i]].push_back(i);
  }
  int curr=0;
  int64_t cost=0;
  for(int i=1;i<=100000;i++){
    std::vector<int>::iterator next=
      std::lower_bound(inv[i].begin(),inv[i].end(),curr);
    if(next!=inv[i].end()){
      std::rotate(inv[i].begin(),next,inv[i].end());
    }
    for(int j=0;j<inv[i].size();j++){
      if(curr>inv[i][j]){
	cost+=prefix(N)-prefix(curr);
	curr=0;
      }
      cost+=prefix(inv[i][j])-prefix(curr);
      add(inv[i][j],-1);
      curr=inv[i][j];
    }
  }
  std::cout<<cost<<std::endl;
  return 0;
}
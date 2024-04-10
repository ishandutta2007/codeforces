#include <cstdio>
#include <vector>
#include <stdint.h>

struct State{
  int data[2];
  State(){
    data[0]=1;
    data[1]=0;
  }
  State extend(int c){
    State res;
    if(c==0){
      res.data[0]=data[0];
      res.data[1]=0;
    }else{
      res.data[0]=0;
      res.data[1]=data[0]+data[1];
    }
    return res;
  }
  State operator+(State s)const{
    State res;
    res.data[0]=data[0]+s.data[0];
    res.data[1]=data[1]+s.data[1];
    return res;
  }
  State operator-(State s)const{
    State res;
    res.data[0]=data[0]-s.data[0];
    res.data[1]=data[1]-s.data[1];
    return res;
  }
  State& operator+=(State s){
    return *this=*this+s;
  }
  State& operator-=(State s){
    return *this=*this-s;
  }
}dp[200005];
int64_t ans=0;

std::vector<std::pair<int,int> > edges[200005];

void dfs1(int node,int parent){
  for(auto e:edges[node]){
    int child=e.first;
    if(child==parent) continue;
    dfs1(child,node);
    dp[node]+=dp[child].extend(e.second);
  }
}

void dfs2(int node,int parent,State all){
  ans+=all.data[0]+all.data[1];
  for(auto e:edges[node]){
    int child=e.first;
    if(child==parent) continue;
    dfs2(child,node,(all-dp[child].extend(e.second)).extend(e.second)+dp[child]);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int X,Y,C;
    scanf("%d %d %d",&X,&Y,&C);
    X--,Y--;
    edges[X].emplace_back(Y,C);
    edges[Y].emplace_back(X,C);
  }
  dfs1(0,0);
  dfs2(0,0,dp[0]);
  printf("%I64d\n",ans-N);
  return 0;
}
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <stdint.h>

int cs[200005];
int N;
std::vector<int> edges[200005];
std::map<int,std::vector<std::tuple<int,int,int> > > elist;
int leaves=0;

int uf[200005];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void dfs(int node){
  int in=leaves;
  if(edges[node].empty()) leaves++;
  for(int child:edges[node]){
    edges[child].erase(std::find(edges[child].begin(),edges[child].end(),node));
    dfs(child);
  }
  int out=leaves;
  elist[cs[node]].push_back(std::make_tuple(in,out,node));
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i]);
  }
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(0);
  std::iota(uf,uf+leaves+1,0);
  std::vector<int> good;
  int64_t cost=0;
  for(auto it:elist){
    for(auto e:it.second){
      int A=std::get<0>(e);
      int B=std::get<1>(e);
      int node=std::get<2>(e);
      if(find(A)!=find(B)){
	good.push_back(node);
      }
    }
    for(auto e:it.second){
      int A=std::get<0>(e);
      int B=std::get<1>(e);
      int node=std::get<2>(e);
      if(find(A)!=find(B)){
	uf[find(A)]=find(B);
	cost+=cs[node];
      }
    }
  }
  std::sort(good.begin(),good.end());
  printf("%I64d %d\n",cost,(int)good.size());
  for(int i=0;i<good.size();i++){
    if(i) printf(" ");
    printf("%d",good[i]+1);
  }
  printf("\n");
  return 0;
}
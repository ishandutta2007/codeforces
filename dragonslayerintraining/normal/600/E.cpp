#include <iostream>
#include <vector>
#include <map>
#include <set>

long long N;
long long colors[100000];
std::vector<long long> edges[100000];

long long size[100000];
long long results[100000];

struct cds{
  long long best;
  long long bestsum;
  long long colors_cnt[100001];
  cds():best(0),bestsum(0){
  }
  void insert(long long color){
    colors_cnt[color]++;
    if(colors_cnt[color]>best){
      best=colors_cnt[color];
      bestsum=color;
    }else if(colors_cnt[color]==best){
      bestsum+=color;
    }
  }
  void erase(long long color){
    colors_cnt[color]=0;
  }
  void clear(){
    best=0;
    bestsum=0;
  }
  long long query(){
    return bestsum;
  }
}ds;

void dfs_sizes(long long node,long long parent){
  size[node]=1;
  for(long long i=0;i<edges[node].size();i++){
    long long child=edges[node][i];
    if(child!=parent){
      dfs_sizes(child,node);
      size[node]+=size[child];
    }
  }
}

void dfs_ins(long long node,long long parent){
  for(long long i=0;i<edges[node].size();i++){
    long long child=edges[node][i];
    if(child!=parent){
      dfs_ins(child,node);
    }
  }
  ds.insert(colors[node]);
}

void dfs_clr(long long node,long long parent){
  for(long long i=0;i<edges[node].size();i++){
    long long child=edges[node][i];
    if(child!=parent){
      dfs_clr(child,node);
    }
  }
  ds.erase(colors[node]);
}

void dfs_calc(long long node,long long parent){
  std::pair<long long,long long> heavy(0,-1);
  for(long long i=0;i<edges[node].size();i++){
    long long child=edges[node][i];
    if(child!=parent){
      heavy=std::max(heavy,std::make_pair(size[child],child));
    }
  }
  for(long long i=0;i<edges[node].size();i++){
    long long child=edges[node][i];
    if((child!=parent)&&(child!=heavy.second)){
      dfs_calc(child,node);
      dfs_clr(child,node);
      ds.clear();
    }
  }
  if(heavy.second>=0){
    dfs_calc(heavy.second,node);
  }
  for(long long i=0;i<edges[node].size();i++){
    long long child=edges[node][i];
    if((child!=parent)&&(child!=heavy.second)){
      dfs_ins(child,node);
    }
  }
  ds.insert(colors[node]);
  results[node]=ds.query();
}

int main(){
  std::cin>>N;
  for(long long i=0;i<N;i++){
    std::cin>>colors[i];
  }
  for(long long i=0;i<N-1;i++){
    long long X,Y;
    std::cin>>X>>Y;
    X--,Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }
  dfs_sizes(0,0);
  dfs_calc(0,0);
  for(long long i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<results[i];
  }
  std::cout<<std::endl;
  return 0;
}
#include <cstdio>
#include <vector>
#include <map>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t pow2[200001]={1};

std::vector<int64_t> edges[200000];
std::map<int64_t,int64_t> xs,ys;
int64_t card=0;
int64_t size[200000];
bool vis[200000];

bool dfs(int64_t node,int64_t parent){
  if(vis[node]){
    return false;
  }
  vis[node]=true;
  size[node]=1;
  bool cycle=false;
  for(int64_t child:edges[node]){
    if(child==parent){
      continue;
    }
    if(vis[child]){
      cycle=true;
    }else{
      cycle=dfs(child,node)||cycle;
      size[node]+=size[child];
    }
  }
  return cycle;
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<=2*N;i++){
    pow2[i]=pow2[i-1]*2%MOD;
  }
  
  std::vector<std::pair<int64_t,int64_t> > points;
  for(int64_t i=0;i<N;i++){
    int64_t X,Y;
    scanf("%I64d %I64d",&X,&Y);
    points.emplace_back(X,Y);
    xs[X];
    ys[Y];
  }
  for(auto it=xs.begin();it!=xs.end();it++){
    xs[it->first]=card++;
  }
  for(auto it=ys.begin();it!=ys.end();it++){
    ys[it->first]=card++;
  }
  for(std::pair<int64_t,int64_t>& e:points){
    edges[xs[e.first]].push_back(ys[e.second]);
    edges[ys[e.second]].push_back(xs[e.first]);
  }
  int64_t ways=1;
  for(int64_t i=0;i<card;i++){
    if(!vis[i]){
      if(dfs(i,i)){
	ways=ways*(pow2[size[i]])%MOD;
      }else{
	ways=ways*(pow2[size[i]]+MOD-1)%MOD;
      }
    }
  }
  printf("%I64d\n",ways);
  
  return 0;
}
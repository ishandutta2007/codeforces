#include <cstdio>
#include <vector>
#include <set>

std::vector<int> edges[200000];
std::vector<int> crit[200000];
std::set<std::pair<int,int> > rest;

int size[200000];
int ncrit[200000];

void dfs(int node,int parent=-1){
  size[node]=1;
  for(int child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
    size[node]+=size[child];
  }
  if(parent>=0){
    if(size[node]%2==0){
      crit[node].push_back(parent);
      ncrit[parent]++;
    }else{
      crit[parent].push_back(node);
      ncrit[node]++;
    }
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int P;
    scanf("%d",&P);
    if(P){
      P--;
      edges[P].push_back(i);
      edges[i].push_back(P);
    }
  }
  if(N%2==0){
    printf("NO\n");
    return 0;
  }
  dfs(0);
  std::vector<int> vs;
  for(int i=0;i<N;i++){
    rest.emplace(ncrit[i],i);
  }
  while(!rest.empty()){
    if(rest.begin()->first>0){
      printf("NO\n");
      return 0;
    }
    int node=rest.begin()->second;
    rest.erase(rest.begin());
    vs.push_back(node+1);
    for(int adj:crit[node]){
      rest.erase(std::make_pair(ncrit[adj],adj));
      ncrit[adj]--;
      rest.insert(std::make_pair(ncrit[adj],adj));
    }
  }
  printf("YES\n");
  for(int i=0;i<N;i++){
    printf("%d\n",vs[i]);
  }
  return 0;
}
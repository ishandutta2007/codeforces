#include <iostream>
#include <vector>

int N;

std::vector<int> roots;
std::vector<int> children[100000];

struct cquery{
  int node;
  int kth;
  int anc;
  int cousins;
  cquery(int node,int kth):node(node),kth(kth),anc(-1),cousins(0){
  }
};

std::vector<struct cquery> queries;
std::vector<int> laqueries[100000];
std::vector<int> descqueries[100000];

std::vector<int> stk;
void dfs_la(int node){
  for(int i=0;i<laqueries[node].size();i++){
    struct cquery& q=queries[laqueries[node][i]];
    if(q.kth<=stk.size()){
      q.anc=stk[stk.size()-q.kth];
      descqueries[q.anc].push_back(laqueries[node][i]);
    }
  }
  
  stk.push_back(node);
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    dfs_la(child);
  }
  stk.pop_back();
}

int size[100000];
int bydepth[100000];

void dfs_size(int node){
  size[node]=1;
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    dfs_size(child);
    size[node]+=size[child];
  }
}

void dfs_ins(int node,int depth){
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    dfs_ins(child,depth+1);
  }
  bydepth[depth]++;
}

void dfs_clr(int node,int depth){
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    dfs_clr(child,depth+1);
  }
  bydepth[depth]--;
}

void dfs_calc(int node,int depth){
  std::pair<int,int> heavy(0,-1);
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    heavy=std::max(heavy,std::make_pair(size[child],child));
  }
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    if(child!=heavy.second){
      dfs_calc(child,depth+1);
      dfs_clr(child,depth+1);
    }
  }
  if(heavy.second>=0){
    dfs_calc(heavy.second,depth+1);
  }
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    if(child!=heavy.second){
      dfs_ins(child,depth+1);
    }
  }
  bydepth[depth]++;
  
  for(int i=0;i<descqueries[node].size();i++){
    struct cquery& q=queries[descqueries[node][i]];
    q.cousins=bydepth[depth+q.kth]-1;
  }
}



int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int P;
    std::cin>>P;
    if(P>0){
      P--;
      children[P].push_back(i);
    }else{
      roots.push_back(i);
    }
  }
  int M;
  std::cin>>M;
  for(int i=0;i<M;i++){
    int V,P;
    std::cin>>V>>P;
    V--;
    laqueries[V].push_back(queries.size());
    queries.push_back(cquery(V,P));
  }
  for(int i=0;i<roots.size();i++){
    dfs_la(roots[i]);
  }
  for(int i=0;i<roots.size();i++){
    dfs_size(roots[i]);
    dfs_calc(roots[i],0);
    dfs_clr(roots[i],0);
  }
  for(int i=0;i<queries.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<queries[i].cousins;
  }
  std::cout<<std::endl;
  return 0;
}
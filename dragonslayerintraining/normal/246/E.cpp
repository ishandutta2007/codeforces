#include <iostream>
#include <vector>
#include <set>
#include <map>

int N,M;

int men[100000];

struct cquery{
  int v,k;
  int res;
}queries[100000];

std::vector<int> children[100000];
std::vector<int> roots;

std::vector<int> dfsqueries[100000];

void readinput(){
  std::cin>>N;
  std::map<std::string,int> names;
  for(int i=0;i<N;i++){
    std::string name;
    int parent;
    std::cin>>name>>parent;
    if(!names.count(name)){
      int size=names.size();
      names[name]=size;
    }
    men[i]=names[name];
    if(parent>0){
      parent--;
      children[parent].push_back(i);
    }else{
      roots.push_back(i);
    }
  }
  std::cin>>M;
  for(int i=0;i<M;i++){
    std::cin>>queries[i].v>>queries[i].k;
    queries[i].v--;
    dfsqueries[queries[i].v].push_back(i);
  }
}

int size[100000];
std::set<int> bydepth[100000];

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
  bydepth[depth].insert(men[node]);
}
void dfs_clr(int node,int depth){
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    dfs_clr(child,depth+1);
  }
  //doesn't matter because all will be erased
  bydepth[depth].erase(men[node]);
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
  bydepth[depth].insert(men[node]);
  for(int i=0;i<dfsqueries[node].size();i++){
    struct cquery& q=queries[dfsqueries[node][i]];
    if(depth+q.k>=100000){
      q.res=0;
    }else{
      q.res=bydepth[depth+q.k].size();
    }
  }
}

int main(){
  readinput();
  for(int i=0;i<roots.size();i++){
    dfs_size(roots[i]);
  }
  for(int i=0;i<roots.size();i++){
    dfs_calc(roots[i],0);
    dfs_clr(roots[i],0);
  }
  for(int i=0;i<M;i++){
    std::cout<<queries[i].res<<std::endl;
  }
  return 0;
}
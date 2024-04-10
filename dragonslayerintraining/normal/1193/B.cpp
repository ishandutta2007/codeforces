#include <cstdio>
#include <vector>
#include <map>

std::vector<int> children[100005];
std::vector<std::pair<int,int> > fruits[100005];

std::map<int,int64_t>* dfs(int node){
  std::map<int,int64_t>* res=new std::map<int,int64_t>();
  for(int child:children[node]){
    std::map<int,int64_t>* tmp=dfs(child);
    if(tmp->size()>res->size()){
      std::swap(tmp,res);
    }
    for(auto it:*tmp){
      (*res)[it.first]+=it.second;
    }
    delete tmp;
  }
  for(auto f:fruits[node]){
    int day=f.first;
    int value=f.second;
    while(value>0){
      auto it=res->upper_bound(day);
      if(it==res->end()) break;
      if(it->second<=value){
	value-=it->second;
	res->erase(it);
      }else{
	(*res)[it->first]-=value;
	value=0;
      }
    }
    (*res)[day]+=f.second;
  }
  return res;
}


int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=1;i<N;i++){
    int P;
    scanf("%d",&P);
    children[P-1].push_back(i);
  }
  for(int i=0;i<M;i++){
    int V,D,W;
    scanf("%d %d %d",&V,&D,&W);
    V--;
    fruits[V].push_back({D,W});
  }
  std::map<int,int64_t>* res=dfs(0);
  int64_t ans=0;
  for(auto it:*res){
    ans+=it.second;
  }
  printf("%I64d\n",ans);
}
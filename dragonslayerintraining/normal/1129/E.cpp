#include <cstdio>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

//check if v is in minimal connected induced subgraph containing T
template<class Iterator>
bool query(Iterator begin,Iterator end,int v){
  for(Iterator it=begin;it!=end;it++){
    if(*it==v){
      return true;
    }
  }
  if(end-begin==1){
    return false;
  }
  printf("1\n");
  printf("%d\n",*(begin++));;
  printf("%d\n",int(end-begin));
  for(;begin!=end;begin++){
    printf("%d ",*begin);
  }
  printf("\n");
  printf("%d\n",v);
  fflush(stdout);
  int ans;
  scanf("%d",&ans);
  return ans>0;
}

bool used[505];
int parent[505];

int depth[505];

int getdepth(int x){
  if(x==1) return 0;
  if(depth[x]) return depth[x];
  return depth[x]=getdepth(parent[x])+1;
}

template<class Iterator>
void reparent(Iterator begin,Iterator end,int from,int to){
  if(begin==end) return;
  std::vector<int> tmp(begin,end);
  tmp.push_back(from);
  if(!query(tmp.begin(),tmp.end(),to)) return;
  if(end-begin==1){
    parent[*begin]=to;
    return;
  }
  Iterator mid=begin+(end-begin)/2;
  reparent(begin,mid,from,to);
  reparent(mid,end,from,to);
}

int main(){
  int N;
  scanf("%d",&N);
  //root at 1
  used[1]=true;
  parent[1]=0;
  //take all leaves
  for(int i=2;i<=N;i++){
    std::vector<int> T;
    for(int j=1;j<=N;j++){
      if(i!=j){
	T.push_back(j);
      }
    }
    if(!query(T.begin(),T.end(),i)){
      used[i]=true;
      parent[i]=1;
    }
  }
  std::vector<int> is;
  for(int i=1;i<=N;i++){
    if(!used[i]){
      is.push_back(i);
    }
  }
  std::shuffle(is.begin(),is.end(),rng);
  for(int i:is){
    //insert i into tree
    std::vector<int> tree;
    for(int j=1;j<=N;j++){
      if(used[j]){
	tree.push_back(j);
      }
    }
    std::fill(depth,depth+N+1,0);
    std::sort(tree.begin(),tree.end(),[](int i,int j){return getdepth(i)<getdepth(j);});
    int low=0,high=tree.size();
    while(high-low>1){
      int mid=(low+high)/2;
      if(query(tree.begin(),tree.begin()+mid,i)){
	high=mid;
      }else{
	low=mid;
      }
    }
    //tree[low] is critical
    int x=parent[tree[low]];
    parent[tree[low]]=i;
    std::vector<int> siblings;
    for(int j=1;j<=N;j++){
      if(parent[j]==x){
	siblings.push_back(j);
      }
    }
    reparent(siblings.begin(),siblings.end(),x,i);
    used[i]=true;
    parent[i]=x;
  }
  printf("ANSWER\n");
  for(int i=2;i<=N;i++){
    printf("%d %d\n",i,parent[i]);
  }
  return 0;
}
#include <cstdio>
#include <vector>
#include <stdint.h>

class LiChaoTree{
  std::vector<int64_t> left,right;
  std::vector<int64_t> as,bs;
  int64_t new_node(int64_t l,int64_t r,int64_t a,int64_t b){
    int64_t id=left.size();
    left.push_back(l);
    right.push_back(r);
    as.push_back(a);
    bs.push_back(b);
    return id;
  }
  int64_t query(int64_t node,int64_t L,int64_t R,int64_t x){
    if(node==-1){
      return 1e18+7;
    }
    int64_t M=(L+R)/2;
    int64_t here=as[node]*x+bs[node];
    if(x<M){
      return std::min(here,query(left[node],L,M,x));
    }else{
      return std::min(here,query(right[node],M,R,x));
    }
  }
  int64_t update(int64_t node,int64_t L,int64_t R,int64_t a,int64_t b){
    if(node==-1){
      return new_node(-1,-1,a,b);
    }
    int64_t oa=as[node],ob=bs[node];
    int64_t M=(L+R)/2;
    if(a*M+b<oa*M+ob){
      std::swap(a,oa);
      std::swap(b,ob);
    }
    if(R-L==1){
      return new_node(-1,-1,oa,ob);
    }
    if(a>oa){
      return new_node(update(left[node],L,M,a,b),right[node],oa,ob);
    }else{
      return new_node(left[node],update(right[node],M,R,a,b),oa,ob);
    }
  }
public:
  int64_t query(int64_t root,int64_t x){
    return query(root,-1e6,1e6,x);
  }
  int64_t update(int64_t root,int64_t a,int64_t b){
    return update(root,-1e6,1e6,a,b);
  }
  void clear(){
    left.clear(),right.clear(),as.clear(),bs.clear();
  }
}lcts;

int64_t as[100000];
int64_t bs[100000];
int64_t cs[100000];
int64_t res[100000];

std::vector<int64_t> edges[100000];

int64_t size[100000];

void dfs_size(int64_t node,int64_t parent){
  size[node]=1;
  for(int64_t child:edges[node]){
    if(child!=parent){
      dfs_size(child,node);
      size[node]+=size[child];
    }
  }
}

int64_t dfs_light(int64_t node,int64_t parent,int64_t lct){
  for(int64_t child:edges[node]){
    if(child!=parent){
      lct=dfs_light(child,node,lct);
    }
  }
  return lcts.update(lct,bs[node],cs[node]);
}

int64_t dfs_heavy(int64_t node,int64_t parent){
  int64_t lct=-1;
  int64_t heavy=-1;
  for(int64_t child:edges[node]){
    if(child!=parent){
      if(heavy<0||size[child]>size[heavy]){
	heavy=child;
      }
    }
  }
  if(heavy>=0){
    for(int64_t child:edges[node]){
      if(child!=parent&&child!=heavy){
	dfs_heavy(child,node);
	lcts.clear();
      }
    }
    lct=dfs_heavy(heavy,node);
    for(int64_t child:edges[node]){
      if(child!=parent&&child!=heavy){
	lct=dfs_light(child,node,lct);
      }
    }
    cs[node]=lcts.query(lct,as[node]);
  }
  return lcts.update(lct,bs[node],cs[node]);
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&bs[i]);
  }
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs_size(0,0);
  dfs_heavy(0,0);
  for(int64_t i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%I64d",cs[i]);
  }
  printf("\n");
  return 0;
}
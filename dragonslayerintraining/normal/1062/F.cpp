#include <cstdio>
#include <algorithm>
#include <vector>

std::vector<std::vector<int> > fwd,rev;
std::vector<int> order;
int level[300005];
int parent[300005];
int children[300005];
int bad[300005];
int N;

int badness=0;

void dfs(int x){
  level[x]=1;
  for(int y:fwd[x]){
    if(!level[y]){
      dfs(y);
    }
  }
  order.push_back(x);
}

void solve(const std::vector<std::vector<int> >& edges){
  std::fill(children,children+N,0);
  std::fill(level,level+N,0);
  badness=0;
  for(int x:order){
    for(int y:edges[x]){
      if(level[y]==1){
	children[parent[y]]--;
	badness--;
	level[y]=2;
      }else if(level[y]==0){
	badness-=1+children[y];
	for(int z:edges[y]){
	  level[z]=2;
	}
	level[y]=1;
	parent[y]=x;
	children[x]++;
      }
    }
    bad[x]+=badness;
    badness+=1+children[x];
  }
}

int main(){
  int M;
  scanf("%d %d",&N,&M);
  fwd.resize(N);
  rev.resize(N);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    fwd[U].push_back(V);
    rev[V].push_back(U);
  }
  for(int i=0;i<N;i++){
    if(!level[i]){
      dfs(i);
    }
  }
  /*
  for(int i:order){
    printf("%d\n",i+1);
  }
  */
  solve(fwd);
  std::reverse(order.begin(),order.end());
  solve(rev);
  int cnt=0;
  for(int i=0;i<N;i++){
    if(bad[i]<=1) cnt++;
    //printf("bad[%d]=%d\n",i,bad[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
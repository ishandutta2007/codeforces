#include <cstdio>
#include <vector>
#include <cassert>

int us[100000];

std::vector<int> edges[100000];

int pre[100000];
int pre_max=1;
int low[100000];

std::vector<int> stk;

int cmpt[100000];
int size[100000];
int out[100000];
int cmpt_max=0;

void dfs_scc(int node){
  if(low[node]) return;
  low[node]=pre[node]=pre_max++;
  stk.push_back(node);
  for(int child:edges[node]){
    dfs_scc(child);
    low[node]=std::min(low[node],low[child]);
  }
  if(low[node]==pre[node]){
    while(stk.back()!=node){
      low[stk.back()]=1e9;
      cmpt[stk.back()]=cmpt_max;
      stk.pop_back();
      size[cmpt_max]++;
    }
    low[stk.back()]=1e9;
    cmpt[stk.back()]=cmpt_max;
    stk.pop_back();
    size[cmpt_max]++;

    cmpt_max++;
  }
}

int main(){
  int N,M,H;
  scanf("%d %d %d",&N,&M,&H);
  for(int i=0;i<N;i++){
    scanf("%d",&us[i]);
  }
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    if((us[A]+1)%H==us[B]) edges[A].push_back(B);
    if((us[B]+1)%H==us[A]) edges[B].push_back(A);
  }
  for(int i=0;i<N;i++){
    dfs_scc(i);
  }
  for(int i=0;i<N;i++){
    for(int j:edges[i]){
      if(cmpt[i]!=cmpt[j]){
	out[cmpt[i]]++;
      }
    }
  }
  /*
  for(int i=0;i<N;i++){
    printf("cmpt[%d]=%d\n",i,cmpt[i]);
  }
  */
  std::pair<int,int> best(1e9,-1);
  for(int i=0;i<cmpt_max;i++){
    if(out[i]==0){
      best=std::min(best,std::make_pair(size[i],i));
    }
  }
  std::vector<int> elems;
  for(int i=0;i<N;i++){
    if(cmpt[i]==best.second){
      elems.push_back(i+1);
    }
  }
  assert(elems.size()==best.first);
  printf("%d\n",best.first);
  for(int i=0;i<elems.size();i++){
    if(i>0) printf(" ");
    printf("%d",elems[i]);
  }
  printf("\n");
  return 0;
}
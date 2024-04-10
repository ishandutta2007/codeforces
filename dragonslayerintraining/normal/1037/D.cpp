#include <cstdio>
#include <vector>
#include <algorithm>

int as[200005];
int bs[200005];
std::vector<int> edges[200005];
int child_cnt[200005];

int ps[200005];

void dfs(int node){
  for(int child:edges[node]){
    if(child==ps[node]) continue;
    ps[child]=node;
    dfs(child);
    child_cnt[node]++;
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  dfs(0);
  for(int i=0;i<N;i++){
    bs[i]=as[i];
  }
  std::sort(bs,bs+N);
  for(int i=0;i<N;i++){
    if(bs[i]!=i){
      printf("NO\n");
      return 0;
    }
  }
  if(as[0]!=0){
    printf("NO\n");
    return 0;
  }
  int j=1;
  for(int i=0;i<N;i++){
    for(int k=0;k<child_cnt[as[i]];k++){
      if(as[i]!=ps[as[j++]]){
	printf("NO\n");
	return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}
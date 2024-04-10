#include <cstdio>
#include <set>

std::set<int> unvis;

std::set<int> forbid[300005];
int cnt[300005];

void dfs(int u){
  unvis.erase(u);
  int low=0;
  while(true){
    auto it=unvis.lower_bound(low);
    if(it==unvis.end()) break;
    low=*it+1;
    if(!forbid[u].count(*it)){
      dfs(*it);
      cnt[u]++;
    }
  }
}

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    forbid[A].insert(B);
    forbid[B].insert(A);
  }
  for(int i=1;i<N;i++){
    unvis.insert(i);
  }
  dfs(0);
  if(K>=cnt[0]&&K<=N-1-forbid[0].size()&&unvis.empty()){
    printf("possible\n");
  }else{
    printf("impossible\n");
  }
  return 0;
}
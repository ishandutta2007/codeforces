#include <cstdio>
#include <set>
#include <vector>
#include <map>

bool used[300005];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::fill(used,used+N*3,false);
  std::vector<int> matching;
  std::vector<int> indset;
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    if(!used[U]&&!used[V]){
      matching.push_back(i);
      used[U]=true;
      used[V]=true;
    }
  }
  for(int i=0;i<N*3;i++){
    if(!used[i]){
      indset.push_back(i);
    }
  }
  if(matching.size()>=N){
    printf("Matching\n");
    for(int i=0;i<N;i++){
      printf("%d ",matching[i]+1);
    }
    printf("\n");
  }else{
    printf("IndSet\n");
    for(int i=0;i<N;i++){
      printf("%d ",indset[i]+1);
    }
    printf("\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}
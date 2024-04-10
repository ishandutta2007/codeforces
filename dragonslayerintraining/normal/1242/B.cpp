#include <cstdio>
#include <set>

std::set<int> adj[100005];
std::set<int> unvis;

void dfs(int x){
  unvis.erase(x);
  int z;
  for(auto y=unvis.begin();y!=unvis.end();y=unvis.upper_bound(z)){
    z=*y;
    if(!adj[x].count(z)){
      dfs(z);
    }
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    adj[A].insert(B);
    adj[B].insert(A);
  }
  for(int i=1;i<=N;i++){
    unvis.insert(i);
  }
  int ans=-1;
  for(int i=1;i<=N;i++){
    if(unvis.count(i)){
      dfs(i);
      ans++;
    }
  }
  printf("%d\n",ans);
}
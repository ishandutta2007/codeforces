#include <cstdio>
#include <algorithm>
#include <vector>

std::vector<int> elist;

std::vector<std::pair<int,int> > adj[100005];

int post[100005];
int post_max;
int N;

bool dfs(int node,int limit){
  post[node]=-1;
  for(auto e:adj[node]){
    if(e.second<=limit) continue;
    int child=e.first;
    if(post[child]==-1||(post[child]==0&&dfs(child,limit))){
      return true;
    }
  }
  post[node]=++post_max;
  return false;
}

bool check(int limit){
  std::fill(post,post+N,0);
  post_max=0;
  for(int i=0;i<N;i++){
    if(post[i]==0&&dfs(i,limit)) return false;
  }
  return true;
}

int main(){
  int M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V,C;
    scanf("%d %d %d",&U,&V,&C);
    U--,V--;
    adj[U].push_back({V,C});
    elist.push_back(U);
    elist.push_back(V);
  }
  int low=-1,high=1e9;
  while(high-low>1){
    int mid=(low+high)/2;
    if(check(mid)){
      high=mid;
    }else{
      low=mid;
    }
    /*
    printf("check(%d): %d\n",mid,check(mid));
    for(int i=0;i<N;i++){
      printf("post[%d]=%d\n",i,post[i]);
    }
    */
  }
  check(high);
  std::vector<int> rev;
  for(int i=0;i<elist.size();i+=2){
    int U=elist[i],V=elist[i+1];
    if(post[U]<post[V]){
      rev.push_back(i>>1);
    }
  }
  printf("%d %d\n",high,(int)rev.size());
  for(int i=0;i<rev.size();i++){
    if(i) printf(" ");
    printf("%d",rev[i]+1);
  }
  printf("\n");
  return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>

using ll=long long;

int ts[200005];
int hs[200005];

std::vector<int> edges[200005];

ll dp[200005];

ll total_cost=0;

void dfs(int x,int p){
  std::vector<ll> v;
  int up_cnt=0,down_cnt=0;
  for(int y:edges[x]){
    if(y==p) continue;
    dfs(y,x);
    if(hs[y]>hs[x]){
      down_cnt++;
    }else if(hs[y]<hs[x]){
      total_cost+=dp[y];
      up_cnt++;
    }else{
      v.push_back(dp[y]);
    }
  }
  std::sort(v.begin(),v.end());
  if(x==0){
    ll cost=0;
    ll prefix_cost=0;
    for(int i=0;;i++){
      //extra i up, v.size()-i down
      cost=std::min<ll>(cost,prefix_cost-ts[x]*std::min<ll>(up_cnt+i,down_cnt+v.size()-i));
      if(i==v.size()) break;
      prefix_cost+=v[i];
    }
    total_cost+=cost;
  }else{
    ll down_cost=0,up_cost=0;
    ll prefix_cost=0;
    for(int i=0;;i++){
      //extra i up, v.size()-i+1 down
      up_cost=std::min<ll>(up_cost,prefix_cost-ts[x]*std::min<ll>(up_cnt+i,down_cnt+v.size()-i+1));
      //extra i+1 up, v.size()-i+1 down
      down_cost=std::min<ll>(down_cost,prefix_cost-ts[x]*std::min<ll>(up_cnt+i+1,down_cnt+v.size()-i));
      if(i==v.size()) break;
      prefix_cost+=v[i];
    }
    total_cost+=down_cost;
    dp[x]=up_cost-down_cost;
  }
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ts[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&hs[i]);
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
    total_cost+=ts[U]+ts[V];
  }
  dfs(0,-1);
  printf("%lld\n",total_cost);
}
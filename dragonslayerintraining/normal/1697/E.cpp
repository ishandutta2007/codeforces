#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>

const int INF=1e9+7;
const int MOD=998244353;

int xs[100];
int ys[100];
int near[100];
std::set<int> nearset[100];

bool vis[100];
bool ok[100];

int dist(int i,int j){
  return std::labs(xs[i]-xs[j])+std::labs(ys[i]-ys[j]);
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&xs[i],&ys[i]);
  }
  for(int i=0;i<N;i++){
    near[i]=INF;
    for(int j=0;j<N;j++){
      if(i==j) continue;
      near[i]=std::min(near[i],dist(i,j));
    }
    nearset[i].insert(i);
    for(int j=0;j<N;j++){
      if(i==j) continue;
      if(dist(i,j)==near[i]){
	nearset[i].insert(j);
      }
    }
  }
  std::fill(ok,ok+N,true);
  std::vector<int> groups;
  for(int i=0;i<N;i++){
    if(vis[i]) continue;
    std::set<int> grp=nearset[i];
    for(int j:grp){
      if(nearset[j]!=nearset[i]) ok[i]=false;
    }
    if(ok[i]){
      for(int j:nearset[i]){
	vis[j]=true;
      }
      assert(nearset[i].size()<=4);
      groups.push_back(nearset[i].size());
    }else{
      vis[i]=true;
      groups.push_back(1);
    }
  }
  std::vector<int> ways(N+1);//ways[i] = #ways so that i colors remain
  ways[N]=1;
  for(int x:groups){
    //printf("Group of %d\n",x);
    for(int i=0;i<=N;i++){
      ways[i]=0;
      if(i+1<=N){
	ways[i]=ways[i+1]*(i+1LL)%MOD;
      }
      if(x>1&&i+x<=N){
	int combo=1;
	for(int k=0;k<x;k++){
	  combo=1LL*combo*(i+x-k)%MOD;
	}
	ways[i]=(ways[i]+1LL*ways[i+x]*combo)%MOD;
      }
    }
  }
  int ans=0;
  for(int i=0;i<=N;i++){
    //printf("Ways with %d colors remaining: %d\n",i,ways[i]);
    ans=(ans+ways[i])%MOD;
  }
  printf("%d\n",ans);
}
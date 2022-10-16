#include <cstdio>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>
#include <algorithm>

std::mt19937 rng(std::chrono::steady_clock().now().time_since_epoch().count());

int fib[50]={0,1};

std::set<int> adj[200005];

int size[200005];
int par[200005];

std::vector<int> nodes;
void dfs_size(int x,int z){
  nodes.push_back(x);
  size[x]=1;
  for(int y:adj[x]){
    if(y==z) continue;
    par[y]=x;
    dfs_size(y,x);
    size[x]+=size[y];
  }
}

bool check(int x,int k){
  nodes.clear();
  dfs_size(x,x);
  assert(size[x]==fib[k]);
  if(fib[k]==1) return true;
  std::vector<std::pair<int,int> > splits;
  for(int y:nodes){
    if(x==y) continue;
    if(size[y]==fib[k-2]){
      splits.push_back({y,par[y]});
    }else if(size[y]==fib[k-1]){
      splits.push_back({par[y],y});
    }
  }
  std::shuffle(splits.begin(),splits.end(),rng);
  for(auto e:splits){
    int y=e.first,z=e.second;
    adj[y].erase(z);
    adj[z].erase(y);
    if(check(y,k-2)){
      if(check(z,k-1)){
	adj[y].insert(z);
	adj[z].insert(y);
	return true;
      }else{
	adj[y].insert(z);
	adj[z].insert(y);
	return false;
      }
    }
    adj[y].insert(z);
    adj[z].insert(y);
  }
  return false;
}

int main(){
  int N;
  scanf("%d",&N);
  int k;
  for(k=2;;k++){
    fib[k]=fib[k-1]+fib[k-2];
    if(fib[k]==N) break;
    if(fib[k]>N){
      printf("NO\n");
      return 0;
    }
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U].insert(V);
    adj[V].insert(U);
  }
  if(check(0,k)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
}
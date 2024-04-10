#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 150005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0;
  for(c = getchar();c < '0' || c > '9';c = getchar());
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res;
}
vector <int> adj[maxn];
int n,par[maxn],he[maxn],ta[maxn],deg[maxn];
void ini(int x){
  for(int i = 1;i <= x;i++){
    he[i] = ta[i] = par[i] = i;
  }
}
int fin(int x){
  if(par[x] == x) return x;
  return par[x] = fin(par[x]);
}
void uni(int x,int y){
  x = fin(x),y = fin(y);
  if(x == y) return;
  par[x] = y;
  adj[he[x]].push_back(ta[y]);
  adj[ta[y]].push_back(he[x]);
  he[y] = he[x];
  he[x] = ta[x] = 0;
}
bool vis[maxn];
void dfs(int u){
  vis[u] = true;
  printf("%d ",u);
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(!vis[v]) dfs(v);
  }
}
int main(){
  n = getint();
  ini(n);
  for(int i = 1;i < n;i++){
    int u = getint(), v = getint();
    uni(u,v);
  }
  dfs(he[fin(1)]);
  printf("\n");
  return 0;
}
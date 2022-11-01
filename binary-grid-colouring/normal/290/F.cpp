#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;

int a[1234][1234];
std::vector<int> adj[32];
int deg[34];
int vis[34];
bool cmp(int x,int y)
{
  if(deg[x] != deg[y]) {
    return deg[x] < deg[y];
  }
  return x < y;
}

void dfs(int u)
{
  vis[u] = 1;
  for(int i=0;i<(int)adj[u].size();i++) {
    int nxt = adj[u][i];
    if(nxt==u) continue;
    if(vis[nxt])continue;
    dfs(nxt);
    break;
  }
}
int main(int argc, char const *argv[]) {
  int n,m;
  std::cin >> n >> m;
  for(int i=1;i<=m;i++) {
    int x,y;
    std::cin >> x >> y;
    if(x!=y) {
      a[x][y] = a[y][x]  = true;
    }
  }
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      if(a[i][j]==true) {
        deg[i]++;
        adj[i].push_back(j);
      }
    }
  }
  for(int i=1;i<=n;i++) {
    sort(adj[i].begin(),adj[i].end(),cmp);
  }
  int f = 0;
  for(int i=1;i<=n;i++) {
    memset(vis,0,sizeof(vis));
    dfs(i);
    if(count(vis+1,vis+n+1,true)==n) {
      f = 1;break;
    }
  }
  if(f) std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';
  return 0;
}
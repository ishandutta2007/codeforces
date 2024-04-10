#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > G;

bool vis[100005] = {0};
int l = 1;

bool tree(int from, int v) {
  bool ok = 1;
  vis[v] = 1;
  for(int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i];
    if(u == from) continue;
    if(vis[u]) ok = false;
    else ok &= tree(v,u);
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  G = vector<vector<int> >(n+1,vector<int>());
  for(int i = 0; i < m; ++i) {
    int u,v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(vis[i]) continue;
    ans += tree(-1,i);
  }
  cout << ans << "\n";
  return 0;
}
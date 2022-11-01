#include <bits/stdc++.h>

using namespace std;

int n,m;
int E[100010];
std::vector<int> edge[100010];
bool vis[100010];
int mx[100010];

int dfs(int u)
{
  if(vis[u]){
    return mx[u];
  }
  vis[u] = true;
  mx[u] = E[u];
  for(int i=0;i<edge[u].size();i++) {
    mx[u] = max(mx[u], (E[u]==1 && E[edge[u][i]]==0) + dfs(edge[u][i]));
  }
  return mx[u];
}
int main(int argc, char const *argv[]) {

  std::cin >> n >> m;
  for(int i=0;i<n;i++) {
    cin>>E[i];
  }
  int u,v;
  for(int i=0;i<m;i++) {
    std::cin >> u >> v;
    edge[u].push_back(v);
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    ans = max(ans,dfs(i));
  }
  std::cout << ans << '\n';
  return 0;
}
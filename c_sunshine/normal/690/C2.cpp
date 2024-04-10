#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100000 + 10;

int n;
std::vector<int> adj[N];

int dep[N];

void dfs(int a, int fa = -1) {
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != fa) dep[b] = dep[a] + 1, dfs(b, a);
  }
}

int main() {
  scanf("%d%*d", &n);
  for (int i = n - 1; i--;) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dep[1] = 0;
  dfs(1);
  int t = std::max_element(dep + 1, dep + n + 1) - dep;
  dep[t] = 0;
  dfs(t);
  printf("%d\n", *std::max_element(dep + 1, dep + n + 1));
  return 0;
}
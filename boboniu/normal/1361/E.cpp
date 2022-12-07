#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 222222
mt19937 mrand(random_device{}());
int randint(int x) { return mrand() % x; }

int MAGIC = 50;
vector<int> adj[maxN], radj[maxN];
int n, m, p[maxN], dep[maxN], edgeUp[maxN], par[maxN], sumUp[maxN];
bool vis[maxN], instack[maxN], valid;
bool bad[maxN], arrive[maxN];

void dfs(int u) {
  vis[u] = true;
  instack[u] = true;
  for (auto v : adj[u]) {
    if (!vis[v]) {
      dep[v] = dep[u] + 1;
      par[v] = u;
      dfs(v);
      edgeUp[u] += edgeUp[v];
      sumUp[u] += sumUp[v];
    } else {
      if (!instack[v])
        valid = false;
      else {
        edgeUp[u] += 1;
        edgeUp[v] -= 1;
        sumUp[u] += v;
        sumUp[v] -= v;
      }
    }
  }
  instack[u] = false;
}
bool check(int root) {
  valid = true;
  for (int i = 1; i <= n; i++) {
    instack[i] = 0, vis[i] = 0, dep[i] = 0;
    edgeUp[i] = 0;
    sumUp[i] = 0;
  }
  par[root] = 0;
  dfs(root);
  return valid;
}
void solve(int u) {
  if (edgeUp[u] >= 2) {
    bad[u] = true;
  } else if (edgeUp[u] == 1) {
    int v = sumUp[u];
    arrive[u] = arrive[v];
    if (arrive[u]) {
      bad[u] |= bad[v];
    }
  }
  for (auto v : adj[u])
    if (dep[v] > dep[u])
      solve(v);
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    radj[i].clear();
    p[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    radj[y].push_back(x);
  }
  random_shuffle(p + 1, p + n + 1, randint);
  int root = -1;
  for (int i = 1; i <= min(MAGIC, n); i++) {
    if (check(p[i])) {
      root = p[i];
      break;
    }
  }
  if (root == -1) {
    printf("-1\n");
    return;
  }
  for (int i = 1; i <= n; i++) {
    arrive[i] = false;
    bad[i] = false;
  }
  arrive[root] = true;
  solve(root);
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (arrive[i] && !bad[i]) {
      ans.push_back(i);
    }
  if (ans.size() * 5 < n) {
    printf("-1\n");
  } else {
    for (auto x : ans)
      printf("%d ", x);
    printf("\n");
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    solve();
  }
}
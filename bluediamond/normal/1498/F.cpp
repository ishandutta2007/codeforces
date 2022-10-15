#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
const int K = 40 + 7;
int n, k, down[N][K], up[N][K], v[N], kidss[N][K];
vector<int> g[N];

void build(int a, int p = -1) {
  down[a][0] = v[a];
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b == p) continue;
    kids.push_back(b);
    build(b, a);
    for (int j = 0; j < k; j++) {
      kidss[a][j] ^= down[b][j];
      down[a][(j + 1) % k] ^= down[b][j];
    }
  }
  g[a] = kids;
}

void dfs(int a, int p = -1) {
  up[a][0] = v[a];
  if (p != -1) {
    for (int j = 0; j < k; j++) {
      up[a][(j + 1) % k] ^= up[p][j];
    }
    for (int j = 0; j < k; j++) {
      up[a][(j + 2) % k] ^= kidss[p][j];
    }
   /** for (auto &oth : g[p]) {
      for (int j = 0; j < k; j++) {
        up[a][(j + 2) % k] ^= down[oth][j];
      }
    }**/
    for (int j = 0; j < k; j++) {
      up[a][(j + 2) % k] ^= down[a][j];
    }
  }
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
  }
}

signed realMain() {
  cin >> n >> k;
  k *= 2;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  build(1);
  dfs(1);

  for (int i = 1; i <= n; i++) {
    int ret = 0;
    for (int j = k / 2; j < k; j++) {
      ret ^= up[i][j];
      ret ^= down[i][j];
    }
    cout << (ret > 0) << " ";
  }
  cout << "\n";
  return 0;
}
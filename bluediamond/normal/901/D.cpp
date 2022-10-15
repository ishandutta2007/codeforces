#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
const int N = (int) 1e5 + 7;
int n, m, init[N], cur[N], xr[N], sol[N], pi[N];
vector<int> g[N];
bool vis[N];
int dep[N];
int col[N];
int s, t, ei;

void place() {
  for (int i = 1; i <= m; i++) sol[i] = 0;
  for (int i = 1; i <= n; i++) cur[i] = init[i], vis[i] = 0;
}

void dfs(int a) {
  vis[a] = 1;
  for (auto &ind : g[a]) {
    int b = (xr[ind] ^ a);
    if (!vis[b]) {
      dep[b] = 1 + dep[a];
      col[b] = (1 ^ col[a]);
      dfs(b);
      sol[ind] = cur[b];
      cur[a] -= sol[ind];
      pi[b] = ind;
    } else {
      if (dep[b] < dep[a] && col[b] == col[a]) {
        s = a;
        t = b;
        ei = ind;
      }
    }
  }
}

void dfssimple(int a) {
  vis[a] = 1;
  for (auto &ind : g[a]) {
    int b = (xr[ind] ^ a);
    if (ind != ei && !vis[b]) {
      dfssimple(b);
      sol[ind] = cur[b];
      cur[a] -= sol[ind];
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> init[i];
  place();
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    xr[i] = (x ^ y);
    g[x].push_back(i);
    g[y].push_back(i);
  }
  dfs(1);
  if (cur[1] == 0) {
    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
      cout << sol[i] << "\n";
    }
    return 0;
  }

  if (!ei) {
    cout << "NO\n";
    return 0;
  }


  place();
  dfssimple(s);
  assert(cur[s] % 2 == 0);
  ll kek = cur[s] / 2;
  int sgn = +1;
  while (s != t) {
    sol[pi[s]] += sgn * kek;
    sgn *= -1;
    s ^= xr[pi[s]];
  }
  sol[ei] += sgn * kek;
  cout << "YES\n";
  for (int i = 1; i <= m; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}
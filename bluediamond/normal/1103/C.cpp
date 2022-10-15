#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

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

const int N = (int) 3e5 + 7;
int n, m, k, dep[N], par[N];
vector<int> g[N];
vector<int> good[N];
vector<int> bk[N];

void dfs(int a) {
  for (auto &b : g[a]) {
    if (dep[b] == 0) {
      par[b] = a;
      good[a].push_back(b);
      dep[b] = 1 + dep[a];
      dfs(b);
    } else {
      if (dep[b] < dep[a] - 1) {
        bk[a].push_back(b);
      }
    }
  }
}

mt19937 rng((long long) (new char));

signed realMain() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = rng() % n + 1;
  dep[root] = 1;
  dfs(root);
  int leafs = 0;
  for (int i = 1; i <= n; i++) {
    leafs += good[i].empty();
  }
  /**
  u1 + ... + uk >= n
  max(u1, ..., uk) * k >= n
  max(u1, ..., uk) >= n / k
  **/
  int mx_dep = 0;
  for (int i = 1; i <= n; i++) {
    mx_dep = max(mx_dep, dep[i]);
  }
  bool goodd = (mx_dep * k >= n);
  if (!goodd) {
    cout << "CYCLES\n";
    int need = k;
    for (int id = 1; id <= n; id++) {
      int i = id;
      if (need == 0) break;
      if (!good[i].empty()) continue;
      if ((int) bk[i].size() < 2) {
        cout << "sad_at_node=" << i << ":" << (int) bk[i].size() << "\n";
        return 0;
      }
      need--;
      int x = bk[i][0], y = bk[i][1];
      if ((dep[i] - dep[x] + 1) % 3 != 0) {
        cout << dep[i] - dep[x] + 1 << "\n";
        while (i != par[x]) {
          cout << i << " ";
          i = par[i];
        }
        cout << "\n";
        continue;
      }
      if ((dep[i] - dep[y] + 1) % 3 != 0) {
        cout << dep[i] - dep[y] + 1 << "\n";
        while (i != par[y]) {
          cout << i << " ";
          i = par[i];
        }
        cout << "\n";
        continue;
      }
      if (dep[x] < dep[y]) swap(x, y);
      if ((dep[x] - dep[y] + 2) % 3 != 0) {
        cout << dep[x] - dep[y] + 2 << "\n";
        vector<int> uga;
        while (x != par[y]) {
          uga.push_back(x);
          x = par[x];
        }
        reverse(uga.begin(), uga.end());
        cout << i << " ";
        for (auto &j : uga) {
          cout << j << " ";
        }
        cout << "\n";
        continue;
      }
      cout << i << "sad:(\n";
      return 0;
     /// buga(0);
    }
  } else {
    /// max_dep >= n / leafs > n / k
    cout << "PATH\n";

    cout << mx_dep << "\n";
    int i = 1;
    while (dep[i] != mx_dep) i++;
    while (i) {
      cout << i << " ";
      i = par[i];
    }
    cout << "\n";
  }
  return 0;
}
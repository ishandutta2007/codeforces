#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100 + 7;
int n;
map<pair<int, int>, int> id;
vector<int> g[N];

ld rep(ld x) {
  if (x >= 2) {
    x -= 2;
  }
  return x;
}

void dfs(int a, int p = 0, ld t = 0) {
  int deg = (int) g[a].size();
  ld jump = 2 / (ld) deg;
  for (auto &b : g[a]) {
    if (b == p) continue;
    t = rep(t + jump);
    cout << 1 << " " << id[{a, b}] << " ";
    if (t <= 1) {
      cout << b << " " << a << " " << fixed << setprecision(6) << 1 - t << "\n";
    } else {
      cout << a << " " << b << " " << fixed << setprecision(6) << 1 - rep(t + 1) << "\n";
    }
    dfs(b, a, rep(t + 1));
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    id[{x, y}] = i;
    id[{y, x}] = i;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = 1;
  cout << n - 1 << "\n";
  dfs(root);
}
#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 7;
int n, k, a[N], sub[N], gsub[N], sol;
bool good[N];
vector<int> g[N], kids[N];

void bok(int a) {
  gsub[a] = good[a];
  for (auto &b : g[a]) {
    bok(b);
    gsub[a] += gsub[b];
  }
}

int dfs(int a) {
  if (good[a] == 0) {
    for (auto &b : g[a])
      dfs(b);
    return 0;
  }
  int f = 0, s = 0, tot = 1;
  for (auto &b : g[a]) {
    int dp = dfs(b);
    if (dp == sub[b])
      tot += dp;
    else {
      if (dp > f) {
        s = f;
        f = dp;
      } else
        s = max(s, dp);
    }
  }
  sol = max(sol, tot + f + s);
  if (n - sub[a] == gsub[1] - gsub[a])
    sol = max(sol, tot + f + s + n - sub[a]);
  return tot + f;
}

bool ok(int x) {
  sol = 0;
  for (int i = 1; i <= n; i++)
    good[i] = (a[i] >= x);
  bok(1);
  dfs(1);
  return sol >= k;
}

void build(int a, int p) {
  sub[a] = 1;
  for (auto &b : g[a])
    if (b != p) {
      kids[a].push_back(b);
      build(b, a);
      sub[a] += sub[b];
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build(1, 0);
  for (int i = 1; i <= n; i++)
    g[i] = kids[i];
  int l = 1, r = 1000000, ans;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m)) {
      ans = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  cout << ans << "\n";
}
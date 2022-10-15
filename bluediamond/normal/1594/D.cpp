#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int ll
typedef long double ld;

const int N = (int) 2e5 + 7;
int n;
int m;
int c0;
int c1;
int col[N];
vector<pair<int, int>> g[N];
bool ok;

void dfs(int a) {
  c0 += (col[a] == 0);
  c1 += (col[a] == 1);
  for (auto &it : g[a]) {
    int b = it.first, val = (it.second ^ col[a]);
    if (col[b] == -1) {
      col[b] = val;
      dfs(b);
    } else {
      ok &= (col[b] == val);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      col[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y;
      string s;
      cin >> s;
      z = (s[0] == 'i');
    //  z = (s[i] != 'i');
      g[x].push_back({y, z});
      g[y].push_back({x, z});
    }
    ok = 1;
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      if (col[i] != -1) continue;
      c0 = c1 = 0;
      col[i] = 0;
      dfs(i);
      sol += max(c0, c1);
    }
    if (!ok) {
      cout << "-1\n";
    } else {
      cout << sol << "\n";
    }
  }

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 5e5 + 7;
int n, m, t[N], information[N];
vector<int> atp[N];
vector<int> g[N];

void dfs(int a, int dep) {
  atp[dep].push_back(a);
  information[a] = dep;
  for (auto &b : g[a]) {
    if (t[b] == 0) {
      t[b] = a;
      dfs(b, dep + 1);
    }
  }
}

void solve() {
  int mx = 0, who;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, information[i]);
    if (information[i] == mx) {
      who = i;
    }
  }
  if (mx >= (n + 1) / 2) {
    cout << "PATH\n";
    vector<int> sol;
    while (who != -1) {
      sol.push_back(who);
      who = t[who];
    }
    cout << (int) sol.size() << "\n";
    for (auto &x : sol) {
      cout << x << " ";
    }
    cout << "\n";
    return;
  }
  vector<pair<int, int>> sol;
  for (int i = 1; i <= mx; i++) {
    for (int j = 0; j + 1 < (int) atp[i].size(); j += 2) {
      sol.push_back({atp[i][j], atp[i][j + 1]});
    }
  }
  cout << "PAIRING\n";
  cout << (int) sol.size() << "\n";
  for (auto &it : sol) {
    cout << it.first << " " << it.second << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      t[i] = 0;
      atp[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    t[1] = -1;
    dfs(1, 1);
    solve();
  }
  return 0;
}
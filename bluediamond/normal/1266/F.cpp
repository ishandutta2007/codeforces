#include <bits/stdc++.h>

using namespace std;

void maxup(int &a, int b) {
  a = max(a, b);
}

const int N = (int) 5e5 + 7;
const int INF = (int) 1e9 + 7;
vector<int> g[N];
vector<int> deps[N];
vector<int> tr[N];
int n;
int sol[N];
int par[N];
int dep_max_down[N];
int dep_max_up[N];

void build_dep_max_down(int a, int p) {
  par[a] = p;
  {
    dep_max_down[a] = 0;
    vector<int> kids;
    for (auto &b : g[a]) {
      if (b == p) continue;
      kids.push_back(b);
      build_dep_max_down(b, a);
      dep_max_down[a] = max(dep_max_down[a], 1 + dep_max_down[b]);
    }
    g[a] = kids;
  }
}

void build_dep_max_up(int a) {
  if (par[a]) {
    maxup(dep_max_up[a], 1 + dep_max_up[par[a]]);
  }
  for (int stp = 1; stp <= 2; stp++) {
    reverse(g[a].begin(), g[a].end());
    int mx = -INF;
    for (auto &b : g[a]) {
      dep_max_up[b] = max(dep_max_up[b], 2 + mx);
      maxup(mx, dep_max_down[b]);
    }
  }

  for (auto &b : g[a]) {
    build_dep_max_up(b);
  }
}

void solve(int a) {

  {
    if (par[a]) {
      deps[a].push_back(dep_max_up[a]);
    }
    for (auto &b : g[a]) {
      deps[a].push_back(1 + dep_max_down[b]);
    }
    sort(deps[a].rbegin(), deps[a].rend());
    {
      /// 2 * l + 1 => l + 1 and at most one l
      for (int it = 0; it < (int) deps[a].size(); it++) {
        int l = deps[a][it] - 1, cnt_l_plus_1 = it + 1, cnt_l = 0;
        if (it + 1 < (int) deps[a].size() && deps[a][it + 1] >= l) {
          cnt_l++;
        }
        if (1 <= l && 2 * l + 1 <= n) {
          maxup(sol[2 * l + 1], cnt_l_plus_1 + min(1, cnt_l));
        }
        if (it + 1 < (int) deps[a].size() && deps[a][it] != deps[a][it + 1]) {
          l = deps[a][it + 1];
          cnt_l_plus_1 = it + 1;
          cnt_l = 1;
          if (1 <= l && 2 * l + 1 <= n) {
            maxup(sol[2 * l + 1], cnt_l_plus_1 + min(1, cnt_l));
          }
        }
      }
    }
    {
      /// 2 * l => l
      for (int it = 0; it < (int) deps[a].size(); it++) {
        int l = deps[a][it], cnt_l = it + 1;
        if (1 <= l && 2 * l <= n) {
          maxup(sol[2 * l], cnt_l);
        }
      }
    }
  }


  for (auto &b : g[a]) {
    solve(b);
  }
}

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  cin >> n;
  vector<pair<int, int>> edges;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back({a, b});
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    sol[i] = 1;
  }
  for (int a = 1; a <= n; a++) {
    sol[1] = max(sol[1], (int) g[a].size() + 1);
  }
  build_dep_max_down(1, 0);
  build_dep_max_up(1);
  solve(1);

  for (auto &edge : edges) {
    int a = edge.first, b = edge.second;
    if ((int) deps[a].size() > (int) deps[b].size()) {
      swap(a, b);
    }
    assert((int) deps[a].size() <= (int) deps[b].size());
    tr[b].push_back(a);
  }
  for (int b = 1; b <= n; b++) {
    vector<int> big((int) deps[b].size(), -INF);
    for (auto &a : tr[b]) {

      for (int p0 = 0; p0 < (int) deps[a].size(); p0++) {
        int low = 0, high = (int) deps[b].size() - 1, cnt = 0;
        while (low <= high) {
          int mid = (low + high) / 2;
          if (deps[b][mid] > deps[a][p0]) {
            cnt = mid + 1;
            low = mid + 1;
          } else {
            high = mid - 1;
          }
        }
        if (cnt >= 1) {
          int p1 = cnt - 1;
          maxup(sol[2 * deps[a][p0]], p0 + p1);
        }
        if (cnt < (int) deps[b].size()) {
          big[cnt] = max(big[cnt], p0);
        }
      }
    }

    int mx = -INF;
    for (int p1 = 0; p1 < (int) deps[b].size(); p1++) {
      mx = max(mx, big[p1]);
      maxup(sol[2 * deps[b][p1]], mx + p1);
    }
  }

#ifndef ONLINE_JUDGE
  cout << " = " << sol[5] << "\n";
#endif // ONLINE_JUDGE

  for (int i = n - 2; i >= 1; i--) {
    sol[i] = max(sol[i + 2], sol[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
  exit(0);
}
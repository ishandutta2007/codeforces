#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e6 + 7;
int n, a[N], b[N], xx[N], yy[N], cnt[N], y;
vector<int> g[N];
bool vis[N];

int nos, eos;

void dfs(int a) {
  vis[a] = 1;
  nos++;
  eos += 2 * cnt[a] + (int) g[a].size();
  for (auto &b : g[a]) {
    if (!vis[b]) {
      dfs(b);
    }
  }
}

bool ok(int lim) {
  for (int i = 1; i <= y; i++) {
    g[i].clear();
    cnt[i] = 0;
    vis[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (lim < a[i]) return 0;
    if (lim < b[i]) {
      cnt[xx[i]]++;
    } else {
      g[xx[i]].push_back(yy[i]);
      g[yy[i]].push_back(xx[i]);
    }
  }

  for (int i = 1; i <= y; i++) {
    if (!vis[i]) {
      nos = 0;
      eos = 0;
      dfs(i);
      eos /= 2;
      if (eos > nos) return 0;
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  vector<pair<int, int>> kek;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    kek.push_back({a[i], i});
    kek.push_back({b[i], i + n});
  }
  sort(kek.begin(), kek.end());
  vector<int> v;
  int ant = -1;
  for (auto &it : kek) {
    if (it.first != ant) {
      y++;
      v.push_back(it.first);
      ant = it.first;
    }
    if (it.second <= n) xx[it.second] = y;
    else yy[it.second - n] = y;
  }
  int l = 0, r = y - 1, sol = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(v[m])) {
      sol = v[m];
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << sol << "\n";


  return 0;
}
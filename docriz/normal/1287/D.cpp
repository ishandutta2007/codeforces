#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int n, root, c[MAXN], size[MAXN];
vector<int> G[MAXN];

vector<pair<int, int>> ans[MAXN];

void dfs(int cur) {
  // printf("dfs(%d)\n", cur);
  size[cur] = 1;
  for (auto nx: G[cur]) {
    dfs(nx);
    for (auto v: ans[nx]) {
      v.first += size[cur];
      ans[cur].push_back(v);
    }
    size[cur] += size[nx];
  }
  if (ans[cur].empty()) {
    ans[cur].push_back(make_pair(1, cur));
  } else {
    for (auto&& v: ans[cur]) v.first += v.first;
    sort(ans[cur].begin(), ans[cur].end());
    if (c[cur] == 0) {
      ans[cur].push_back(make_pair(1, cur));
    } else {
      ans[cur].push_back(make_pair(ans[cur][c[cur] - 1].first + 1, cur));
    }
    sort(ans[cur].begin(), ans[cur].end());
    for (int i = 0; i < (int)ans[cur].size(); i++) {
      ans[cur][i].first = i + 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p >> c[i];
    if (p == 0) root = i;
    else {
      G[p].push_back(i);
    }
  }
  dfs(root);
  vector<int> Ans(n + 1);
  assert((int)ans[root].size() == n);
  for (auto t: ans[root]) {
    Ans[t.second] = t.first;
  }
  auto check = [&]() -> bool {
    function<int(int, int)> dfs;
    dfs = [&](int cur, int v) -> int {
      int ret = 0;
      if (Ans[cur] < v) ++ret;
      for (auto nx: G[cur]) {
        ret += dfs(nx, v);
      }
      return ret;
    };
    for (int i = 1; i <= n; i++) {
      if (dfs(i, Ans[i]) != c[i]) {
        return false;
      }
    }
    return true;
  };

  if (!check()) {
    cout << "NO\n";
    return 0;
  }

  // assert(check());
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << Ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
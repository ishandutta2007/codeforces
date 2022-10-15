#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100 + 7;
int n;
int m;
int t[N];
vector<pair<int, int>> g[N];

void dfs(int a) {
  for (auto &it : g[a]) {
    int b = it.first;
    int c = t[a] ^ it.second;
    if (t[b] == -1) {
      t[b] = c;
      dfs(b);
    } else {
      if (t[b] != c) {
        cout << "Impossible\n";
        exit(0);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  /// 0 => diferite
  /// 1 => la fel
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    t[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    c ^= 1;
    g[x].push_back({y, c});
    g[y].push_back({x, c});
  }
  for (int i = 1; i <= n; i++) {
    if (t[i] == -1) {
      t[i] = 0;
      dfs(i);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += t[i];
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; i++) {
    if (t[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
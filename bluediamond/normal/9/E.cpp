#include <bits/stdc++.h>

using namespace std;

const int N = 50 + 7;
int n, m, d[N];
bool is_edge[N][N];
vector<int> dims;
vector<int> aloha;
vector<int> g[N];
vector<pair<int, int>> all;

void dfs(int a) {
  dims.push_back((int) g[a].size());
  aloha.push_back(a);
  for (auto &b : g[a]) {
    if (d[b] == -1) {
      d[b] = 1 + d[a];
      dfs(b);
    }
  }
}

bool is_cy() {
  if (n == 1) {
    return 1;
  }
  for (int i = 1; i <= n; i++) {
    if ((int) g[i].size() != 2) {
      return 0;
    }
  }
  return 1;
}

pair<int, int> small(pair<int, int> a) {
  if (a.first > a.second) {
    swap(a.first, a.second);
  }
  return a;
}

void rep() {
  for (auto &it : all) {
    it = small(it);
  }
}

int cc[N][N];

bool ok() {
  sort(dims.begin(), dims.end());
  int l = (int) dims.size();
  if (l == 1) {
    return (dims[0] == 0);
  }
  if (dims[0] != 1 || dims[1] != 1) {
    return 0;
  }
  for (int i = 2; i < l; i++) {
    if (dims[i] != 2) {
      return 0;
    }
  }
  return 1;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  if (n == 1) {
    if (m >= 2) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    m = 1 - m;
    cout << m << "\n";
    for (int i = 1; i <= m; i++) {
      cout << "1 1\n";
    }
    return 0;
  }
  if (n == 2) {
    int cc = 0;
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      if (x == y) {
        cout << "NO\n";
        return 0;
      }
      cc++;
    }
    if (cc >= 3) {
      cout << "NO\n";
      return 0;
    }
    cc = 2 - cc;
    cout << "YES\n";
    cout << cc << "\n";
    for (int i = 1; i <= cc; i++) {
      cout << "1 2\n";
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    d[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (is_edge[x][y] || (x == y)) {
      cout << "NO\n";
      return 0;
    }
    is_edge[x][y] = is_edge[y][x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j && is_edge[i][j]) {
        g[i].push_back(j);
      }
    }
  }
  if (is_cy()) {
    cout << "YES\n";
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] == -1) {
      aloha.clear();
      dims.clear();
      d[i] = 0;
      dfs(i);
      if (!ok()) {
        cout << "NO\n";
        return 0;
      }
      if ((int) aloha.size() == 1) {
        all.push_back({aloha[0], aloha[0]});
      } else {
        int p1, p2 = aloha.back();
        for (int j = 1; j < (int) aloha.size(); j++) {
          if (d[aloha[j]] == 1) {
            p1 = aloha[j - 1];
          }
        }
        all.push_back({p1, p2});
      }
    }
  }
  cout << "YES\n";
  cout << (int) all.size() << "\n";
  while ((int) all.size() >= 2) {
    rep();
    sort(all.rbegin(), all.rend());
    pair<int, int> ff = all.back();
    all.pop_back();
    pair<int, int> ss = all.back();
    all.pop_back();
    cout << ff.first << " " << ss.first << "\n";
    all.push_back({ff.second, ss.second});
  }
  rep();
  cout << all[0].first << " " << all[0].second << "\n";
}
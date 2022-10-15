#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n, m, k, d[N], pap[N];
vector<int> g[N];
vector<int> bk[N];
vector<int> nor[N];

void dfs(int a) {
  for (auto &b : g[a]) {
    if (d[b] == -1) {
      nor[a].push_back(b);
      d[b] = 1 + d[a];
      pap[b] = a;
      dfs(b);
    } else {
      if (d[b] < d[a] - 1) {
        bk[a].push_back(b);
      }
    }
  }
}

void dfs2(int a) {
  for (auto &b : bk[a]) {
    vector<int> path;
    int now = a;
    while (1) {
      path.push_back(now);
      if (now == b) break;
      now = pap[now];
    }
    if ((int) path.size() <= k) {
      cout << "2\n";
      cout << (int) path.size() << "\n";
      for (auto &a : path) {
        cout << a << " ";
      }
      cout << "\n";
      exit(0);
    }
    vector<int> indp;
    for (int i = 1; i < (int) path.size(); i += 2) {
      indp.push_back(path[i]);
    }
    cout << "1\n";
    for (int i = 0; i < (k + 1) / 2; i++) {
      cout << indp[i] << " ";
    }
    cout << "\n";
    exit(0);
  }
  for (auto &b : nor[a]) {
    dfs2(b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    d[i] = -1;
  }
  d[1] = 0;
  dfs(1);
  dfs2(1);
  vector<vector<int>> nodes(2);
  for (int i = 1; i <= n; i++) {
    nodes[d[i] % 2].push_back(i);
  }
  int prn = 1;
  if ((int) nodes[0].size() > (int) nodes[1].size()) {
    prn = 0;
  }
  cout << "1\n";
  for (int i = 0; i < (k + 1) / 2; i++) {
    cout << nodes[prn][i] << " ";
  }
  cout << "\n";
  return 0;
}
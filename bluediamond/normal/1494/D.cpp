#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

const int N = 5000 + 7;
int n, a[N][N], y = 0, col[N], par[N], t[N], label[N];

int root(int i) {
  if (t[i] == i) return i;
  return t[i] = root(t[i]);
}

void unite(int i, int j) {
  t[root(i)] = root(j);
}

void solve(vector<int> nodes, int last = 0) {
 /** cout << " : ";
  for (auto &x : nodes) {
    cout << x << " ";
  }
  cout << "\n"; **/
  if ((int) nodes.size() == 1) {
    y++;
    col[y] = a[nodes[0]][nodes[0]];
    par[y] = last;
    label[y] = nodes[0];
    return;
  }
  int mx = 0, k = (int) nodes.size();
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < i; j++) {
      mx = max(mx, a[nodes[i]][nodes[j]]);
    }
  }
  y++;
  col[y] = mx;
  par[y] = last;
  for (auto &x : nodes) {
    t[x] = x;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < i; j++) {
      if (a[nodes[i]][nodes[j]] < mx) {
        unite(nodes[i], nodes[j]);
      }
    }
  }
  vector<vector<int>> las;
  int now = y;
  for (auto &x : nodes) {
    if (t[x] != x) continue;
    vector<int> la;
    for (auto &y : nodes) {
      if (root(y) == x) {
        la.push_back(y);
      }
    }
    las.push_back(la);
  }
  for (auto &la : las) {
    solve(la, now);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> nodes;
  for (int i = 1; i <= n; i++) {
    nodes.push_back(i);
  }
  solve(nodes);
  for (int i = 1; i <= y; i++) {
    if (!label[i]) {
      label[i] = ++n;
    }
  }
  cout << y << "\n";
  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= y; j++) {
      if (label[j] == i) {
        cout << col[j] << " ";
      }
    }
  }
  cout << "\n";
  cout << label[1] << "\n";
  int cnt = 0;
  for (int i = 1; i <= y; i++) {
    if (par[i]) {
      cnt++;
      cout << label[i] << " " << label[par[i]] << "\n";
    }
  }
  assert(cnt == y - 1);
}
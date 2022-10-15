#include <bits/stdc++.h>

using namespace std;

void bkt(int done, vector<vector<int>> a) {
  int n = (int) a.size(), m = (int) a[0].size();
  vector<vector<int>> difs(n);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] != a[0][j]) difs[i].push_back(j);
  /// a[0] contains the result and a[0] differs from the initial a[0] (at most) done times
  bool all_ok = 1;
  for (int i = 0; i < n; i++) {
    if ((int) difs[i].size() - (2 - done) > 2) return;
    if ((int) difs[i].size() > 2) all_ok = 0;
  }
  if (all_ok) {
    cout << "Yes\n";
    for (auto &x : a[0]) cout << x << " ";
    cout << "\n";
    exit(0);
  }
  if (done == 2) return;
  int wrong = 0;
  while ((int) difs[wrong].size() <= 2) wrong++;
  for (auto &modif : difs[wrong]) {
    int init = a[0][modif];
    a[0][modif] = a[wrong][modif];
    bkt(done + 1, a);
    a[0][modif] = init;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));
  for (auto &v : a) for (auto &x : v) cin >> x;
  bkt(0, a);
  cout << "No\n";
}
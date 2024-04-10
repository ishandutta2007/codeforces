#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 2e5 + 7;
int n, a[N];
bool vis[N];
vector<pair<int, int>> ret;
vector<vector<int>> cycles;

void op(int i, int j) {
  a[i] *= -1;
  a[j] *= -1;
  swap(a[i], a[j]);
  ret.push_back({i, j});
}

void check() {
  for (int i = 1; i <= n; i++) {
    assert(a[i] == i);
  }
}

void two(vector<int> cycle1, vector<int> cycle2) {
  int k1 = (int) cycle1.size(), k2 = (int) cycle2.size();
  op(cycle1[0], cycle2[0]);
  swap(cycle1[0], cycle2[0]);
  for (int i = 1; i <= k1 - 1; i++) {
    op(cycle1[0], cycle1[i]);
  }
  for (int i = 1; i <= k2 - 1; i++) {
    op(cycle2[0], cycle2[i]);
  }
  op(cycle1[0], cycle2[0]);
}

void one(vector<int> cycle) {
  int k = (int) cycle.size();
  if (k == 1) {
    return;
  }
  if (k == 2) {
    int a = cycle[0], b = cycle[1], c = 1;
    while (c == a || c == b) {
      c++;
    }
    op(a, c);
    op(c, b);
    op(a, c);
    return;
  }
  for (int i = 1; i <= k - 2; i++) {
    op(cycle[0], cycle[i]);
  }
  int a = cycle[0], b = cycle[1], c = cycle[k - 1];
 // op(a, b);
  op(b, c);
  op(a, c);
  op(b, a);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vector<int> cycle;
      int j = i;
      while (!vis[j]) {
        cycle.push_back(j);
        vis[j] = 1;
        j = a[j];
      }
      cycles.push_back(cycle);
    }
  }
  if ((int) cycles.size() & 1) {
    one(cycles.back());
  }
  for (int j = 0; j + 1 < (int) cycles.size(); j += 2) {
    two(cycles[j], cycles[j + 1]);
  }
  check();
  cout << (int) ret.size() << "\n";
  for (auto &it : ret) {
    cout << it.first << " " << it.second << "\n";
  }
}
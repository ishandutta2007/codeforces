#include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 7;
int n, m, deg, mn, mx;
set<pair<int, int>> banned;
bool vec1[N], is;
set<int> unvisited;

void dfs(int a) {
  is |= vec1[a];
  unvisited.erase(a);
  int last = 1;
  while (1) {
    auto it = unvisited.lower_bound(last);
    if (it == unvisited.end()) {
      break;
    }
    int b = *it;
    if (b >= 2 && unvisited.count(b) && !banned.count({a, b})) {
      dfs(b);
    }
    last = b + 1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> deg;
  for (int i = 1; i <= n; i++) {
    vec1[i] = 1;
    if (i >= 2) {
      unvisited.insert(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    banned.insert({x, y});
    banned.insert({y, x});
    if (x == 1) {
      vec1[y] = 0;
    }
    if (y == 1) {
      vec1[x] = 0;
    }
  }
  while (!unvisited.empty()) {
    mn++;
    is = 0;
    dfs(*unvisited.begin());
    if (!is) {
      cout << "impossible\n";
      return 0;
    }
  }
  for (int i = 2; i <= n; i++) {
    mx += vec1[i];
  }
  if (mn <= deg && deg <= mx) {
    cout << "possible\n";
  } else {
    cout << "impossible\n";
  }
}
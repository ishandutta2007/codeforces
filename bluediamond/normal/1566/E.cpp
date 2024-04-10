#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, sol;
vector<int> g[N];

int dfs(int a, int p = -1) {
  int k = 0;
  for (auto &b : g[a]) {
    if (b == p) continue;
    k += dfs(b, a);
  }
  if (k == 0) {
    return 1;
  } else {
    sol += k - 1;
    return 0;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    sol *= 0;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int foo, bar;
      cin >> foo >> bar;
      g[foo].push_back(bar);
      swap(foo, bar);
      g[foo].push_back(bar);
    }
    dfs(1);
    cout << ++sol << "\n";
  }


  return 0;
}
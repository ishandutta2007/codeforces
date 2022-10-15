#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, f[2];
vector<int> g[N];

void dfs(int a, int tp = 0, int p = -1) {
  f[tp]++;
  for (auto &b : g[a]) {
    if (b != p) {
      dfs(b, tp ^ 1, a);
    }
  }
}

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
 /// freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  cout << min(f[0], f[1]) - 1 << "\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
int sol;
vector<int> g[N];

int dfs(int a, int p = -1) {
  vector<int> hs;
  for (auto &b : g[a]) {
    if (b != p) hs.push_back(dfs(b, a) + 1);
  }
  if (hs.empty()) return 0;
  if ((int) hs.size() == 1) {sol = max(sol, hs[0]); return hs[0];}
  sort(hs.begin(), hs.end());
  if (a > 1) {
    sol = max(sol, hs.back() + 1);
    return hs[0];
  } else {
    sol = max(sol, hs.back());
    sol = max(sol, hs[(int) hs.size() - 2] + 1);
    return hs.back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    sol = 0; dfs(1); cout << sol << "\n";
  }


}
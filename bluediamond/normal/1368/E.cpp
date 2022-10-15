#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, m, c[N];
vector<int> ig[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      c[i] = 0;
      ig[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      ig[y].push_back(x);
    }
    vector<int> sol;
    for (int i = 1; i <= n; i++) {
      for (auto &j : ig[i]) {
        c[i] = max(c[i], c[j]);
      }
      c[i]++;
      if (c[i] == 3) {
        c[i] = 0;
        sol.push_back(i);
      }
    }
    cout << (int) sol.size() << "\n";
    for (auto &x : sol) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
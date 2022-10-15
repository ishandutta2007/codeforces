#include <bits/stdc++.h>

bool home = 1;

using namespace std;

/// 425 -> 426
typedef long long ll;
const int N = 1500 + 7;
int n;
int q[N];
int w[N];
pair<int, int> x[N * N];
ll dot;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int foo;
      cin >> foo;
      x[foo] = {i, j};
    }
  }
  for (int _ = 1; _ <= n * n; _++) {
    dot += q[x[_].first]++ * w[x[_].second]++;
  }
  cout << (ll) n * (n - 1) * n * (n - 1) / 2 - dot << "\n";
}
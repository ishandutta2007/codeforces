#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> of(2, vector<int>(n+1));
    for (int i=1; i<=l; ++i) {
      int x;
      cin >> x;
      of[0][x]++;
    }
    for (int i=1; i<=r; ++i) {
      int x;
      cin >> x;
      of[1][x]++;
    }
    ll cost = 0;
    for (int i=1; i<=n; ++i) {
      int q = min(of[0][i], of[1][i]);
      of[0][i] -= q;
      of[1][i] -= q;
      r -= q;
      l -= q;
    }
    if (r < l) {
      swap(of[0], of[1]);
      swap(r, l);
    }
    for (int i=1; i<=n && r > l; ++i) {
      while (r > l && of[1][i] >= 2) {
        r -= 2;
        cost += 1;
        of[1][i] -= 2;
      }
    }
    int q = min(r, l);
    cost += q;
    r -= q;
    l -= q;
    cost += r;
    assert(l == 0);
    cout << cost << "\n";


  }
  return 0;
}
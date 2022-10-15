#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n, b[N], a[N];
/**

len = par

**/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int best = 0;
  for (int bit = 0; bit < 20; bit++) {
    int AndMask = (1 << 20) - (1 << (bit + 1));
    for (int i = 1; i <= n; i++) {
      a[i] = (AndMask & b[i]);
      a[i] ^= a[i - 1];
    }
    /// xor should be zero
    vector<map<int, int>> s(2);
    for (int i = 0; i <= n; i++) {
      bool has = !!(b[i] & (1 << bit));
      if (!has) {
        s[0].clear(), s[1].clear();
      }
      if (!s[i % 2].count(a[i])) {
        s[i % 2][a[i]] = i;
      } else {
        best = max(best, i - s[i % 2][a[i]]);
      }

    }
  }
  cout << best << "\n";


  return 0;
}
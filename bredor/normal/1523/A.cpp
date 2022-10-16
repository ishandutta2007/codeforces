#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  int n, m;
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    string ns = s;
    for (int j = 0; j < n; ++j) {
      int c1 = j ? s[j - 1] - '0' : 0;
      int c2 = j + 1 < n ? s[j + 1] - '0' : 0;
      if (c1 + c2 == 1) ns[j] = '1';
    }
    if (s == ns) break;
    s = ns;
  }
  cout << s << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
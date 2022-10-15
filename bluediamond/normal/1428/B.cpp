#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> n >> s;
    int c0 = 0, c1 = 0, c2 = 0;
    for (auto &c : s) {
      c0 += (c == '-');
      c1 += (c == '>');
      c2 += (c == '<');
    }
    if (c1 == 0 || c2 == 0) {
      cout << n << "\n";
      continue;
    }
    int sol = c0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '-' && s[(i + 1) % n] != '-') {
        sol++;
      }
    }
    cout << sol << "\n";
  }
}
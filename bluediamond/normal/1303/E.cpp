#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 400 + 7;
const int INF = (int) 1e9;
int best[N][N];

bool solve_test() {
  string s, t;
  cin >> s >> t;
  int l = (int) s.size();
  int n = (int) t.size();
  for (int ff = -1; ff < n; ff++) {
    string a, b;
    for (int i = 0; i < n; i++) {
      if (i <= ff) {
        a += t[i];
      } else {
        b += t[i];
      }
    }
    int ca = (int) a.size();
    int cb = (int) b.size();
    for (int i = 0; i <= l; i++) {
      for (int j = 0; j <= ca; j++) {
        best[i][j] = -INF;
      }
    }
    best[0][0] = 0;
    for (int i = 1; i <= l; i++) {
      for (int x = 0; x <= ca; x++) {
        if (x >= 1 && s[i - 1] == a[x - 1]) {
          best[i][x] = best[i - 1][x - 1];
        }
        int y = best[i - 1][x] + 1;
        if (y >= 1 && y <= cb && s[i - 1] == b[y - 1]) {
          best[i][x] = max(best[i][x], y);
        }
        best[i][x] = max(best[i][x], best[i - 1][x]);
      }
    }
    if (best[l][ca] == cb) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    bool ok = solve_test();
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }


}
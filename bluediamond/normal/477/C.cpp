#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void upd(int &a, int b) {
  a = max(a, b);
}

const int N = 2000 + 7;
string s;
string p;
int n;
int m;
int urm[N];
int dp[N][N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);


  cin >> s >> p;
  n = (int) s.size();
  m = (int) p.size();

  for (int i = 0; i < n; i++) {
    int iter = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == p[iter]) {
        iter++;
        if (iter == m) {
          urm[i + 1] = j + 1;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int d = 0; d <= i; d++) {
      upd(dp[i + 1][d + 1], dp[i][d]);
      upd(dp[i + 1][d], dp[i][d]);
      if (urm[i + 1]) {
        int lose = urm[i + 1] - i - m;
        upd(dp[urm[i + 1]][d + lose], dp[i][d] + 1);
      }
    }
  }

  for (int d = 0; d <= n; d++) {
    cout << dp[n][d] << " ";
  }
  cout << "\n";

  return 0;
}
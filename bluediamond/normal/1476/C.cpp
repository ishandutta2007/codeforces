#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 1e5 + 7;
int n;
int c[N];
int a[N];
int b[N];
int alpha[N];
int beta[N];
int gama[N];
int teta[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 2; i <= n; i++) {
      alpha[i] = c[i - 1] - max(0LL, abs(a[i] - b[i]) - 1);
      beta[i] = abs(a[i] - b[i]) + 1;
      alpha[i] += alpha[i - 1];
      gama[i] = beta[i] - alpha[i];
      teta[i] = c[i] + alpha[i];
    }
    int ret = 0;
    for (int i = 2; i <= n; i++) {
      ret = max(ret, teta[i] + gama[i]);
      int cur = c[i] + abs(a[i] - b[i]) + 1;
      ret = max(ret, cur);
      assert(cur == teta[i] + gama[i]);
    }
    int l = 1;
    while (l <= n) {
      if (a[l] == b[l]) {
        l++;
        continue;
      }
      int r = l;
      while (r + 1 <= n && a[r + 1] != b[r + 1]) {
        r++;
      }
      l--;
      if (l - 1 >= 1) {
        l--;
      }
      int mx_gama = -(int) 1e18;
      for (int x = l; x <= r; x++) {
        ret = max(ret, teta[x] + mx_gama);
        mx_gama = max(mx_gama, gama[x + 1]);
      }
      l = r + 1;
    }
    cout << ret << "\n";
  }

}
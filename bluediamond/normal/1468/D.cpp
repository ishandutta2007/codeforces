#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 2e5 + 7;
int s[N];

bool ok(int l, int n, int a, int b) {
  int tm = 0, when = 0;
  for (int i = n; i >= 1; i--) {
    tm = max(tm, s[i] + when);
    when++;
    if (a < b) {
      b--;
    } else {
      b++;
    }
    if (a == b) {
      return 0;
    }
  }
  int extra_time;
  if (a < b) {
    extra_time = b;
  } else {
    extra_time = l - b + 1;
  }
  return when + extra_time - 2 >= tm;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int len, n, a, b;
    cin >> len >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
    }
    sort(s + 1, s + n + 1);
    int l = 0, r = n, cnt = 0;
    while (l <= r) {
      int m = (l + r) / 2;
      if (ok(len, m, a, b)) {
        cnt = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    cout << cnt << "\n";
  }


}
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, a[N], dp[N][2][2];
string str;

void clr() {
  for (int i = 0; i < N; i++) {
    dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
  }
}

bool bg;

bool ok(int l, int r, int fl, int fr) {
  if (dp[l][fl][fr] != -1) return dp[l][fl][fr];
  if (l == r) {
    for (int sum = 0; sum <= 18; sum += 2) {
      if ((sum + fr) % 10 == a[r] && (sum + fr) / 10 == fl) {
        dp[l][fl][fr] = 1;
        return 1;
      }
    }
    dp[l][fl][fr] = 0;
    return 0;
  }
  if (l + 1 == r) {
    for (int sum = 0; sum <= 18; sum++) {
      if ((sum + fr) % 10 == a[r]) {
        int nxtadd = (sum + fr) / 10;
        if ((sum + nxtadd) % 10 == a[l] && (sum + nxtadd) / 10 == fl) {
          dp[l][fl][fr] = 1;
          return 1;
        }
      }
    }
    dp[l][fl][fr] = 0;
    return 0;
  }
  for (int sum = (bg && l == 1); sum <= 18; sum++) {
    if ((sum + fr) % 10 == a[r]) {
      int newfr = (sum + fr) / 10;
      for (int newfl = 0; newfl <= 1; newfl++) {
        if ((sum + newfl) % 10 == a[l] && (sum + newfl) / 10 == fl) {
          if (ok(l + 1, r - 1, newfl, newfr)) {
            dp[l][fl][fr] = 1;
            return 1;
          }
        }
      }
    }
  }
  dp[l][fl][fr] = 0;
  return 0;
}

void print(int l, int r, int fl, int fr) {
  ///cout << "# " << l << " and " << r << " : " << fl << " and " << fr << "\n";
  assert(ok(l, r, fl, fr));
  if (l == r) {
    for (int sum = 0; sum <= 18; sum += 2) {
      if ((sum + fr) % 10 == a[r] && (sum + fr) / 10 == fl) {
        cout << sum / 2;
        return;
      }
    }
    assert(0);
  }
  if (l + 1 == r) {
    for (int sum = 0; sum <= 18; sum++) {
      if ((sum + fr) % 10 == a[r]) {
        int nxtadd = (sum + fr) / 10;
        if ((sum + nxtadd) % 10 == a[l] && (sum + nxtadd) / 10 == fl) {
          cout << (sum + 1) / 2 << sum / 2;
          return;
        }
      }
    }
    assert(0);
  }
  for (int sum = (bg && l == 1); sum <= 18; sum++) {
    if ((sum + fr) % 10 == a[r]) {
      int newfr = (sum + fr) / 10;
      for (int newfl = 0; newfl <= 1; newfl++) {
        if ((sum + newfl) % 10 == a[l] && (sum + newfl) / 10 == fl) {

          if (ok(l + 1, r - 1, newfl, newfr)) {
            cout << (sum + 1) / 2;
            print(l + 1, r - 1, newfl, newfr);
            cout << sum / 2;
            return;
          }
        }
      }
    }
  }
  assert(0);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> str;
  n = (int) str.size();
  for (int i = 1; i <= n; i++) {
    a[i] = str[i - 1] - '0';
  }
  clr();
  bg = 1;
  if (ok(1, n, 0, 0)) {
    print(1, n, 0, 0);
    return 0;
  }
  bg = 0;
  if (a[1] == 1) {
    for (int i = 1; i < n; i++) {
      a[i] = a[i + 1];
    }
    n--;
    clr();
    if (ok(1, n, 1, 0)) {
      print(1, n, 1, 0);
      return 0;
    }
  }
  cout << "0\n";








  return 0;
}
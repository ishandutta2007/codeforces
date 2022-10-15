#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 2e5 + 7;
int n, a[N], cnt[N], memo[N][2];
string s;

int compute(int i, int x) {
  if (i > n) return 0;
  if (memo[i][x] != -1) return memo[i][x];
  int sol = 0;
  if (a[i] == -1 || a[i] == x) {
    sol = 1 + compute(i + 1, x ^ 1);
  } else {
    sol = 0;
  }
  memo[i][x] = sol;
  return sol;
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      char ch = s[i - 1];
      if (ch == '?') a[i] = -1;
      if (ch == '0') a[i] = 0;
      if (ch == '1') a[i] = 1;
      memo[i][0] = memo[i][1] = -1;
    }
    cnt[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] == -1) {
        cnt[i] = cnt[i + 1] + 1;
        continue;
      }
      cnt[i] = compute(i, a[i]);
    }
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      sol += cnt[i];
    }
    cout << sol << "\n";
  }
  return 0;
}
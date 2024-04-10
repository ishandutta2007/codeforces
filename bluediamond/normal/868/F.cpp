#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
const int INF = (int) 1e18;
int n, k, a[N], dp[N], nw[N], f[N], sum, acum[N], tot[N];
int act[N];
int f2[N], sum2;

void pop2(int i) {
  i = a[i];
  f2[i]--;
  sum2 -= f2[i];
}

void add2(int i) {
  i = a[i];
  sum2 += f2[i];
  f2[i]++;
}

void pop(int i) {
  act[i] = 0;
  i = a[i];
  f[i]--;
  sum -= f[i];
}

void add(int i) {
  act[i] = 1;
  i = a[i];
  sum += f[i];
  f[i]++;
}

void rec(int l, int r, int lo, int hi) {
  if (l > r) return;
  int m = (l + r) / 2;
  if (hi + 1 <= m) {
    for (int j = m + 1; j <= r; j++) pop(j);
    for (int j = hi; j >= lo; j--) {
      add(j);
      acum[j] = sum;
    }
    for (int j = lo; j <= hi; j++) {
      pop(j);
    }
    for (int j = m + 1; j <= r; j++) add(j);
  } else {
    for (int j = m; j >= lo; j--) {
      add2(j);
      acum[j] = sum2;
    }
    for (int j = m; j >= lo; j--) {
      pop2(j);
    }
  }
  int best = INF;
  for (int j = lo; j <= min(m, hi); j++) {
    tot[j] = acum[j] + dp[j - 1];
    best = min(best, tot[j]);
  }
  int opt = -1;
  for (int j = lo; j <= min(m, hi); j++) {
    if (tot[j] == best) {
      opt = j;
      break;
    }
  }
  nw[m] = best;
  for (int j = opt + 1; j <= hi; j++) {
    if (j <= r) {
      add(j);
    }
  }
  for (int j = r; j >= m; j--) {
    if (opt + 1 <= j) {
      pop(j);
    }
  }
  rec(l, m - 1, lo, opt);
  for (int j = r; j >= m; j--) {
    if (opt + 1 <= j) {
      add(j);
    }
  }
  for (int j = opt + 1; j <= hi; j++) {
    if (j <= r) {
      pop(j);
    }
  }


  rec(m + 1, r, opt, hi);
}

void upd() {
  for (int i = 1; i <= n; i++) f[i] = 0, act[i] = 0;
  sum = 0;
  rec(1, n, 1, n);
}

signed realMain() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + f[a[i]]++;
  }
  for (int j = 2; j <= k; j++) {
    for (int i = 1; i <= n; i++) {
      nw[i] = INF;
    }
    upd();
    for (int i = 1; i <= n; i++) {
      dp[i] = nw[i];
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
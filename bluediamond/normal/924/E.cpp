#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

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

struct T {
  int type, len;
};

bool operator < (T a, T b) {
  if (a.type != b.type) return a.type < b.type;
  return a.len > b.len;
}

const int N = (int) 1e4 + 7, INF = (int) 1e9;
int n, l, r, s, dp[N];
T a[N];

signed realMain() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) cin >> a[i].len;
  for (int i = 1; i <= n; i++) cin >> a[i].type;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s += a[i].len;
  l = s - l;
  r = s - r;
  swap(l, r);
  for (int i = 1; i < N; i++) dp[i] = -INF;
  for (int i = 1; i <= n; i++) {
    for (int j = N - 1; j >= 0; j--) {
      if (dp[j] == -INF) continue;
      dp[j + a[i].len] = max(dp[j + a[i].len], dp[j] + a[i].type * (l <= j + a[i].len && j + a[i].len <= r));
    }
  }
  int ret = 0;
  for (int i = 1; i < N; i++) {
    ret = max(ret, dp[i]);
  }
  cout << ret << "\n";
  return 0;
}
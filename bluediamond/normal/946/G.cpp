#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int long long
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

const int N = 400000 + 7;

void upd(int aib[], int i, int val) {
  while (i < N) {
    aib[i] = max(aib[i], val);
    i += i & (-i);
  }
}

int get(int aib[], int i) {
  int ret = 0;
  while (i) {
    ret = max(ret, aib[i]);
    i -= i & (-i);
  }
  return ret;
}

int n, a[N], dp1[N], dp2[N], b[N], aib1[N], aib2[N];

signed realMain() {
  cin >> n;
  map<int, int> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i] + 1;
    t[a[i]] = t[b[i]] = 0;
    dp1[i] = dp2[i] = 1;
  }
  int idx = 0;
  for (auto &it : t) {
    it.second = ++idx;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = t[a[i]];
    b[i] = t[b[i]];
  }
  for (int i = 1; i <= n; i++) {
    dp1[i] = max(dp1[i], get(aib1, a[i]) + 1);
    dp2[i] = max(dp2[i], get(aib2, a[i]) + 1);
    if (i + 1 <= n) {
      dp2[i + 1] = max(dp2[i + 1], get(aib1, b[i + 1]) + 1);
    }
    upd(aib1, a[i], dp1[i]);
    upd(aib2, a[i], dp2[i]);
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    ret = max(ret, dp1[i]);
    ret = max(ret, dp2[i]);
  }
  cout << max(0LL, n - 1 - ret) << "\n";
  return 0;
}
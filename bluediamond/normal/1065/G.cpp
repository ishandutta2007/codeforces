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

int add(int a, int b) {
  return min(a + b, (int) 2e18);
}

const int N = 200 + 7;
string pre[N], suf[N], sol;
int n, k, m, dp[N];

int cate(string s) {
  int ret = 0;
  for (int j = 0; j + (int) sol.size() - 1 < (int) s.size(); j++) {
    bool match = 1;
    for (int k = 0; k < (int) sol.size(); k++) {
      if (sol[k] != s[j + k]) {
        match = 0;
        break;
      }
    }
    ret += match;
  }
  return ret;
}

int get() {
  dp[0] = (sol == "0");
  dp[1] = (sol == "1");
  for (int j = 2; j <= n; j++) {
    dp[j] = add(dp[j - 2], dp[j - 1]);
    dp[j] = dp[j] + cate(suf[j - 2] + pre[j - 1]) - cate(suf[j - 2]) - cate(pre[j - 1]);
  }
  return dp[n];
}

signed realMain() {
  cin >> n >> k >> m;
  pre[0] = suf[0] = "0";
  pre[1] = suf[1] = "1";
  for (int j = 2; j <= n; j++) {
    pre[j] = pre[j - 2];
    if ((int) pre[j].size() < N) {
      pre[j] += pre[j - 1];
    }
    suf[j] = suf[j - 1];
    if ((int) suf[j].size() < N) {
      suf[j] = suf[j - 2] + suf[j];
    }
  }
  for (int l = 1; l <= m; l++) {
    sol += "0";
    int cate_incep_cu_sol = get();
    if (k > cate_incep_cu_sol) {
      k -= cate_incep_cu_sol;
      sol.back() = '1';
    }
    /// am invatat sa folosesc functia substr
    if (suf[n].substr((int) suf[n].size() - l, l) == sol) {
      k--;
      if (!k) {
        cout << sol << "\n";
        return 0;
      }
    }
  }
  cout << sol << "\n";
  return 0;
}
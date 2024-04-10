#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a) + 1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int dp[5005], ps[5005];
int pr[5005], oc[256];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string cs;
  for (char c : s) {
    if (!cs.size() && cs.back() == c)
      continue;
    cs += c;
  }
  int l = cs.size();
  memset(oc, -1, sizeof oc);
  rep(i, l) {
    pr[i] = oc[cs[i]];
    oc[cs[i]] = i;
    if (pr[i] == -1)
      dp[i] = 1;
  }
  rep(x, n - 1) {
    rep(i, l) {
      if (i)
        ps[i] = (ps[i - 1] + dp[i]) % MOD;
      else
        ps[i] = dp[i];
    }
    rep(i, l) {
      if (i)
        dp[i] = (dp[i] + ps[i - 1]) % MOD;
      if (pr[i] != -1)
        dp[i] = (dp[i] + MOD - ps[pr[i]]) % MOD;
    }
  }
  int sm = 0;
  rep(i, l) sm = (sm + dp[i]) % MOD;
  cout << sm << endl;
}
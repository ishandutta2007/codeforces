#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

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
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int B = 61;
const int N = (int) 1e5 + 7;
const int INF = (int) 1e18;
int n, a[N], dp[B][N]; /// we only care about the amount of carry from the last one
int cnt[3];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = a[n] - a[i];
  }
  for (int b = 0; b < B; b++) {
    for (int i = 0; i < N; i++) {
      dp[b][i] = INF;
    }
  }
  {
    /// only consider the first bit
    int ones = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 1) {
        ones++;
      }
    }
    /// I put 0 => no one has carry
    dp[0][0] = ones;
    /// I put 1 => ones have carry
    dp[0][ones] = min(dp[0][ones], n - ones);
  }
  for (int b = 0; b + 1 < B; b++) {
    cnt[0] = cnt[1] = cnt[2] = 0;
    vector<pair<int, int>> ks;
    vector<int> k;
    for (int i = 1; i <= n; i++) {
      ks.push_back({a[i] % (1LL << (b + 1)), i});
      int now = !!(a[i] & (1LL << (b + 1)));
      cnt[now]++;
    }
    sort(ks.rbegin(), ks.rend());
    for (auto &it : ks) k.push_back(it.second);
    for (int pre = 0; pre <= n; pre++) {
      if (pre) {
        int now = !!(a[k[pre - 1]] & (1LL << (b + 1)));
        cnt[now]--;
        cnt[now + 1]++;
      }
      if (dp[b][pre] == INF) continue;
      for (int put = 0; put <= 1; put++) {
        int cntt = 0, relax = dp[b][pre];
        for (int bef = 0; bef <= 2; bef++) {
          int will_be = (bef + put) % 2;
          int will_carry = (bef + put) / 2;
          relax += will_be * cnt[bef];
          cntt += will_carry * cnt[bef];
        }
        dp[b + 1][cntt] = min(dp[b + 1][cntt], relax);
      }
    }
  }
  int ret = dp[B - 1][0];
  cout << ret << "\n";
  return 0;
}
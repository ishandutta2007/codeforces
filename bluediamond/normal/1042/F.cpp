#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e6 + 7;
const int INF = (int) 1e9;
int n, k, root = 1, dp[N], mx[N], dp2[N], dp3[N];
vector<int> g[N];

bool cmp(int i, int j) {
  return mx[i] < mx[j];
}

void dfs(int a, int p = -1) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
      dfs(b, a);
    }
  }
  if (kids.empty()) {
    dp[a] = 1;
    mx[a] = 1;
    dp2[a] = 0;
    return;
  }
  for (auto &b : kids) {
    dp[a] += dp[b];
    dp3[b] = min(dp[b], dp2[b]);
  }
  sort(kids.begin(), kids.end(), cmp);
  pair<int, int> ret = {INF, INF};
  int lol = 0;
  for (auto &b : kids) {
    lol += dp[b];
  }
  vector<int> sum((int) kids.size());
  int cur = 0;
  for (int j = 0; j < (int) kids.size(); j++) {
    cur += dp3[kids[j]] - dp[kids[j]];
    sum[j] = cur;
  }
  for (auto &b : kids) {
    int cost = dp2[b] + 1, lim = min(mx[b], k - mx[b]);
    int l = 0, r = (int) kids.size() - 1, pre = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (mx[kids[m]] <= lim) {
        pre = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    cost += lol;
    if (pre >= 0) {
      cost += sum[pre];
    }
    if (2 * mx[b] <= k) {
      cost -= min(dp[b], dp2[b]);
    } else {
      cost -= dp[b];
    }
    ret = min(ret, {cost - 1, mx[b] + 1});
    dp[a] = min(dp[a], cost);
  }
  dp2[a] = ret.first;
  mx[a] = ret.second;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen ("input", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  while ((int) g[root].size() == 1) root++;
  dfs(root);
  cout << dp[root] << "\n";
}
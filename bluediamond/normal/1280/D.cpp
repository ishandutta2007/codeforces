#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool home;
const int N = 3000 + 7;
const ll INF = (ll) 1e18;
int n, m, delta[N], sub[N], ret;
vector<int> g[N];
pair<int, ll> best[N];
pair<int, ll> dp[N][N]; /// dp[node][cnt] = max win, max delta

pair<int, ll> operator + (pair<int, ll> a, pair<int, ll> b) {
  return {a.first + b.first, a.second + b.second};
}

void push(int a) {
  if (a == 1) {
    for (int cnt = 0; cnt < m; cnt++) {
     /// cout << cnt << " : " << dp[a][cnt].first << " " << dp[a][cnt].second << "\n";
      ret = max(ret, dp[a][cnt].first + (dp[a][cnt].second > 0));
    }
    return;
  }
  for (int cnt = 0; cnt < sub[a]; cnt++) {
    dp[a][cnt + 1] = max(dp[a][cnt + 1], {dp[a][cnt].first + (dp[a][cnt].second > 0), 0});
  }
}

void dfs(int a, int p = 0) {
  vector<int> kids;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;
    kids.push_back(b);
    dfs(b, a);
    sub[a] += sub[b];
  }
  for (int cnt = 0; cnt <= sub[a]; cnt++) {
    dp[a][cnt] = {0, -INF};
  }
  if (kids.empty()) {
    dp[a][0] = {0, delta[a]};
    push(a);
    return;
  }
  int sum = 1;
  for (int cnt = 0; cnt <= sub[kids[0]]; cnt++) {
    dp[a][cnt] = dp[kids[0]][cnt];
  }
  sum += sub[kids[0]];
 // cout << "aici\n";
  for (int j = 1; j < (int) kids.size(); j++) {
    for (int k = 0; k <= sum + sub[kids[j]]; k++) {
      best[k] = {0, -INF};
    }
    for (int cnt1 = sum; cnt1 >= 0; cnt1--) {
      for (int cnt2 = sub[kids[j]]; cnt2 >= 0; cnt2--) {
        best[cnt1 + cnt2] = max(best[cnt1 + cnt2], dp[a][cnt1] + dp[kids[j]][cnt2]);
      }
    }
    sum += sub[kids[j]];
    for (int k = 0; k <= sum; k++) {
      dp[a][k] = best[k];
    }
  }
  for (int cnt = 0; cnt <= sub[a]; cnt++) {
    dp[a][cnt].second += delta[a];
  }
  push(a);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

    ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> delta[i];
      g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      delta[i] = x - delta[i];
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    ret = 0;
    dfs(1);
   /** for (int i = 1; i <= n; i++) {
      cout << delta[i] << " ";
    }
    cout << "\n";**/
    cout << ret << "\n";
  }
}
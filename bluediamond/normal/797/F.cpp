#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
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
  realMain();
}

const int N = 5000 + 7;
const int INF = (int) 1e18;
int n, m, x[N], y[N], cnt[N], dp[N], val[N], recup[N];
pair<int, int> v[N];

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(x + 1, x + n + 1);
  sort(v + 1, v + m + 1);
  for (int i = 1; i <= m; i++) {
    y[i] = v[i].first;
    cnt[i] = v[i].second;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i] = INF;
    }
  }
  for (int st = 1; st <= m; st++) {
    for (int i = 1; i <= n; i++) {
      val[i] = val[i - 1] + abs(y[st] - x[i]);
    }
    for (int i = 1; i <= n; i++) {
      recup[i] = dp[i];
    }
    deque<pair<int, int>> dq;
    for (int i = 1; i <= n; i++) {
      int psh = dp[i - 1] - val[i - 1];
      while (!dq.empty() && psh < dq.back().second) {
        dq.pop_back();
      }
      dq.push_back({i - 1, psh});
      if (i - dq.front().first > cnt[st]) {
        dq.pop_front();
      }
      assert(!dq.empty());
      int value = min(INF, dq.front().second);
      if (value != INF) {
        value += val[i];
        recup[i] = min(recup[i], value);
      }
    }
    for (int i = 1; i <= n; i++) {
      dp[i] = recup[i];
    }
  }
  if (dp[n] == INF) dp[n] = -1;
  cout << dp[n] << "\n";
  return 0;
}
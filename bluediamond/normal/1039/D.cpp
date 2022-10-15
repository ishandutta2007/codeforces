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

const int N = (int) 1e5 + 7;
int n, ret[N], len, aib[N];
vector<int> g[N], ord;
pair<int, int> dp[N];

void upd(int pre, int val) {
  pre = n + 1 - pre;
  while (pre <= n) {
    aib[pre] = max(aib[pre], val);
    pre += pre & (-pre);
  }
}

int best(int pre) {
  pre = n + 1 - pre;
  int ret = 0;
  while (pre) {
    ret = max(ret, aib[pre]);
    pre -= pre & (-pre);
  }
  return ret;
}

void build(int a, int p = -1) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
      build(b, a);
    }
  }
  ord.push_back(a);
  g[a] = kids;
}

int get(int __len) {
  len = __len;
  if (ret[len] == -1) {
    for (auto &a : ord) {
      int m1 = 0, m2 = 0, ret = 0;
      for (auto &b : g[a]) {
        ret += dp[b].first;
        if (dp[b].second > m1) {
          m2 = m1;
          m1 = dp[b].second;
        } else {
          m2 = max(m2, dp[b].second);
        }
      }
      if (m1 + m2 + 1 >= len) {
        dp[a] = {ret + 1, 0};
      } else {
        dp[a] = {ret, m1 + 1};
      }
    }
    ret[len] = dp[1].first;
    upd(len, ret[len]);
  }
  return ret[len];
}

bool can_bigger(int len, int val) {
  if (ret[len] != -1) {
    return ret[len] >= val;
  }
  if (best(len) >= val) {
    return 1;
  }
  return get(len) >= val;
}

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build(1);
  for (int i = 1; i <= n; i++) {
    ret[i] = -1;
  }
  int rad = sqrt(n), i = 1;
  while (i <= n) {
    ret[i] = get(i);
    if (ret[i] < rad) {
      break;
    } else {
      i++;
    }
  }
  for (int val = ret[i]; val >= 1; val--) {
    /// the last position i so that ret[i] >= val
    int lo = i, hi = n, last = -1;
    if (!can_bigger(lo, val)) {
      continue;
    }
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (can_bigger(mid, val)) {
        last = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << best(i) << "\n";
  }
  return 0;
}
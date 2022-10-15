#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;

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

struct line {
  ll a;
  ll b;
  int i;
  bool operator < (line &ln) {
    if (a == ln.a) {
      return b < ln.b;
    } else {
      return a > ln.a;
    }
  }
  ll eval(ll t) {
    return a * t + b;
  }
};

bool better(line l1, line l2, line l3) {
  return (l3.b - l1.b) * (l1.a - l2.a) < (l2.b - l1.b) * (l1.a - l3.a);
}

const int N = 500000 + 7;
const int INF = (int) 1e18;
int n, sub[N];
int ret = INF, dp[N];
vector<int> g[N];

int sqr(int x) {
  return x * x;
}

void dfs(int a, int p = 0) {
  sub[a] = 1;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b == p) continue;
    kids.push_back(b);
    dfs(b, a);
    sub[a] += sub[b];
  }
  if (kids.empty()) {
    dp[a] = 0;
    return;
  }
  dp[a] = INF;
  for (auto &b : kids) {
    dp[a] = min(dp[a], dp[b] + sqr(sub[a] - sub[b]) + sub[b] - sub[a]);
  }
  int sz = (int) kids.size();
  if (sz == 1) {
    return;
  }
  for (auto &b : kids) {
    dp[b] += sub[b];
    dp[b] -= 2 * n * sub[b];
    dp[b] += sqr(sub[b]);
  }
  int value = INF;
  vector<line> lines((int) kids.size()), hull;
  for (int j = 0; j < (int) kids.size(); j++) {
    lines[j] = {sub[kids[j]], dp[kids[j]]};
  }
  sort(lines.begin(), lines.end());
  for (auto &l : lines) {
    ll x = 2 * l.a;
    int lo = 0, hi = (int) hull.size() - 1, id = 0;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (mid + 1 < (int) hull.size() && hull[mid + 1].eval(x) < hull[mid].eval(x)) {
        lo = mid + 1;
      } else {
        id = mid;
        hi = mid - 1;
      }
    }
    if (!hull.empty()) {
      value = min(value, l.b + hull[id].eval(x));
    }
    while ((int) hull.size() >= 2 && better(hull[(int) hull.size() - 2], hull[(int) hull.size() - 1], l)) {
      hull.pop_back();
    }
    hull.push_back(l);
  }
  ret = min(ret, value - n + (int) n * n);
}

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  ret = min(ret, dp[1]);
  cout << (int) n * (n - 1) - ret / 2 << "\n";
  return 0;
}
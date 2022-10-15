#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
#pragma GCC optimize("O2")


///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

///#pragma GCC target("avx2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
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

struct hulk {

  struct line {
    ll a;
    ll b;
    int i;
    ll eval(ll t) {
      return a * t + b;
    }
  };

  bool better(line l1, line l2, line l3) {
    return (l3.b - l1.b) * (l1.a - l2.a) < (l2.b - l1.b) * (l1.a - l3.a);
  }

  int top;
  vector<line> stk;

  void clr() {
    top = 0;
    stk.clear();
  }

  void push(ll a, ll b) {
    line ln = {a, b, ++top};
    while ((int) stk.size() >= 2 && better(stk[(int) stk.size() - 2], stk[(int) stk.size() - 1], ln)) {
      stk.pop_back();
    }
    stk.push_back(ln);
  }

  ll get(ll t) {
    if (stk.empty()) return -(ll) 1e18;
    int l = 1, r = (int) stk.size() - 1;
    ll ret = stk[0].eval(t);
    ret = max(ret, stk.back().eval(t));
    for (int it = 1; it <= 30; it++) {
      int m = (l + r) / 2;
      ll bef = stk[m - 1].eval(t), now = stk[m].eval(t);
      for (int j = m - 3; j <= m + 3; j++) {
        if (0 <= j && j < (int) stk.size()) ret = max(ret, stk[j].eval(t));
      }
      if (bef > now) {
        r = m;
      } else {
        l = m;
      }
    }
    return ret;
  }

};

const int N = (int) 2e5 + 7;
const int INF = (int) 1e18;
int n, a[N], s[N], ret, init;

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    init += a[i] * i;
  }
  hulk thanos;
  thanos.clr();
  for (int i = n; i >= 1; i--) {
    int inv = -a[i], cur = -INF;
    cur = thanos.get(inv);
    ret = max(ret, cur + s[i] - i * a[i]);
    thanos.push(-i, -s[i]);
  }
  thanos.clr();
  for (int i = 1; i <= n; i++) {
    int cur = thanos.get(a[i]);
    ret = max(ret, cur + s[i - 1] - i * a[i]);
    thanos.push(i, -s[i - 1]);
  }
  cout << init + ret << "\n";
  if (home && n == 6) {
    assert(init + ret == 6517);
  }
  return 0;
}
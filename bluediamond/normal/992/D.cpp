#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
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

const ull INF = (int) 2e18 + 7;

ull mul(ull a, ull b) {
  if (a == 0 || b == 0) return 0;
  ull c = a * b;
  if (c % b == 0 && c / b == a && c <= INF) return c;
  return INF;
}

const int N = (int) 2e5 + 7;
int n, k, a[N], urm[N], bound, tol[N], pre[N];

signed realMain() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    bound += a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  bound *= k;
  urm[n] = n + 1;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i + 1] == 1) {
      urm[i] = urm[i + 1];
    } else {
      urm[i] = i + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      tol[i] = tol[i - 1] + 1;
    }
  }
  assert(bound <= INF);
  int ret = 0;
  for (int st = 1; st <= n; st++) {
    int prod = 1, dr = st;
    vector<int> pivots, puk;
    while (dr && prod <= bound) {
      pivots.push_back(dr);
      puk.push_back(prod);
      prod = mul(prod, a[dr]);
      dr = urm[dr];
    }
    if ((int) pivots.size() > 100) {
      cout << st << " -> " << prod << " " << (int) pivots.size() << " " << (int) pivots.size() - n << "\n";
      for (int i = 0; i < (int) pivots.size(); i++) {
        cout << pivots[i] << " " << puk[i] << "\n";
       }
       return 0;
      for (auto &x : pivots) cout << x << " ";
        cout << "\n";
      exit(0);
    }
    assert((int) pivots.size() <= 100);
    prod = 1;
    for (int j = 0; j + 1 < (int) pivots.size(); j++) {
      int l = pivots[j], r = pivots[j + 1] - 1;
      prod = mul(prod, a[l]);
      ret += (prod % k == 0 && k * (pre[l] - pre[st - 1]) <= prod && prod <= (r - l + (pre[l] - pre[st - 1])) * k);
    }
  }
  cout << ret << "\n";
  return 0;
}
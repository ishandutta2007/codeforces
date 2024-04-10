#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
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

mt19937 rng((long long) (new char));
const int N = (int) 1e5 + 7;
int n, suf[N];

struct T {
  int x;
  int initial;
  int type;
};

bool initial_order(T a, T b) {
  return a.initial < b.initial;
}

T a[N];

void bkt(int p, int g1, int g2) {
  if (__gcd(g1, suf[p]) != 1 || __gcd(g2, suf[p]) != 1) {
    return;
  }
  if (g1 == 1 && g2 == 1) {
    sort(a + 1, a + n + 1, initial_order);
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << a[i].type << " ";
    }
    cout << "\n";
    exit(0);
  }
  if (p == n + 1) {
    return;
  }
  int ng1 = __gcd(g1, a[p].x), ng2 = __gcd(g2, a[p].x);
  if (ng1 == g1 && ng2 == g2) { /// boring, hope it would not happen to often, actually because of the random shuffle it can't happen to often because they are somewhat equally distributed around the middle
    bkt(p + 1, g1, g2);
    return;
  }
  if (ng1 != g1) {
    a[p].type = 1;
    bkt(p + 1, ng1, g2);
  }
  if (ng2 != g2) {
    a[p].type = 2;
    bkt(p + 1, g1, ng2);
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
    a[i].initial = i;
    a[i].type = 1;
  }
  shuffle(a + 1, a + n + 1, rng);
  for (int i = n; i >= 1; i--) {
    suf[i] = __gcd(suf[i + 1], a[i].x);
  }
  bkt(1, 0, 0);
  cout << "NO\n";

  return 0;
}
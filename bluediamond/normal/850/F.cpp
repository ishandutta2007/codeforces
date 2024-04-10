#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
//#define int ll
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

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = (int) 1e5 + 7;
int n, a[N], s, tab[N];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  tab[1] = dv(mul(s - 1, s - 1), s);
  /**
  2 * tab[i] = tab[i - 1] + tab[i + 1] + (s - 1) / (s - i)
  =>
  tab[i + 1] = 2 * tab[i] - tab[i - 1] - (s - 1) / (s - i)
  **/
  for (int i = 1; i < N; i++) {
    tab[i + 1] = add(mul(2, tab[i]), -add(tab[i - 1], dv(s - 1, s - i)));
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    ret = add(ret, tab[a[i]]);
  }
  cout << ret << "\n";
  return 0;
}
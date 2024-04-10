#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int long long
typedef long long ll;
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

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) a += M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

vector<int> zz(string s) {
  int n = (int) s.size();
  vector<int> ret(n, 0);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i <= r) ret[i] = min(ret[i - l], r - i + 1);
    while (i + ret[i] < n && s[i + ret[i]] == s[ret[i]]) ret[i]++;
    if (i + ret[i] - 1 > r) {
      r = i + ret[i] - 1;
      l = i;
    }
  }
  return ret;
}


const int N = 1000000 + 7;
int dp[N], sa, sl, sr, cl[N], cr[N], suf[N];
string a, l, r, la, ra;

bool smaller_r(int i, int len) {
  if (len < sr) return 1;
  if (len > sr) return 0;
  int com = cr[i];
  if (com >= len) return 1;
 /// cout << " = " << com << "\n";
  return a[i + com] < r[com];
}

bool smaller_l(int i, int len) {
  if (len < sl) return 1;
  if (len > sl) return 0;
  int com = cl[i];
  if (com >= len) return 0;
  return a[i + com] < l[com];
}

int find_last_brute(int i) {
  int j = i - 1;
  j = min(sa - 1, i + sr - 2);
  if (j + 1 < sa && smaller_r(i, j + 2 - i)) {
    j++;
  }
  return j;
}

int find_first_brute(int i) {
  int j = i - 1;
  j = min(sa, j + sl - 2);
  int s = 0;
  while (j < sa && smaller_l(i, j + 1 - i)) {
    j++;
    s++;
  }
  assert(s <= 3);
  if (j == sa) return N;
  return j;
}

signed realMain() {
  cin >> a >> l >> r;
  la = l + "$" + a;
  ra = r + "$" + a;
  vector<int> r1 = zz(la), r2 = zz(ra);
  sa = (int) a.size();
  sl = (int) l.size();
  sr = (int) r.size();
  for (int i = 0; i < sa; i++) {
    cl[i] = r1[i + sl + 1];
    cr[i] = r2[i + sr + 1];
  }
  bool zero = (l == "0");
  dp[sa] = 1;
  suf[sa] = 1;
  for (int i = sa - 1; i >= 0; i--) {
    if (a[i] == '0') {
      dp[i] = dp[i + 1] * zero;
      suf[i] = add(suf[i + 1], dp[i]);
      continue;
    }
    int first = find_first_brute(i);
    int last = find_last_brute(i);
    if (first <= last) {
      first++;
      last++;
      dp[i] = add(suf[first], -suf[last + 1]);
    }
    suf[i] = add(suf[i + 1], dp[i]);
  }
  cout << dp[0] << "\n";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
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
}**/

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

const int N = 4000 + 7;
const int RA = 80;
const int T = RA * RA * RA * RA + 77;
const int error = (int) 2e9;
int n, a[N], pre[N];
int memo[2 * T], y = T;
int ra;

int codif(int l, int r, int k, int player) {
  int deltix = (n - r) - (l - 1);
  deltix += k * (player == 2);
  return T * (player - 1) + l * ra * ra + deltix * ra + k;
}

int sum(int l, int r) {
  return pre[r] - pre[l - 1];
}

int get(int l, int r, int k, int player) {
  if (l + k - 1 > r) return 0;
  int x = codif(l, r, k, player);
  assert(x < 2 * T);
  if (memo[x] != error) return memo[x];
  int ret;
  if (player == 1) {
    ret = sum(l, l + k - 1) - get(l + k, r, k, 2);
    if (l + k <= r) ret = max(ret, sum(l, l + k) - get(l + k + 1, r, k + 1, 2));
  } else {
    ret = sum(r - k + 1, r) - get(l, r - k, k, 1);
    if (l + k <= r) ret = max(ret, sum(r - k, r) - get(l, r - k - 1, k + 1, 1));
  }
  memo[x] = ret;
  return ret;
}

signed realMain() {
  for (int i = 0; i < 2 * T; i++) memo[i] = error;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  ra = sqrt(2 * n);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  int val = get(1, n, 1, 1);
  cout << val << "\n";
  return 0;
}
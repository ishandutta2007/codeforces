#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = (int) 1e9 + 7;

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = (ll) r * a % mod;
    }
    a = (ll) a * a % mod;
    b /= 2;
  }
  return r;
}


const int M = mod;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 100000 + 7;
int f[N];

int c(int n, int k) {
  if (!(0 <= k && k <= n)) {
    cout << "0\n";
    exit(0);
  }
  return dv(f[n], mul(f[k], f[n - k]));
}

signed main() {
 //a ios::sync_with_stdio(0);
  //cin.tie(0);

  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);

 // freopen ("input", "r", stdin);

  int n, x, pos, big = 0, small = 0;
  cin >> n >> x >> pos;
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (pos == m) {
      l = m + 1;
      continue;
    }
    if (pos >= m + 1) {
      l = m + 1;
      small++;
    } else {
      big++;
      r = m;
    }
  }
  if (l - 1 != pos) {
    cout << "0\n";
    return 0;
  }
  /// small => <= x
  /// big => > x
  int sol = f[n - small - big - 1];
  sol = mul(sol, f[small]);
  sol = mul(sol, f[big]);
  int cnt_small = x - 1;
  int cnt_big = n - x;
  sol = mul(sol, c(cnt_small, small));
  sol = mul(sol, c(cnt_big, big));
  cout << sol << "\n";
}
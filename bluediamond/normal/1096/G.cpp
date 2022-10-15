#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

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

const int mod = M;
const int root = 31;
const int root_pw = 1 << 23;

void fft(vector<int> &a, bool inv) {
  int lol = inv ? dv(1, root) : root;
  int n = (int) a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j)
      swap(a[i], a[j]);
  }
  for (int l = 2; l <= n; l *= 2) {
    int mult = lol;
    for (int j = l; j < root_pw; j *= 2) mult = mul(mult, mult);
    for (int i = 0; i < n; i += l) {
      int now = 1;
      for (int j = 0; j < l / 2; j++) {
        int u = a[i+j], v = (int)(1LL * a[i+j+l/2] * now % mod);
        a[i+j] = u + v < mod ? u + v : u + v - mod;
        a[i+j+l/2] = u - v >= 0 ? u - v : u - v + mod;
        now = (int)(1LL * now * mult % mod);
      }
    }
  }
  if (inv) {
    int invn = dv(1, n);
    for (auto &x : a) x = mul(x, invn);
  }
}

vector<int> mult(vector<int> a, vector<int> b) {
  int n = 1;
  while (n < (int) a.size() + (int) b.size()) {
    n *= 2;
  }
  a.resize(n);
  b.resize(n);
  fft(a, 0);
  fft(b, 0);
  for (int i = 0; i < n; i++) {
    a[i] = mul(a[i], b[i]);
  }
  fft(a, 1);
  return a;
}

int main() {
  int n, k;
  cin >> n >> k;
  n /= 2;
  vector<int> ret(10, 0), base(10, 0);
  for (int i = 1; i <= k; i++) {
    int digit;
    cin >> digit;
    base[digit] = 1;
  }
  ret[0] = 1;
  while (n) {
    if (n & 1) {
      ret = mult(ret, base);
    }
    n /= 2;
    base = mult(base, base);
  }
  int sol = 0;
  for (auto &x : ret) {
    sol = add(sol, mul(x, x));
  }
  cout << sol << "\n";
}
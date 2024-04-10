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

unsigned int n, a, b, c, d, ret;

unsigned int f(unsigned int x) {
  return a * x * x * x + b * x * x + c * x + d;
}

vector<unsigned int> primes;

bool prim(unsigned int x) {
  if (x <= 1) {
    return 0;
  }
  for (unsigned int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

bitset<(int) 1e8 + 7> bt;

void ciurulescu(unsigned int l, unsigned int r) {
  if (l < 2) l = 2;
  if (l > r) {
    return;
  }
  for (int j = l; j <= r; j++) {
    bt[j - l] = 1;
  }
  for (auto &x : primes) {
    int go = r / x * x;
    for (unsigned int j = go; j >= l; j -= x) {
      bt[j - l] = 0;
    }
    if (l <= x && x <= r) {
      bt[x - l] = 1;
    }
  }
  for (int i = l; i <= r; i++) {
    if (bt[i - l]) {
      unsigned int func = f(i), times = 0, x = n;
      while (x) {
        x /= i;
        times += x;
      }
      ret += func * times;
    }
  }
}

signed realMain() {
  cin >> n >> a >> b >> c >> d;
  for (int i = 1; i * i <= (int) 3e8; i++) {
    if (prim(i)) {
      primes.push_back(i);
    }
  }
  unsigned int sz = n / 3;
  ciurulescu(2, sz);
  ciurulescu(sz + 1, 2 * sz);
  ciurulescu(2 * sz + 1, n);
  cout << ret << "\n";
  return 0;
}
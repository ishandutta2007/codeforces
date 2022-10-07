#include <bits/stdc++.h>

#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

typedef long long ll;
const int N = 1005;

ll C0(int n) { return 1; }
ll C1(int n) { return n; }
ll C2(int n) { return 1ll * n * (n - 1) / 2; }
ll C3(int n) { return 1ll * n * (n - 1) / 2 * (n - 2) / 3; }

int n;
double p;

int main() {
  std::cin >> n >> p;
  for (int i = 0; i <= n; ++i) {
    double p0 = C3(i) * 1. / C3(n), p1 = C2(i) * 1. / C3(n) * C1(n - i), p2 = C2(n - i) * 1. / C3(n) * C1(i);
    double E = p0 + p1 + p2 * 1. / 2;
    if (E >= p) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  return 0;
}
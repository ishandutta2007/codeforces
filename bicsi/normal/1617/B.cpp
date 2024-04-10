#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  while (b) {
    int r = a % b; a = b; b = r;
  }
  return a;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int mul = 1;
    while (n % 2 == 0 && n >= 20) {
      n /= 2;
      mul *= 2;
    }
    for (int a = 1; a <= n; ++a) {
      for (int b = n - 2 * a - 1; a + b <= n; ++b) {
        int c = gcd(a, b);
        if (c == a || c == b) continue;
        if (a + b + c == n) {
          cout << mul * a << " " << mul * b << " " << mul * c << '\n';
          goto done;
        }
      }
    }
done:;
  }
}
#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();

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

int lcm(int a, int b) {
  return a * b / __gcd(a, b);
}

int lcm(int a, int b, int c) {
  return lcm(a, lcm(b, c));
}

void brute(int n) {
  for (int a = 1; a <= n; a++) {
    for (int b = a; a + b <= n; b++) {
      int c = n - (a + b);
      if (c < b) {
        continue;
      }
      int l = lcm(a, b, c);
      if (l <= n / 2) {
        if (n % 4 == 2) {
          assert(a == 2);
          assert(b == n / 2 - 1);
          assert(c == n / 2 - 1);
         /// continue;
        }
        /**if (n % 4 == 0) {

          assert(a == n / 4);
          assert(b == n / 4);
          assert(c == n / 2);
        }**/
        if (n % 2 == 1) {
          assert(a == 1);
          assert(b == n / 2);
          assert(c == n / 2);
        }

        cout << n << " : " << a << " " << b << " " << c << "\n";
        return;
      }
    }
  }
}

signed realMain() {
  for (int n = 3; n <= 100; n++) {
//    brute(n);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    while (k > 3) {
      k--;
      n--;
      cout << 1 << " ";
    }
    if (n % 2 == 1) {
      cout << n / 2 << " " << n / 2 << " " << 1 << "\n";
      continue;
    }
    if (n % 4 == 0) {
      cout << n / 4 << " " << n / 4 << " " << n / 2 << "\n";
      continue;
    }
    cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << "\n";
  }
}
#include <bits/stdc++.h>

using namespace std;

const int N = 3000 + 7;
int n;
int s;
int a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s += a[i];
    }
    for (int k = n; k >= 1; k--) {
      if (s % k == 0) {
        bool ok = 1;
        int x = s / k, now = 0;
        for (int i = 1; i <= n; i++) {
          now += a[i];
          if (now > x) {
            ok = 0;
            break;
          }
          if (now == x) {
            now = 0;
          }
        }
        if (ok) {
          cout << n - k << "\n";
          break;
        }
      }
    }
  }
}
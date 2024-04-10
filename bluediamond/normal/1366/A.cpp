#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }
    int d = a - b;
    if (b - d < 0) {
      cout << b << "\n";
    } else {
      a -= 2 * d;
      b -= d;
      d += (a / 3) * 2;
      if (a % 3 == 2) {
        d++;
      }
      cout << d << "\n";
    }
  }
  return 0;
}
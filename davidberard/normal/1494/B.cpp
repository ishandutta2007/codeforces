#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool check(int n, int b1, int b2, int goal) {
  if (b1 + b2 > goal) {
    return false;
  }
  if (n-2 + b1 + b2 < goal) {
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    bool good = false;
    for (int i=0; i<=15; ++i) {
      int x[4];
      for (int j=0; j<4; ++j) {
        x[j] = !!(i&(1<<j));
      }
      bool t = true;
      t &= check(n, x[0], x[1], u);
      t &= check(n, x[1], x[2], r);
      t &= check(n, x[2], x[3], d);
      t &= check(n, x[3], x[0], l);
      good |= t;
    }
    cout << (good ? "YES" : "NO") << "\n";
  }
  return 0;
}
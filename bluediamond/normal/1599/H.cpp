#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int inf = (int) 1e9;

signed main() {

  cout << "? 1 1" << endl;
  int a;
  cin >> a;
  int l = 1, r = inf, ff = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    int am;
    cout << "? " << 1 << " " << m << endl;
    cin >> am;
    if (a - am == m - 1) {
      ff = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  int c1 = ff, r1 = a + 2 - c1;


  cout << "? 1 1000000000" << endl;
  int b;
  cin >> b;

  int c2 = (r1 - 1 + inf - b);

  cout << "? 1000000000 1" << endl;
  cin >> b;
  int r2 = inf + (c1 - 1) - b;

  cout << "! " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;

  return 0;
}
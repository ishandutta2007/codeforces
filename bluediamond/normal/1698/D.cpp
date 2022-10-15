/// 486 -> 487
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int get(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int sol = 0;
  for (int i = l; i <= r; i++) {
    int x;
    cin >> x;
    sol += (l <= x && x <= r);
  }
  return sol;
}

int f(int tl, int tr) {
  if (tl == tr) {
    return tl;
  }
  int tm = (tl + tr) / 2;
  int x = get(tl, tm);
  if (x % 2 == 1) {
    return f(tl, tm);
  } else {
    return f(tm + 1, tr);
  }
}

signed main() {
  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    int sol = f(1, n);
    cout << "! " << sol << endl;
  }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll res = 1;
  bool u = false;
  ll k = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x and u) {
      res *= k;
      k = 0;
    }
    if (x) u = true;
    if (u) ++k;
  }
  if (!u) {
    cout << 0 << endl;
    return 0;
  }
  cout << res << endl;
}
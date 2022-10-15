#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int sum(int x) {
  return x * (x + 1) / 2;
}

int sum(int l, int r) {
  return sum(r) - sum(l - 1);
}

bool ok(int x, int k) {
  int l = 1, r = k, sol = -1;
  while (l <= r) {
    int use = (l + r) / 2;
    int mn = sum(1, use) + use;
    if (mn <= x + k) {
      sol = use;
      l = use + 1;
    } else {
      r = use - 1;
    }
  }
  if (sol == -1) {
    return 0;
  }
  int use = sol;
  int mn = sum(1, use) + use;
  int mx = sum(k - use + 1, k) + use;
  assert(mn <= x + k);
  return (x + k <= mx);
}

int f(int x) {
  int k = 1;
  while (!ok(x, k)) {
    k++;
  }
  return k;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << f(x) << "\n";
  }


}
#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 100 + 7;

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k;
    if (k > (n - 1) / 2) {
      cout << "-1\n";
      continue;
    }
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        cout << l++ << " ";
      } else {
        if (i / 2 <= k) {
          cout << r-- << " ";
        } else {
          cout << l++ << " ";
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
/**
2 -> 0
3 -> 1
4 -> 1
5 -> 2
6 -> 2

x -> (x-1)/2
**/
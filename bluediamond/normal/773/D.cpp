#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
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

const int N = 2000 + 7;
int n, d[N][N], mn = (int) 1e9 + 7, kek[N];
bool steve[N];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> d[i][j];
      d[j][i] = d[i][j];
      mn = min(mn, d[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) d[i][j] -= mn;
    }
  }
  for (int i = 1; i <= n; i++) {
    kek[i] = (int) 1e9;
    for (int j = 1; j <= n; j++) {
      if (i != j) kek[i] = min(kek[i], d[i][j]);
    }
    kek[i] *= 2;
  }
  for (int step = 1; step <= n; step++) {
    int j = 0;
    for (int i = 1; i <= n; i++) {
      if (!steve[i]) {
        if (!j) j = i;
        else if (kek[i] < kek[j]) j = i;
      }
    }
    assert(j);
    steve[j] = 1;
    for (int i = 1; i <= n; i++) kek[i] = min(kek[i], kek[j] + d[i][j]);
  }
  for (int i = 1; i <= n; i++) cout << kek[i] + mn * (n - 1) << "\n";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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
}
**/
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

const int N = (int) 1e5 + 7;
const int D = 10;
const ld INF = (ld) 1e18;
int n, want, a[N];
ld best[N][D];
bool good[N][D];
int what[N][D];

signed realMain() {
  cin >> n >> want;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  good[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int d = 0; d <= 9; d++) {
      if (good[i - 1][d]) {
        good[i][d] = 1;
        best[i][d] = best[i - 1][d];
        what[i][d] = -1;
      }
    }
    /// mult
    ld val = log(a[i]);
    for (int d = 0; d <= 9; d++) {
      if (!good[i - 1][d]) continue;
      int nd = d * a[i] % 10;
      if (!good[i][nd]) {
        good[i][nd] = 1;
        best[i][nd] = best[i - 1][d] + val;
        what[i][nd] = d;
      } else {
        ld relax = best[i - 1][d] + val;
        if (relax > best[i][nd]) {
          best[i][nd] = relax;
          good[i][nd] = 1;
          what[i][nd] = d;
        }
      }
    }
  }
  if (!good[n][want]) {
    cout << "-1\n";
    return 0;
  }
  int cur = n, dg = want;
  vector<int> ret;
  while (cur) {
    assert(good[cur][dg]);
    if (what[cur][dg] == -1) {
      cur--;
      continue;
    }
    ret.push_back(a[cur]);
    dg = what[cur][dg];
    cur--;
  }
  if (ret.empty()) {
    cout << "-1\n";
    return 0;
  }
  cout << (int) ret.size() << "\n";
  for (auto &x : ret) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
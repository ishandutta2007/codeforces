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

const int N = 1000 + 7;
int n, r[N], c[N], nowr[N], nowc[N], needr[N], needc[N];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nowr[i];
    needr[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> nowc[i];
    needc[i] = i;
  }
  vector<vector<int>> ret;
  for (int i = 1; i <= n; i++) {
    /// I want to force i to go where he need to go
    if (nowr[i] == needr[i] && nowc[i] == needc[i]) continue;
    /// on what row is the guy that needs to come here?
    int rguy = -1;
    for (int r = i; r <= n; r++) {
      if (nowr[r] == needr[i]) {
        rguy = r;
      }
    }
    /// on what col is the guy that needs to come here?
    int cguy = -1;
    for (int c = i; c <= n; c++) {
      if (nowc[c] == needc[i]) {
        cguy = c;
      }
    }
    /// done
    assert(rguy != -1);
    assert(cguy != -1);
    ret.push_back({rguy, i, i, cguy});
    swap(nowr[rguy], nowr[i]);
    swap(nowc[cguy], nowc[i]);
  }
  cout << (int) ret.size() << "\n";
  for (auto &v : ret) {
    for (auto &x : v) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
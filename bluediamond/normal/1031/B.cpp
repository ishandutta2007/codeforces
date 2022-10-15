#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

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

const int N = (int) 1e5 + 7;
int n, what[N][4], a[N], b[N];
bool ok[N][4];

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) cin >> b[i];
  ok[1][0] = ok[1][1] = ok[1][2] = ok[1][3] = 1;
  for (int i = 1; i < n; i++) {
    for (int x = 0; x < 4; x++) {
      if (ok[i][x]) {
        for (int y = 0; y < 4; y++) {
          if (!ok[i + 1][y]) {
            if ((x | y) == a[i]) {
              if ((x & y) == b[i]) {
                ok[i + 1][y] = 1;
                what[i + 1][y] = x;
              }
            }
          }
        }
      }
    }
  }
  int x = -1;
  for (int i = 0; i < 4; i++) {
    if (ok[n][i]) {
      x = i;
      break;
    }
  }
  if (x == -1) {
    cout << "NO\n";
    return 0;
  }
  vector<int> sol;
  while (n) {
    sol.push_back(x);
    x = what[n--][x];
  }
  reverse(sol.begin(), sol.end());
  cout << "YES\n";
  for (auto &x : sol) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
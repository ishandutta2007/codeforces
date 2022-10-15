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

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int D = 10;
const int N = (int) 2e5 + 7;
int n, lee[D][N];

signed realMain() {
  for (int d = 0; d <= 9; d++) {
    lee[d][1] = 1;
  }
  for (int i = 2; i < N; i++) {
    for (int d = 0; d < 9; d++) {
      lee[d][i] = lee[d + 1][i - 1];
    }
    lee[9][i] = add(lee[0][i - 1], lee[1][i - 1]);
  }
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n, ret = 0;
    cin >> s >> n;
    for (auto &ch : s) {
      int x = ch - '0';
      ret = add(ret, lee[x][n + 1]);
    }
    cout << ret << "\n";
  }
  return 0;
}
/**


**/
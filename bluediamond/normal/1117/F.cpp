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

const int N = 17;
int len, n, consec[N][N], ok[1 << N], f[N], tot[1 << N], rl[1 << N], last[N];
string s;
bool okp[1 << N];
bitset<1 << N> bad[N][N];

signed realMain() {
  cin >> len >> n >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> consec[i][j];
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    ok[i] = 1;
  }
  for (int i = 0; i < len; i++) {
    int x = s[i] - 'a';
    f[x]++;
  }
  for (int i = 0; i < n; i++) {
    last[i] = -1;
  }
  for (int i = 0; i < len; i++) {
    int x = s[i] - 'a';
    for (int y = 0; y < n; y++) {
      if (last[y] != -1) {
        if (consec[x][y]) continue;
        int pos = last[y];
        if (pos < last[x]) {
          continue;
        }
        int mid = 0;
        for (int z = 0; z < n; z++) {
          if (z == x || z == y) continue;
          if (pos < last[z]) {
            mid |= (1 << z);
          }
        }
        /// all that have also x also y and are sub-masks of ... are bad
        mid = (1 << n) - 1 - mid;
        assert(mid & (1 << x));
        assert(mid & (1 << y));
        bad[x][y][mid] = 1;
      }
    }
    last[x] = i;
    ///cout << x << " " << y << " : " << consec[x][y] << "\n";
    ///ok[(1 << x) + (1 << y)] &= consec[x][y];
  }
  for (int i = 0; i < n; i++) {
    tot[1 << i] = f[i];
  }
  for (int i = 1; i < (1 << n); i++) {
    int j = i & (-i);
    tot[i] = tot[j] + tot[i ^ j];
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (consec[x][y]) continue;
      for (int bit = 0; bit < n; bit++) {
        if (bit == x || bit == y) continue;
        for (int i = 0; i < (1 << n); i++) {

          if (i & (1 << bit) && bad[x][y][i]) {
            bad[x][y][i ^ (1 << bit)] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        ok[i] &= !bad[x][y][i];
      }
    }
  }
  rl[(1 << n) - 1] = 1;
  for (int i = (1 << n) - 1; i >= 0; i--) {
    rl[i] &= ok[i];
    if (!rl[i]) continue;
    for (int bit = 0; bit < n; bit++) {
      if (i & (1 << bit)) {
       // cout << (char) ('a' + bit) << " ";
      }
    }
   // cout << "\n";
    for (int bit = 0; bit < n; bit++) {
      if (i & (1 << bit)) {
        rl[i ^ (1 << bit)] |= 1;
      }
    }
  }
  int ret = (int) 1e9;
  for (int i = 0; i < (1 << n); i++) {
    if (rl[i]) {
      ret = min(ret, tot[i]);
    }
  }
  cout << ret << "\n";
  return 0;
}
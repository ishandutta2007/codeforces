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

const int N = 2000 + 7;
int n, k, mn[N][N], best = 0, type[N][N];
pair<int, int> to[N];
string s[N];
string ret = "{";

signed realMain() {
  cin >> n >> k;
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) mn[i][j] = (int) 1e9, type[i][j] = (int) 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "#" + s[i];
  }
  mn[0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + (s[i][j] != 'a');
    }
  }
  type[n][n] = 1;
  for (int t = 2 * n - 1; t >= 1; t--) {
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
      int j = t - i;
      if (1 <= j && j <= n) {
        to[i] = {s[i][j], min(type[i + 1][j], type[i][j + 1])};
        mp[to[i]] = 0;
      }
    }
    int ind = 0;
    for (auto &it : mp) {
      it.second = ++ind;
    }
    for (int i = 1; i <= n; i++) {
      int j = t - i;
      if (1 <= j && j <= n) {
        type[i][j] = mp[to[i]];
      }
    }
  }
  for (int t = 1; t <= 2 * n; t++) {
    for (int i = 1; i <= n; i++) {
      int j = t - i;
      if (1 <= j && j <= n) {
        if (mn[i][j] <= k) {
          best = t;
        }
      }
    }
  }
  int t = best;
  for (int i = 1; i <= n; i++) {
    int j = t - i;
    if (1 <= j && j <= n) {
      if (mn[i][j] <= k) {
        string cur;
        for (int k = 1; k < t; k++) {
          cur += "a";
        }
        int i2 = i, j2 = j;
        while (i2 != n || j2 != n) {
          if (i2 == n) {
            j2++;
          } else {
            if (j2 == n) {
              i2++;
            } else {
              if (type[i2 + 1][j2] < type[i2][j2 + 1]) {
                i2++;
              } else {
                j2++;
              }
            }
          }
          cur += s[i2][j2];
        }
        ret = min(ret, cur);
      }
    }
  }
  if (ret == "{") {
    ret = s[1][1];
    int i2 = 1, j2 = 1;
    while (i2 != n || j2 != n) {
      if (type[i2 + 1][j2] < type[i2][j2 + 1]) {
        i2++;
      } else {
        j2++;
      }
      ret += s[i2][j2];
    }
  }
  cout << ret << "\n";
  return 0;
}
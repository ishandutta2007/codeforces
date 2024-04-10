#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();


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

struct T {
  int r1, c1;
  int r2, c2;
  int x;
};

const int N = (int) 1e3 + 7;
const int K = (int) 3e5 + 7;
int n, m, k, a[N][N], coef[N][N], nr[N][N][26], tab[N][N], tval[N][N][26];

int scoef(int r1, int c1, int r2, int c2) {
  return coef[r2][c2] - coef[r1 - 1][c2] - coef[r2][c1 - 1] + coef[r1 - 1][c1 - 1];
}

int stval(int y, int r1, int c1, int r2, int c2) {
  return tval[r2][c2][y] - tval[r1 - 1][c2][y] - tval[r2][c1 - 1][y] + tval[r1 - 1][c1 - 1][y];
}

signed realMain() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= m; j++) {
      a[i][j] = str[j - 1] - 'a';
    }
  }
  vector<T> v(k);
  for (auto &i : v) {
    string str;
    cin >> i.r1 >> i.c1 >> i.r2 >> i.c2 >> str;
    i.x = str[0] - 'a';
  }
  for (auto &it : v) {
    nr[it.r1][it.c1][it.x]++;
    nr[it.r2 + 1][it.c1][it.x]--;
    nr[it.r1][it.c2 + 1][it.x]--;
    nr[it.r2 + 1][it.c2 + 1][it.x]++;

    tab[it.r1][it.c1]--;
    tab[it.r2 + 1][it.c1]++;
    tab[it.r1][it.c2 + 1]++;
    tab[it.r2 + 1][it.c2 + 1]--;
  }
  for (int x = 0; x < 26; x++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        nr[i][j][x] += nr[i - 1][j][x];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tab[i][j] += tab[i - 1][j];
    }
  }
  for (int x = 0; x < 26; x++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        nr[i][j][x] += nr[i][j - 1][x];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tab[i][j] += tab[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tab[i][j] += k;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int x = 0; x < 26; x++) {
        coef[i][j] += abs(a[i][j] - x) * nr[i][j][x];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    for (int j = 1; j <= m; j++) {
      cur += coef[i][j];
      coef[i][j] = coef[i - 1][j] + cur;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tval[i][j][a[i][j]] += tab[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int x = 0; x < 26; x++) {
        tval[i][j][x] += nr[i][j][x];
      }
    }
  }
  for (int y = 0; y < 26; y++) {
    for (int i = 1; i <= n; i++) {
      int cur = 0;
      for (int j = 1; j <= m; j++) {
        cur += tval[i][j][y];
        tval[i][j][y] = cur + tval[i - 1][j][y];
      }
    }
  }
  int mn = (int) 1e18;
  for (auto &itrr : v) {
    int r1 = itrr.r1;
    int c1 = itrr.c1;
    int r2 = itrr.r2;
    int c2 = itrr.c2;
    int x = itrr.x;
    int ret = scoef(1, 1, n, m) - scoef(r1, c1, r2, c2);
    for (int y = 0; y < 26; y++) {
      ret += abs(x - y) * stval(y, r1, c1, r2, c2);
    }
    if (home) {
      cout << " --> " << ret << "\n";
    }
    mn = min(mn, ret);
  }
  cout << mn << "\n";
  if (home) {
    assert(mn == 505);
  }
  return 0;
}
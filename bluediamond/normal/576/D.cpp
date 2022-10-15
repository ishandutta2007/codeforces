#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll

signed realMain();

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

const int INF = (int) 1e9 + 1000;
const int N = 150 + 7;
int n, m;

struct E {
  int a, b, w;
};

bool operator < (E f, E s) {
  return f.w < s.w;
}

bitset<N> f[N];
bitset<N> inv[N];

void mul(bitset<N> a[N], bitset<N> b[N], bitset<N> c[N]) {
  for (int i = 1; i <= n; i++) {
    inv[i] = 0;
    f[i] = 0;
    for (int j = 1; j <= n; j++) {
      if (a[i][j]) f[i][j] = 1;
      if (b[j][i]) inv[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      c[i][j] = (f[i] & inv[j]).any();
    }
  }
}

bitset<N> cur, ret;

void mul(bitset<N> a[N]) {
  ret = 0;
  for (int i = 1; i <= n; i++) {
    if (cur[i]) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j]) ret[j] = 1;
      }
    }
  }
  cur = ret;
}

int d[N][N];

signed realMain() {
  cin >> n >> m;
  vector<E> e(m);
  for (auto &x : e) {
    cin >> x.a >> x.b >> x.w;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = INF;
    }
    d[i][i] = 0;
  }
  e.push_back({N, 1, 0});
  e.push_back({N, 1, INF});
  sort(e.begin(), e.end());
  bitset<N> b[N];
  cur[1] = 1;
  int ret = INF;
  for (int it = 0; it + 1 < (int) e.size(); it++) {
    int acum = e[it].w, urm = e[it + 1].w;
    int x = e[it].a, y = e[it].b;
    if (x != N) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          d[i][j] = min(d[i][j], d[i][x] + 1 + d[y][j]);
        }
      }
      b[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (cur[i]) {
        ret = min(ret, acum + d[i][n]);
      }
    }
    bitset<N> lol[N] = b;
    int dif = urm - acum;
    while (dif) {
      if (dif & 1) {
        mul(lol);
      }
      mul(lol, lol, lol);
      dif /= 2;
    }
  }
  if (ret == INF) {
    cout << "Impossible\n";
  } else {
    cout << ret << "\n";
  }
  return 0;
}
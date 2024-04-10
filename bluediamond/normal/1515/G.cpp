#include <bits/stdc++.h>
///#pragma GCC target("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")


/**
#pragma GCC opimize("O3")
#pragma GCC opimization ("unroll-loops")

**/
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

struct edge {
  int to;
  int len;
};

const int N = (int) 2e5 + 7;
int n, m, cur, col[N], way[N], gg[N];
bool vis[N];
vector<edge> g[N], ginv[N];
vector<int> ord;

void trav(int a) {
  vis[a] = 1;
  for (auto &it : g[a]) {
    if (!vis[it.to]) {
      trav(it.to);
    }
  }
  ord.push_back(a);
}

void trav_inv(int a) {
  col[a] = cur;
  for (auto &it : ginv[a]) {
    if (col[it.to] == 0) {
      way[it.to] = way[a] + it.len;
      trav_inv(it.to);
    } else {
      int len = way[a] - way[it.to] + it.len;
      len = abs(len);
      if (col[a] == col[it.to]) {
        gg[col[a]] = __gcd(gg[col[a]], len);
      }
    }
  }
}

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    g[a].push_back({b, l});
    ginv[b].push_back({a, l});
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      trav(i);
    }
  }
  reverse(ord.begin(), ord.end());
  for (auto &i : ord) {
    if (!col[i]) {
      col[i] = ++cur;
      trav_inv(i);
    }
  }
  if (home) {
    for (int i = 1; i <= n; i++) {
      cout << col[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= cur; i++) {
      cout << ": " << "gg[" << i << "] = " << gg[i] << "\n";
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int a, mod, rest;
    cin >> a >> mod >> rest;
    a = col[a];
    if (rest == 0) {
      cout << "YES\n";
      continue;
    }
    if (mod % __gcd(rest, gg[a]) == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
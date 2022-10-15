#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC optimize("O3")
///#pragma GCC optimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
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

const int N = (int) 2e5 + 7;
const int INF = (int) 1e9;
int n, q, digit[N];
string s;

struct T {
  int ret[5][5];
  T() {
    for (int i = 0; i < 5; i++) {
      for (int j = i; j < 5; j++) {
        ret[i][j] = INF;
      }
    }
  }
};

T tree[4 * N];

T operator + (T a, T b) {
  T c;
  for (int i = 0; i < 5; i++) {
    for (int j = i; j < 5; j++) {
      for (int k = i; k <= j; k++) {
        c.ret[i][j] = min(c.ret[i][j], a.ret[i][k] + b.ret[k][j]);
      }
    }
  }
  return c;
}

vector<int> edges = {2, 0, 1, 7};

void build(int v, int tl, int tr) {
  if (tl == tr) {
    for (int i = 0; i < 5; i++) {
      if (i < 4 && digit[tl] == edges[i]) {
        tree[v].ret[i][i] = 1;
        tree[v].ret[i][i + 1] = 0;
      } else {
        if ((i == 3 || i == 4) && digit[tl] == 6) {
          tree[v].ret[i][i] = 1;
        } else {
          tree[v].ret[i][i] = 0;
        }
      }
    }
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}

T rec(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    assert(0);
  }
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) {
    return rec(2 * v, tl, tm, l, r);
  }
  if (tm + 1 <= l) {
    return rec(2 * v + 1, tm + 1, tr, l, r);
  }
  return rec(2 * v, tl, tm, l, r) + rec(2 * v + 1, tm + 1, tr, l, r);
}

/**

cand sunt trecut de nodul 3 trebuie sa sterg orice 6

**/

signed realMain() {
  cin >> n >> q >> s;
  for (int i = 1; i <= n; i++) {
    digit[i] = s[i - 1] - '0';
  }
  build(1, 1, n);
  while (q--) {
    int l, r;
    cin >> l >> r;
    T a = rec(1, 1, n, l, r);
    if (a.ret[0][4] == INF) {
      cout << "-1\n";
    } else {
      cout << a.ret[0][4] << "\n";
    }
  }
  return 0;
}
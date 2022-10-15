#include <bits/stdc++.h>; iron man

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200000 + 7;
const int K = 10;
int n, q, k, cnt[4 * N][K][K];
string s;
char lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v] == 'X') return;
  int x = lazy[v] - 'a';
  lazy[v] = 'X';
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      cnt[v][i][j] = 0;
    }
  }
  cnt[v][x][x] = tr - tl;
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    s[tm - 1] = s[tm] = s[tl - 1] = s[tr - 1] = 'a' + x;
    lazy[2 * v] = lazy[2 * v + 1] = 'a' + x;
  } else {
    s[tl - 1] = 'a' + x;
  }
}

void join(int v, int tm) {

  for (int a = 0; a < k; a++) {
    for (int b = 0; b < k; b++) {
      cnt[v][a][b] = cnt[2 * v][a][b] + cnt[2 * v + 1][a][b];
    }
  }
  cnt[v][s[tm - 1] - 'a'][s[tm] - 'a']++;
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  join(v, tm);
}

void transf(int v, int tl, int tr, int l, int r, char ch) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] = ch;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  transf(2 * v, tl, tm, l, r, ch);
  transf(2 * v + 1, tm + 1, tr, l, r, ch);
  join(v, tm);
}

int pos[K];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < 4 * N; i++) {
    lazy[i] = 'X';
  }

  cin >> n >> q >> k >> s;
  build(1, 1, n);

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      string s;
      cin >> l >> r >> s;
      transf(1, 1, n, l, r, s[0]);
    } else {
      string t;
      cin >> t;
      push(1, 1, n);
      for (int j = 0; j < k; j++) {
        pos[j] = -1;
      }
      assert((int) t.size() == k);
      for (int j = 0; j < (int) t.size(); j++) {
        pos[t[j] - 'a'] = j;
      }
      int sol = 1;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          if (pos[i] >= pos[j]) {
            sol += cnt[1][i][j];
          }
        }
      }
      cout << sol << "\n";
    }
  }

  return 0;
}
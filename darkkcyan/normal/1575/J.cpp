#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int maxn = 1010;

int n, m, k;
int board[maxn][maxn];

struct cell {
  int r, c;
  cell(int x): r(x / m), c(x % m) {}
  cell(int r_, int c_): r(r_), c(c_) {}
  operator int() const {
    return r * m + c;
  }
};

int par[maxn * maxn];
int find_set(int u) {
  return par[u] < 0 ? u : par[u] = find_set(par[u]);
}

void join_to(int from, int to) {
  from = find_set(from);
  to = find_set(to);
  if (from == to) return ;
  par[to] += par[from];
  par[from] = to;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int f = 0; f < m; ++f) {
      cin >> board[i][f];
    }
  }

  for (int i = 0; i < n * m + m; ++i) {
    par[i] = -1;
  }

  for (int i = 0; i < n; ++i) {
    for (int f = 0; f < m; ++f) {
      if (board[i][f] == 2) {
        join_to(cell(i, f), cell(i + 1, f));
      }
    }
  }

  while (k--) {
    int col; cin >> col;
    cell cur(0, col - 1);
    while (cur.r < n) {
      cell nxt = find_set(cur);
      cur = nxt;
      if (nxt.r == n) break;
      if (board[nxt.r][nxt.c] == 1) {
        cur.c ++;
      } else {
        cur.c --;
      }
      board[nxt.r][nxt.c] = 2;
      join_to(nxt, cell(nxt.r + 1, nxt.c));
    }
    cout << cur.c + 1 << ' ';
  }

  return 0;
}
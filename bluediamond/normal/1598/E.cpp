#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int ll

const int DIM = 1000 + 7;
int n, m, q, dp[DIM][DIM], sol;
bool active[DIM][DIM];

int goright[DIM][DIM];
int godown[DIM][DIM];

void upd(int r, int c) {
  if (active[r][c]) {
    sol -= (goright[r][c] + godown[r][c] - 1);
    goright[r][c] = 1 + active[r][c + 1] * (godown[r][c + 1]);
    godown[r][c] = 1 + active[r + 1][c] * (goright[r + 1][c]);
    sol += goright[r][c] + godown[r][c] - 1;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  ///freopen ("input", "r", stdin);


  cin >> n >> m >> q;

  for (int r = n; r >= 1; r--) {
    for (int c = m; c >= 1; c--) {
      goright[r][c] = 1;
      active[r][c] = 1;
      upd(r, c);
    }
  }
  /**cout << sol << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << goright[i][j] + godown[i][j] - 1 << " ";
    }
    cout << "\n";
  }**/

  for (int it = 1; it <= q; it++) {
    int r, c;
    cin >> r >> c;
    if (active[r][c]) {
      sol -= (goright[r][c] + godown[r][c] - 1);
    } else {
      goright[r][c] = godown[r][c] = 0;
      goright[r][c] = 1;
    }
    active[r][c] ^= 1;

    vector<pair<int, int>> path;
    path.push_back({r, c});
    int i = r - 1, j = c - 1;
    while (i >= 1 && j >= 1) {
      path.push_back({i, j + 1});
      path.push_back({i + 1, j});
      path.push_back({i, j});
      i--;
      j--;
    }
    if (i >= 1 && j + 1 >= 1) path.push_back({i, j + 1});
    if (i + 1 >= 1 && j >= 1) path.push_back({i + 1, j});
    for (auto &it : path) {
    //  cout << it.first << " " << it.second << "\n";
      upd(it.first, it.second);
    }
    cout << sol << "\n";


   // vector<pair<int, int>> so = a; sort(so.begin(), so.end());
   // assert(so == a);


  }


  return 0;
}
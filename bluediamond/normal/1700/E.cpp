#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int long long

void print(vector<vector<int>> a) {
  for (auto &v : a) {
    for (auto &x : v) {
      cout << x << " ";
    }
    cout << "\n";
  }
}


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  int dr[] = {-1, 0, 1, 0};
  int dc[] = {0, 1, 0, -1};

  function<bool(int, int, vector<vector<int>>)> is_all_ok = [&](int n, int m, vector<vector<int>> a) {

    assert((int) a.size() == n);
    for (int i = 0; i < n; i++) {
      assert((int) a[i].size() == m);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0) {
          continue;
        }

        bool found = 0;
        for (int k = 0; k < 4; k++) {
          int r = i + dr[k], c = j + dc[k];
          if (0 <= r && 0 <= c && r < n && c < m) {
            found |= (a[r][c] < a[i][j]);
          }
        }
        if (!found) {
          return 0;
        }
      }
    }
    return 1;
  };

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));

  function<bool(int, int)> is_cell_ok = [&] (int i, int j) {
    assert(0 <= i && i < n && 0 <= j && j < m);
    if (a[i][j] == 0) {
      return 1;
    }
    for (int k = 0; k < 4; k++) {
      int r = i + dr[k], c = j + dc[k];
      if (0 <= r && 0 <= c && r < n && c < m) {
        if (a[r][c] < a[i][j]) {
          return 1;
        }
      }
    }
    return 0;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
      assert(0 <= a[i][j] && a[i][j] < n * m);
    }
  }

 /// print(a);exit(0);

  vector<pair<int, int>> bad;

  if (is_all_ok(n, m, a)) {
    cout << "0\n";
    return 0;
  }
  vector<pair<int, int>> cells;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!is_cell_ok(i, j)) {
        bad.push_back({i, j});
      }
    }
  }
  for (int i = 0; i < n && cells.empty(); i++) {
    for (int j = 0; j < m && cells.empty(); j++) {
      if (!is_cell_ok(i, j)) {
        cells.push_back({i, j});
        for (int k = 0; k < 4; k++) {
          int r = i + dr[k], c = j + dc[k];
          if (0 <= r && 0 <= c && r < n && c < m) {
            cells.push_back({r, c});
          }
        }
      }
    }
  }
  assert(!cells.empty());


  assert(1 <= (int) cells.size() && (int) cells.size() <= 5);

  int Swaps = 0;

  for (int cell_id = 0; cell_id < (int) cells.size(); cell_id++) {
    pair<int, int> first_pair = cells[cell_id];
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        pair<int, int> second_pair = {r, c};
        bool deja = 0;
        for (int xid = 0; xid < cell_id; xid++) {
          if (cells[xid] == second_pair) {
            deja = 1;
            break;
          }
        }
        if (deja) {
          continue;
        }
        assert(!deja);
        swap(a[first_pair.first][first_pair.second], a[second_pair.first][second_pair.second]);
       /** bool good_full = 1;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            good_full &= is_cell_ok(i, j);
          }
        }**/
        bool good_partial = 1;
        for (auto &it : bad) {
          if (!is_cell_ok(it.first, it.second)) {
            good_partial = 0;
            break;
          }
        }
        if (good_partial) {
          pair<int, int> it = first_pair;
          good_partial &= is_cell_ok(it.first, it.second);
          for (int k = 0; k < 4; k++) {
            if (0 <= it.first + dr[k] && it.first + dr[k] < n && 0 <= it.second + dc[k] && it.second + dc[k] < m) {
              good_partial &= is_cell_ok(it.first + dr[k], it.second + dc[k]);
            }
          }
          it = second_pair;
          good_partial &= is_cell_ok(it.first, it.second);
          for (int k = 0; k < 4; k++) {
            if (0 <= it.first + dr[k] && it.first + dr[k] < n && 0 <= it.second + dc[k] && it.second + dc[k] < m) {
              good_partial &= is_cell_ok(it.first + dr[k], it.second + dc[k]);
            }
          }
        }
      //  assert(good_full == good_partial);
        swap(a[first_pair.first][first_pair.second], a[second_pair.first][second_pair.second]);
        if (good_partial) {
          Swaps++;
        }
      }
    }
  }

  if (Swaps > 0) {
    cout << 1 << " " << Swaps << "\n";
    return 0;
  }
  cout << "2\n";

  /**for (auto &it : cells) {
    cout << " ---> " << it.first << " " << it.second << "\n";
  }**/
}
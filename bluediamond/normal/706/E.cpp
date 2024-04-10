#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
const int Q = 10000 + 7;
int n, m, c1, c2, q, init[N * N], down[N * N], rgh[N * N], sol[N * N];

int f(int i, int j) {
  if (0 <= i && i < n && 0 <= j && j < m) {
    return i * m + j;
  } else {
    return -1;
  }
}

vector<vector<int>> get(int r, int c, int h, int w) {
  vector<vector<int>> tot;
  vector<int> sol;
  {
    int pos = f(0, c);
    for (int j = 0; j < r; j++) {
      assert(pos != -1);
      pos = down[pos];
    }
    sol.clear();
    for (int j = 0; j < w; j++) {
      pos = rgh[pos];
      assert(pos != -1);
      sol.push_back(pos);
    }
    tot.push_back(sol);
    sol.clear();
    for (int j = 0; j < h; j++) {
      pos = down[pos];
      assert(pos != -1);
      sol.push_back(pos);
    }
    tot.push_back(sol);
  }
  {
    int pos = f(r, 0);
    for (int j = 0; j < c; j++) {
      assert(pos != -1);
      pos = rgh[pos];
    }
    sol.clear();
    for (int j = 0; j < h; j++) {
      pos = down[pos];
      assert(pos != -1);
      sol.push_back(pos);
    }
    tot.push_back(sol);
    sol.clear();
    for (int j = 0; j < w; j++) {
      pos = rgh[pos];
      assert(pos != -1);
      sol.push_back(pos);
    }
    tot.push_back(sol);
  }
  return tot;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> c1 >> c2 >> q;
  n = c1 + 3;
  m = c2 + 3;
  for (int i = 1; i <= c1; i++) {
    for (int j = 1; j <= c2; j++) {
      cin >> init[f(i, j)];
      sol[f(i, j)] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      down[f(i, j)] = f(i + 1, j);
      rgh[f(i, j)] = f(i, j + 1);
    }
  }


  for (int iq = 1; iq <= q; iq++) {
    int r1, c1, r2, c2, h, w;
    cin >> r1 >> c1 >> r2 >> c2 >> h >> w;
    r1--;
    c1--;
    r2--;
    c2--;
    auto v1 = get(r1, c1, h, w);
    auto v2 = get(r2, c2, h, w);
    assert((int) v1.size() == 4);
    assert((int) v2.size() == 4);
    for (int i = 0; i < 4; i++) {
      assert((int) v1[i].size() == (int) v2[i].size());
      if (i == 0 || i == 3) {
        for (int j = 0; j < (int) v1[i].size(); j++) {
          swap(down[v1[i][j]], down[v2[i][j]]);
        }
      } else {
        for (int j = 0; j < (int) v1[i].size(); j++) {
          swap(rgh[v1[i][j]], rgh[v2[i][j]]);
        }
      }
    }
  }

  for (int i = 0; i <= c1; i++) {
    int pos = f(i, 0);
    for (int j = 0; j <= c2; j++) {
      assert(pos != -1);
      sol[f(i, j)] = init[pos];
      pos = rgh[pos];
    }
  }

  for (int i = 1; i <= c1; i++) {
    for (int j = 1; j <= c2; j++) {
      cout << sol[f(i, j)] << " ";
    }
    cout << "\n";
  }

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef double ld;

struct T {
  int i, j;
  ld x, y;
};

vector<T> coefs;
vector<int> PI;

vector<ld> gauss(int n, int m, vector<vector<ld>> a) {
  const ld eps = 1e-14;
  assert((int) a.size() == n);
  for (int i = 0; i < n; i++) {
    assert((int) a[i].size() == m + 1);
  }
  vector<int> pi(n, -1), pj(m, -1);
  while (1) {
    int r = -1, c = -1;
    vector<int> Is, Js;
    for (int i = 0; i < n; i++) {
      if (pi[i] == -1) {
        Is.push_back(i);
      }
    }
    for (int j = 0; j < n; j++) {
      if (pj[j] == -1) {
        Js.push_back(j);
      }
    }
    for (auto &i : Is) {
      for (auto &j : Js) {
        if ((r == -1 && c == -1) || (abs(a[i][j]) > abs(a[r][c]))) {
          r = i;
          c = j;
        }
      }
    }
    if (r == -1 && c == -1) {
      break;
    }
    if (abs(a[r][c]) < eps) {
      break;
    }
    pi[r] = c;
    pj[c] = r;
    ld multiply = (ld) 1 / a[r][c];
    for (int j = 0; j <= m; j++) {
      a[r][j] *= multiply;
    }
    coefs.push_back({r, 0, multiply, 0});
    for (int i = 0; i < n; i++) {
      if (i != r && abs(a[i][c]) > eps) {
        ld coef = a[i][c];
        for (int j = 0; j <= m; j++) {
          a[i][j] -= coef * a[r][j];
        }
        coefs.push_back({i, r, 1, -coef});
      }
    }
  }
  PI = pi;
  vector<ld> sol(m, 0);
  for (int i = 0; i < n; i++) {
    if (pi[i] != -1) {
      sol[pi[i]] = a[i][m];
    }
  }
  for (int i = 0; i < n; i++) {
    ld sum = 0;
    for (int j = 0; j < m; j++) {
      sum += a[i][j] * sol[j];
    }
    if (abs(sum - a[i][m]) > eps) {
      return {};
    }
  }
  return sol;
}


template<class T>
class Matrix {
public:
  int n;
  int m;
  vector<vector<T>> a;

  Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].resize(m, 0);
    }
  }
  Matrix operator * (Matrix b) {
    if (m != b.n) {
      cout << "error on matrix sizes (when wanting to multiply)\n";
      exit(0);
    }
    Matrix c(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          c.a[i][j] += a[i][k] * b.a[k][j];
        }
      }
    }
    return c;
  }
  Matrix operator ^ (long long p) {
    if (n != m) {
      cout << "error on matrix size (when wanting to rise to the power)\n";
      exit(0);
    }
    Matrix c(n, m), cur(n, m);
    cur.a = a;
    for (int i = 0; i < n; i++) {
      c.a[i][i] = 1;
    }
    while (p) {
      if (p & 1) {
        c = c * cur;
      }
      cur = cur * cur;
      p /= 2;
    }
    return c;
  }
};

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> has_trap(n, 0);
  vector<vector<ld>> pnext(n, vector<ld> (n, 0));
  for (int i = 0; i < n; i++) {
    cin >> has_trap[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> traps;
  bool F = 1;
  for (int trap_id = 0; trap_id < n; trap_id++) {
    if (has_trap[trap_id]) {
      traps.push_back(trap_id);
      vector<vector<ld>> a(n, vector<ld> (n + 1, 0));
      for (int i = 0; i < n; i++) {
        a[i][i] = 1;
        if (has_trap[i]) {
          if (i == trap_id) {
            a[i][n] = 1;
          }
        } else {
          assert(!g[i].empty());
          ld inv = (ld) 1 / ((ld) g[i].size());
          for (auto &j : g[i]) {
            assert(j != i);
            a[i][j] += -inv;
          }
        }
      }
      vector<ld> sol;
      if (F) {
        sol = gauss(n, n, a);
        F = 0;
      } else {
        sol.resize(n, 0);
        vector<ld> backs(n);
        for (int i = 0; i < n; i++) {
          backs[i] = a[i][n];
        }
        for (auto &it : coefs) {
          backs[it.i] = backs[it.i] * it.x + backs[it.j] * it.y;
        }
        for (int i = 0; i < n; i++) {
          sol[PI[i]] = backs[i];
        }
      }
      assert(!sol.empty());
      assert((int) sol.size() == n);
      for (int i = 0; i < n; i++) {
        pnext[i][trap_id] = sol[i];
      }
    }
  }
  Matrix<ld> mtr(1, (int) traps.size());
  for (int i = 0; i < (int) traps.size(); i++) {
    mtr.a[0][i] = pnext[0][traps[i]];
  }


  Matrix<ld> mult((int) traps.size(), (int) traps.size());

  for (int i = 0; i < (int) traps.size(); i++) {
    ld inv = (ld) 1 / ((ld) ((int) g[traps[i]].size()));
    for (int j = 0; j < (int) traps.size(); j++) {
      for (auto &vecin : g[traps[i]]) {
        mult.a[i][j] += pnext[vecin][traps[j]] * inv;
      }
    }
  }
  mult = mult ^ (k - 2);
  mtr = mtr * mult;
  cout << fixed << setprecision(4) << mtr.a[0][(int) traps.size() - 1] << "\n";
}
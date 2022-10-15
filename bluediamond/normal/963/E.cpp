#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

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
//#define int ll
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

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

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int C = 100 + 3;

vector<int> gauss(int n, vector<vector<int>> &v) {
  vector<int> sol(n);
  for (int i = 0; i < n; i++) {
    for (int rw = i + 1; rw <= min(n - 1, i + C); rw++) {
      if (v[rw][i] > 0) {
        int coef = dv(v[rw][i], v[i][i]);
        for (int k = i; k <= min(n - 1, i + C); k++) {
          v[rw][k] = add(v[rw][k], -mul(coef, v[i][k]));
        }
        if (min(n - 1, i + C) < n) {
          v[rw][n] = add(v[rw][n], -mul(coef, v[i][n]));
        }
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    sol[i] = v[i][n];
    for (int j = i + 1; j < n; j++) {
      sol[i] = add(sol[i], -mul(sol[j], v[i][j]));
    }
    sol[i] = dv(sol[i], v[i][i]);
  }
  return sol;
}

int prob[4], dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

signed realMain() {
  int raz, a0, a1, a2, a3, sum, ind = 0;
  cin >> raz >> a0 >> a1 >> a2 >> a3;
  sum = add(add(a0, a1), add(a2, a3));
  prob[0] = dv(a0, sum);
  prob[1] = dv(a1, sum);
  prob[2] = dv(a2, sum);
  prob[3] = dv(a3, sum);
  for (int i = 0; i < 4; i++) {
    prob[i] = add(0, -prob[i]);
  }
  map<pair<int, int>, int> id;
  for (int r = -raz; r <= +raz; r++) {
    for (int c = -raz; c <= +raz; c++) {
      if (r * r + c * c <= raz * raz) {
        id[{r, c}] = ++ind;
      }
    }
  }
  vector<vector<int>> rel;
  for (int r = -raz; r <= +raz; r++) {
    for (int c = -raz; c <= +raz; c++) {
      if (r * r + c * c <= raz * raz) {
        vector<int> now(ind);
        now[id[{r, c}] - 1] = 1;
        for (int k = 0; k < 4; k++) {
          int rn = r + dr[k], cn = c + dc[k];
          if (rn * rn + cn * cn <= raz * raz) {
            now[id[{rn, cn}] - 1] = prob[k];
          }
        }
        now.push_back(1);
        rel.push_back(now);
      }
    }
  }
  vector<int> v = gauss(ind, rel);
  int need = id[{0, 0}] - 1;
  cout << v[need] << "\n";
  return 0;
}
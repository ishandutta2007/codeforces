#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;


const int M = 998244353;

class modMatrix {
public:
  int n;
  vector<vector<int>> a;

  modMatrix(int n) : n(n), a(n, vector<int> (n, 0)) {
  }
  modMatrix operator + (modMatrix b) {
    modMatrix c(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] += b.a[i][j];
        if (a[i][j] >= M) a[i][j] -= M;
      }
    }
    return *this;
  }
  modMatrix operator * (modMatrix b) {
    modMatrix c(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          c.a[i][j] = (c.a[i][j] + (long long) a[i][k] * b.a[k][j]) % M;
        }
      }
    }
    return c;
  }
  modMatrix operator ^ (long long p) {
    modMatrix c(n), cur(n);
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

class BigMatrix {
public:
  int n;
  int m;
  int dim;
  vector<vector<modMatrix>> a;

  BigMatrix(int n, int m, int dim) : n(n), m(m), dim(dim), a(n, vector<modMatrix> (m, modMatrix(dim))) {
  }
  BigMatrix operator * (BigMatrix b) {
    BigMatrix c(n, m, dim);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          c.a[i][j] = c.a[i][j] + (a[i][k] * b.a[k][j]);
        }
      }
    }
    return c;
  }
  BigMatrix operator ^ (long long p) {
    BigMatrix c(n, m, dim), cur(n, m, dim);
    cur.a = a;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < dim; k++) {
        c.a[i][i].a[k][k] = 1;
      }
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


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> adj(n, vector<int> (n, 0));
  vector<int> deg(n, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a][b] = adj[b][a] = 1;
    deg[a]++;
    deg[b]++;
  }
  if (k == 1) {
    cout << "0\n";
    return 0;
  }
  BigMatrix init(1, 2, n);

  modMatrix adj_mtr(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      adj_mtr.a[i][j] = adj[i][j];
    }
  }
  modMatrix adj_mtr2 = adj_mtr ^ 2;

  for (int i = 0; i < n; i++) {
    adj_mtr2.a[i][i] -= deg[i];
    if (adj_mtr.a[i][i] < 0) adj_mtr.a[i][i] += M;
  }

  init.a[0][0] = adj_mtr;
  init.a[0][1] = adj_mtr2;


  BigMatrix mlt(2, 2, n);

  {
    for (int i = 0; i < n; i++) {
      mlt.a[0][1].a[i][i] = (M + 1 - deg[i]) % M;
    }
  }
  {
    for (int i = 0; i < n; i++) {
      mlt.a[1][0].a[i][i] = 1;
    }
  }
  {
    mlt.a[1][1] = adj_mtr;
  }

  mlt = mlt ^ (k - 1);
  init = init * mlt;

  int sol = 0;
  for (int i = 0; i < n; i++) {
    sol += init.a[0][0].a[i][i];
    sol %= M;
  }
  cout << sol << "\n";
}
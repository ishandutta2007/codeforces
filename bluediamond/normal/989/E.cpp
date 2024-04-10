#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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


bool home = 1;

const int N = 200 + 7;

struct P {
        ll x;
        ll y;
};

ll f(P a, P b) {
        return (a.x + b.x) * (a.y - b.y);
}

ll f(P a, P b, P c) {
        return f(a, b) + f(b, c) + f(c, a);
}

int n;
P a[N];
int inside[N];
ld prob[N][N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }


        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> a[i].x >> a[i].y;
        }

        vector<vector<int>> all;

        set<vector<int>> s;

        for (int i = 1; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                        vector<int> points;
                        for (int k = 1; k <= n; k++) {
                                if (f(a[i], a[j], a[k]) == 0) {
                                        points.push_back(k);
                                }
                        }
                        s.insert(points);
                }
        }
        for (auto &points : s) {
                all.push_back(points);
                for (auto &P : points) {
                        inside[P]++;
                }
        }
        for (int i = 1; i <= n; i++) {
                assert((int) inside[i] > 0);
        }
        for (auto &points : all) {
                for (auto &i : points) {
                        ld value = inside[i] * (int) points.size();
                        value = 1 / value;
                        for (auto &j : points) {
                                prob[i][j] += value;
                        }
                }
        }

        for (int i = 1; i <= n; i++) {
                ld s = 0;
                for (int j = 1; j <= n; j++) {
                        s += prob[i][j];
                }
                assert(abs(s - 1) < 1e-14);
        }

        Matrix<ld> mlt(n, n);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        mlt.a[i][j] = prob[j + 1][i + 1];
                }
        }
        for (auto &points : all) {
                for (auto &p : points) {
                        p--;
                }
        }

        vector<Matrix<ld>> memo;
        memo.push_back(mlt);
        while (1 << ((int) memo.size()) < (int) 1e4) {
                mlt = mlt * mlt;
                memo.push_back(mlt);
        }


        int q;
        cin >> q;
        while (q--) {
                int v;
                int t;
                cin >> v >> t;
                v--;
                t--;

                ld sol = 0;
                Matrix<ld> prob(1, n);
                prob.a[0][v] = 1;

                for (int bit = 0; (1 << bit) <= t; bit++) {
                        if (t & (1 << bit)) {
                                prob = prob * memo[bit];
                        }
                }

                for (auto &points : all) {
                        ld inv = (int) points.size();
                        inv = 1 / inv;
                        ld sum = 0;
                        for (auto &x : points) {
                                sum += prob.a[0][x];
                        }
                        sol = max(sol, sum * inv);
                }

                cout << fixed << setprecision(6) << sol << "\n";
        }
}
/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.06
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define zero(a) memset(a, 0, sizeof(a))

const int N = 30;

typedef double dbl;

struct T {
  dbl p;
  int i, j;
};

int cnt, go[N][N][N][N];
vector<T> c[N][N];
dbl p[N][N], q[N][N];

int pos( int i, int l, int r ) { // [l..r]
  if (i < l || i > r)
    return i;
  return r - (i - l);
}

int main() {
  int n, k;
  cin >> n >> k;
  int perm[n];
  forn(i, n)
    cin >> perm[i];
  forn(r, n)
    forn(l, r + 1) {
      cnt++;
      forn(i, n)
        forn(j, n)
          go[i][j][pos(i, l, r)][pos(j, l, r)]++;
    }
  forn(i, n)
    forn(j, n)
      forn(i1, n)
        forn(j1, n)
          if (go[i][j][i1][j1] != 0)
            c[i][j].pb(T {1. * go[i][j][i1][j1] / cnt, i1, j1});

  dbl res = 0;
  forn(comp, 2) {
    zero(p);
    forn(i, n)
      forn(j, i) 
        if ((perm[i] < perm[j]) == comp)
          p[i][j] += 1;
    forn(_, k) {
      zero(q);
      forn(a, n)
        forn(b, n)
          if (p[a][b] > 0)
            for (auto t : c[a][b])
              q[t.i][t.j] += p[a][b] * t.p;
      memcpy(p, q, sizeof(p));
    }
    forn(a, n)
      forn(b, n)
        if ((a < b) != comp)
          res += p[a][b];
  }
  printf("%.15f\n", res);
  return 0;
}
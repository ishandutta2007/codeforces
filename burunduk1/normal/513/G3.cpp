/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.06
 */

#include <bits/stdc++.h>

using namespace std;

#  define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define zero(a) memset(a, 0, sizeof(a))

const int N = 100;

typedef double dbl;

#pragma pack(4)
struct T {
  dbl p;
  short i, j;
};
struct T2 {
  dbl p;
  short i;
};

int n, k, perm[N];
int cnt, go[N][N], go2[N]; // 200 mb
vector<T> c[N][N];
vector<T2> c2[N];
dbl p[N][N], q[N][N];
dbl p2[N], q2[N];

int pos( int i, int l, int r ) { // [l..r]
  if (i < l || i > r)
    return i;
  return r - (i - l);
}

dbl solve2( int k ) {
  dbl res = 0;
  forn(i, n) {
    zero(p2);
    p2[i] = 1;
    forn(_, k) {
      zero(q2);
      forn(b, n) {
        const dbl tmp = p2[b];
        if (tmp > 0) 
          for (auto t : c2[b])
            q2[t.i] += tmp * t.p;
      }
      memcpy(p2, q2, sizeof(p2));
    }
    memcpy(p[i], p2, sizeof(p2));
  }
  forn(i, n) 
    forn(j, i)
      forn(a, n)
        forn(b, n)
          if (a != b)
            if ((a < b) != (perm[i] < perm[j]))
              res += p[i][a] * p[j][b];
  return res + (n - 1) * 0.25;
}

dbl solve( int k ) {
  dbl res = 0;
  zero(p);
  forn(i, n)
    forn(j, n) 
      p[i][j] += (perm[i] >= perm[j]);
  forn(_, k) {
    zero(q);
    forn(a, n)
      forn(b, n) {
        const dbl tmp = p[a][b];
        if (tmp > 0) 
          for (auto t : c[a][b])
            q[t.i][t.j] += tmp * t.p;
      }
    memcpy(p, q, sizeof(p));
  }
  forn(a, n)
    forn(b, n)
      if ((a < b) != 0)
        res += p[a][b];
      else
        res += 1 - p[a][b];
  return res / 2;
}

dbl inv;
void build2() {
  forn(i, n) {
    zero(go2);
    forn(r, n)
      forn(l, r + 1) 
        go2[pos(i, l, r)]++;
    forn(i1, n)
      if (go2[i1]) 
        c2[i].pb(T2 {inv * go2[i1], i1});
  }
}
void build() {
  forn(i, n)
    forn(j, n) {
      zero(go);
      forn(r, n)
        forn(l, r + 1) 
          go[pos(i, l, r)][pos(j, l, r)]++;
      forn(i1, n)
        forn(j1, n)
          if (go[i1][j1]) 
            c[i][j].pb(T {inv * go[i1][j1], i1, j1});
    }
}
 
int main() {
  cin >> n >> k;
  if (k > 800) {
    printf("%.15f\n", n * (n - 1) * 0.25);
    return 0;
  }
  forn(i, n)
    cin >> perm[i];

  forn(r, n)
    forn(l, r + 1) 
      cnt++;
  inv = 1. / cnt;

  if (k <= 600) {
    build();
    printf("%.15f\n", (double)solve(k));
  } else {
    //build();
    //printf("%.15f\n", (double)solve(k));
    build2();
    printf("%.15f\n", (double)solve2(k));
  }
  fprintf(stderr, "time = %.2f\n", 1. * clock() / CLOCKS_PER_SEC); // stamp
  return 0;
}
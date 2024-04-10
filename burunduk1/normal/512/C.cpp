/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.02
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define pb push_back
#define fiint(a, x) memset(a, x, sizeof(a))

typedef vector <int> vi;

const int M = 2e4 + 10;
int p[M];
void calc_primes() {
  p[0] = p[1] = 1;
  for (int i = 2; i < M; i++)
    if (!p[i]) {
      for (int j = i + i; j < M; j += i)
        p[j] = 1;
    }
}

template <const int maxV, const int maxE>
struct Graph
{
  int S, T, e, head[maxV], next[maxE], to[maxE], f[maxE], c[maxE];
  int cc, u[maxV];

  Graph() {
    e = 0, cc = 1;
    fiint(u, 0), fiint(head, -1);
  }

  void AddE( int a, int b, int x1, int x2 ) {
    //err("%d --%d--> %d\n", a, x1, b);
    assert(e + 2 <= maxE);
    next[e] = head[a], to[e] = b, f[e] = 0, c[e] = x1, head[a] = e++;
    next[e] = head[b], to[e] = a, f[e] = 0, c[e] = x2, head[b] = e++;
  }

  int gval;
  int dfs( int v, int k, int val ) {
    if (v == T) {
      gval = val;
      return 1;
    }
    u[v] = cc;
    for (int e = head[v]; e != -1; e = next[e])
      if (f[e] + k <= c[e] && u[to[e]] != cc && dfs(to[e], k, min(val, c[e] - f[e]))) {
        assert(k <= gval && f[e] + gval <= c[e]);
        f[e] += gval, f[e ^ 1] -= gval;
        return 1;
      }
    return 0;
  }

  int Flow( int MAX_C = 1 ) {
    int sum = 0;
    for (int k = MAX_C; k > 0; k = k == 1 ? 0 : (k + 1) / 2)
      for (cc++; dfs(S, k, 2 * k); cc++)
        sum += gval;
    return sum;
  }
};

const int N = 500;

Graph<2 * N + 2, 2 * (N * N + 2 * N)> g;
vi c[N], t;
vector<vi> ans;
int u[N];

void dfs( int v ) {
  //err("dfs: %d\n", v);
  u[v] = 1;
  t.pb(v);
  for (int x : c[v])
    if (!u[x])
      dfs(x);
}

int main() {
  int n;
  cin >> n;
  int a[n];
  int xn = 0, x[n];
  int yn = 0, y[n];
  forn(i, n) {
    cin >> a[i];
    ((a[i] & 1) ? y[yn++] : x[xn++]) = i;
  }
  calc_primes();

  g.S = xn + yn, g.T = g.S + 1;
  forn(i, xn)
    g.AddE(g.S, i, 2, 0);
  forn(i, yn)
    g.AddE(xn + i, g.T, 2, 0);
  forn(i, xn)
    forn(j, yn) {
      //err("%d, %d : %d %d\n", i, j, a[x[i]] + a[y[j]], p[a[x[i]] + a[y[j]]]);
      if (!p[a[x[i]] + a[y[j]]]) 
        g.AddE(i, xn + j, 1, 0);
    }

  int f = g.Flow();
  //err("flow = %d\n", f);
  if (f != n) {
    puts("Impossible");
    return 0;
  }
  forn(i, xn)
    for (int e = g.head[i]; e != -1; e = g.next[e])
      if (g.f[e] && g.to[e] != g.S) {
        int j = g.to[e] - xn;
        c[x[i]].pb(y[j]);
        c[y[j]].pb(x[i]);
      }

  forn(i, n)
    if (!u[i]) {
      t.clear();
      dfs(i);
      ans.pb(t);
    }
  printf("%d\n", ans.size());
  for (auto v : ans) {
    printf("%d", v.size());
    for (int x : v)
      printf(" %d", x + 1);
    puts("");
/*
    forn(i, v.size())
      printf(" %d[%d,%d]", a[v[i]] + a[v[(i + 1) %v.size()]], v[i], v[(i + 1) %v.size()]);
    puts("");
*/
  }
//  forn(i, n)
//    printf("%d ", a[i]);
  return 0;
}
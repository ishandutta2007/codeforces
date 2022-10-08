/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.06
 */

#include <bits/stdc++.h>

using namespace std;
#  define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back


typedef vector <int> vi;

const int N = 111;
const int inf = 1e9;

void no() {
  puts("IMPOSSIBLE");
  exit(0);
}

int n, c;
vi l[N], r[N];

int Max( vi &v ) {
  return v.size() ? *max_element(all(v)) : -inf;
}
int Min( vi &v ) {
  return v.size() ? *min_element(all(v)) : inf;
}

/*
  int L = 0, R = r;
  L = max(L, Max(l[v]));
  for (int x = 1; x <= L; x++) {
    L = max(L, Max(r[x]));
    L = max(L, Max(l[x]));
  }
  R = min(R, Min(r[v]));
  for (int x = r - 1; x >= R; x--) {
    R = min(R, Min(r[x]));
    R = min(R, Min(l[x]));
  }
  if (L >= R)
    no();
*/

vi res;

bool closed( int a, int b ) {
  err("closed[%d..%d)\n", a, b);
  for (int i = a; i < b; i++) {
    for (int x : l[i])
      if (x >= b)
        return 0;
    for (int x : r[i])
      if (x >= b)
        return 0;
  }
  err("ok\n");
  return 1;    
}

int u[N][N];
int f[N][N];

int good( int v, int border ) {
  int &F = f[N][N];
  if (u[v][border])
    return F;
    u[v][border] = 1;
  if (v >= border)
    return F = 1;
  if (v + 1 == border) {
    if (sz(l[v]) || sz(r[v]))
      return F = 0;
    return F = 1;
  }
  int mi_l = Min(l[v]), ma_l = Max(l[v]);
  int mi_r = Min(r[v]), ma_r = Max(r[v]);
  for (int x = v + 1; x <= border; x++) 
    if (ma_l < x && x <= mi_r && closed(v + 1, x) && closed(x, border))
      if (good(v + 1, x) && good(x, border))
        return F = 1;
  return F = 0;
}

void go( int v, int border ) {
  if (v >= border)
    return;
  err("go [%d..%d)\n", v, border);
  if (v + 1 == border) {
    err("leaf: %d %d\n", sz(l[v]), sz(r[v]));
    if (sz(l[v]) || sz(r[v]))
      no();
    res.pb(v);
    return;
  }
  int mi_l = Min(l[v]), ma_l = Max(l[v]);
  int mi_r = Min(r[v]), ma_r = Max(r[v]);
  for (int x = v + 1; x <= border; x++) 
    if (ma_l < x && x <= mi_r && closed(v + 1, x) && closed(x, border)) 
      if (good(v + 1, x) && good(x, border)) {
        go(v + 1, x);
        res.pb(v);
        go(x, border);
        return;
      }
  no();
}

int main() {
  scanf("%d%d", &n, &c);
  forn(i, c) {
    int a, b;
    char s[9];
    scanf("%d%d%s", &a, &b, s), a--, b--;
    int left = !strcmp(s, "LEFT");
    if (a >= b)
      no();
    if (left)
      l[a].pb(b);
    else
      r[a].pb(b);
  }
  if (!good(0, n))
    no();
  go(0, n);
  for (int x : res)
    printf("%d ", x + 1);
  return 0;
}
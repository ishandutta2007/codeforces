/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#define __USE_MINGW_ANSI_STDIO 1
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long LL;
typedef pair <int, int> pii;

const int N = 1 << 15;
LL inf = 1e18;

int pw[N], ph[N], p[N];
pii w[N], h[N];

const int K = 3;

struct Seg {
  int l, r; // [l, r)
  LL f[K][K];
  int len() { return r - l; }

  void init( int i ) {
    l = i, r = i + 1;
    forn(a, K)
      forn(b, K)
        f[a][b] = -inf;
    if (p[i] != i)
      f[0][0] = (LL)w[i].first * h[i].first;
    f[0][1] = 0;
    f[1][0] = 0;
  }
};

Seg t[2 * N];

template <class T> inline void relax( T &a, T b ) { a = max(a, b); }

LL match( int l, int r ) {
  if (r - l <= 0)
    return 0;
  int n = r - l, q[n];
  forn(i, n) 
    q[i] = i;
  LL ma = -inf;
  do {
    LL sum = 0;
    int bad = 0;
    forn(i, n) {
      bad |= (p[l + i] == l + q[i]);
      sum += (LL)w[l + i].first * h[l + q[i]].first;
    }
    if (!bad) 
      relax(ma, sum);
  } while (next_permutation(q, q + n));
  //printf("match [%d..%d) = %I64d\n", l, r, ma);
  return ma;
}

Seg merge( Seg l, Seg r ) {
  Seg s;
  s.l = l.l, s.r = r.r;
  //printf("merge [%d..%d) and [%d..%d) to [%d..%d) : ", l.l, l.r, r.l, r.r, s.l, s.r);
  assert(l.r == r.l);
  forn(i, K)
    forn(j, K)
      s.f[i][j] = -inf;
  forn(ll, K)
    forn(lr, K)
      forn(rl, K)
        forn(rr, K) {
          if (l.f[ll][lr] < -inf / 2 || r.f[rl][rr] < -inf / 2)
            continue;
          //printf("[%d,%d] x [%d,%d]\n", ll, lr, rl, rr);
          if (lr + rl > K)
            continue;
          relax(s.f[ll][rr], l.f[ll][lr] + r.f[rl][rr] + match(l.r - lr, r.l + rl));
          if (ll + lr == l.len() && ll + lr + rl < K)
            relax(s.f[ll + lr + rl][rr], l.f[ll][lr] + r.f[rl][rr]);
          if (rl + rr == r.len() && lr + rl + rr < K)
            relax(s.f[ll][lr + rl + rr], l.f[ll][lr] + r.f[rl][rr]);
        }
/*
  forn(i, 3) {
    printf("[");
    forn(j, 3)
      printf(" %I64d", s.f[i][j]);
    printf(" ] ");
  }
  puts("");
*/
  return s;
}

void build( int v, int vl, int vr ) {
  if (vr - vl == 1) {
    t[v].init(vl);
    return;
  }
  int vm = (vl + vr) / 2;
  build(2 * v + 0, vl, vm);
  build(2 * v + 1, vm, vr);
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void change( int v, int vl, int vr, int i ) {
  if (vr <= i || i < vl)
    return;
  if (vr - vl == 1) {
    assert(vl == i);
    t[v].init(vl);
    return;
  }
  int vm = (vl + vr) / 2;
  change(2 * v + 0, vl, vm, i);
  change(2 * v + 1, vm, vr, i);
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

int main() {
  //#ifdef DEBUG
  //assert(freopen("d.in", "r", stdin));
  //#endif
  int n, q;
  scanf("%d%d", &n, &q);
  forn(i, n) scanf("%d", &w[i].first), w[i].second = i;
  forn(i, n) scanf("%d", &h[i].first), h[i].second = i;
  sort(w, w + n);
  sort(h, h + n);
  forn(i, n) pw[w[i].second] = i;
  forn(i, n) ph[h[i].second] = i;
  forn(i, n) p[pw[i]] = ph[i];
  build(1, 0, n);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    a = pw[a], b = pw[b];
    int pa = p[b], pb = p[a];
    //printf("%d --|--> %d\n", w[a].first, h[pa].first);
    //printf("%d --|--> %d\n", w[b].first, h[pb].first);
    p[a] = pa, change(1, 0, n, a);
    p[b] = pb, change(1, 0, n, b);
    printf("%I64d\n", t[1].f[0][0]);
  }
  return 0;
}
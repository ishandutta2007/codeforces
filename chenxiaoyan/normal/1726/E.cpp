#include <bits/stdc++.h>
using namespace std;
bool Mbe;

using ll = long long;
using tii = tuple<int, int>;
#define mt(arg...) make_tuple(arg)
#define X(x) get<0>(x)
#define Y(x) get<1>(x)
using vi = vector<int>; using vii = vector<tii>;
#define pb(arg...) emplace_back(arg)
#define sz(x) ((int)(x).size())
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define per(i, r, l) for(int i = (r); i >= (l); --i)
template<class T1, class T2> void cmx(T1 &x, const T2 &y) { if(y > x) x = y; }
template<class T1, class T2> void cmn(T1 &x, const T2 &y) { if(y < x) x = y; }
const int inf = sizeof(int) == 4 ? 0x3f3f3f3fll : 0x3f3f3f3f3f3f3f3fll;

char gc() { return getchar(); } void pc(char x) { putchar(x); }
template<class T = int> T rd() {
  T x = 0; char c = gc(); bool ne = false;
  while(!isdigit(c)) ne |= c == '-', c = gc();
  while(isdigit(c)) x = 10 * x + (c ^ 48), c = gc();
  return ne ? -x : x;
}
template<class T> void prt(T x) {
  x < 0 && (pc('-'), x = -x);
  x > 9 && (prt(x / 10), 0);
  pc(x % 10 ^ 48);
}

const int P = 998244353;
int qp(int x, int e = P - 2) {
  int res = 1;
  for(; e; e >>= 1, x = (ll)x * x % P) if(e & 1) res = (ll)res * x % P;
  return res;
}

const int N = 1e6 + 10;
int fc[N], ifc[N], iv[N];
int comb(int n, int m) {
  if(m < 0 || m > n) return 0;
  return (ll)fc[n] * ifc[n - m] % P * ifc[m] % P;
}

int n;
int f[N], g[N], h[N];

void solve_f() {
  f[0] = 1;
  rep(k, 1, n / 2) {
    f[k] = comb(n - k, k);
  }
}

void mian() {
  n = rd();
  // static int p[N];
  // rep(i, 1, n) p[i] = i;
  // int ss = 0;
  // do {
  //   static int q[N];
  //   rep(i, 1, n) q[p[i]] = i;
  //   bool ok = true;
  //   rep(i, 1, n) ok &= abs(p[i] - q[i]) <= 1;
  //   ss += ok;
  // } while(next_permutation(p + 1, p + n + 1));
  // cout << ss << " = " << ss << "\n";
  solve_f();
  g[0] = 1;
  rep(i, 1, n) g[i] = (g[i - 1] + (ll)(i - 1) * g[i - 2]) % P;
  h[0] = 1;
  rep(i, 1, n) h[i] = (ll)h[i - 1] * (2 * i - 1) % P;
  int ans = 0;
  rep(i, 0, n / 2) if(~i & 1) {
    int ad = (ll)f[i] * h[i / 2] % P * g[n - 2 * i] % P;
    ad = (ll)ad * qp(2, i / 2) % P;
    ans = (ans + ad) % P;
  }
  prt(ans), pc('\n');
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  fc[0] = ifc[0] = 1;
  rep(i, 1, N - 1) {
    fc[i] = (ll)fc[i - 1] * i % P;
    ifc[i] = (ll)ifc[i - 1] * (iv[i] = qp(i)) % P;
  }
  int cases = 1;
  cases = rd();
  while(cases--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}

/*
g++ e.cpp -o e -O2 -std=c++14 -static -Wall -Wno-parentheses -Wextra -Wshadow -DLOCAL -Wl,--stack=1145141919

Author: chenxia25
Start coding at: 
Finish debugging at: 
*/
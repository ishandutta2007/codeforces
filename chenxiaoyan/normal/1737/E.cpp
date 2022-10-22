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

char gc() { return getchar(); } void pc(const char &x) { putchar(x); }
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

const int P = 1e9 + 7;
const int iv2 = P + 1 >> 1;
int qp(int x, int e = P - 2) { int res = 1; for(; e; e >>= 1, x = (ll)x * x % P) if(e & 1) res = (ll)res * x % P; return res; }

const int N = 1e6 + 10;

int n;
int f[N];

void mian() {
  n = rd();
  if(n == 1) return puts("1"), void();
  f[n] = 1;
  int sum = 1, now = n;
  per(i, n - 1, 1) {
    while(i <= now - i) {
      sum = (sum - (ll)f[now] * qp(iv2, now - i - (now == n)) % P + P) % P;
      --now;
    }
    f[i] = sum;
    sum = (ll)(sum + f[i]) * iv2 % P;
  }
  // rep(i, 1, n) cout << f[i] << " \n"[i == n];
  rep(i, 1, n) {
    int ans = (ll)f[i] * (i == n ? 1 : iv2) % P;
    ans = (ll)ans * qp(iv2, i - 1 - i / 2) % P;
    prt(ans), pc('\n');
  }
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
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
#include <bits/stdc++.h>
using namespace std;
bool Mbe;

using ll = long long;
#define int ll
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

const int N = 3e5 + 10;

int n, qu, a[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch() / 1ns);

struct type {
  int a[35];
  type() { memset(a, 0, sizeof(a)); }
  bool ok(int m) {
    rep(i, 0, 34) if(a[i] % m) return false;
    return true;
  }
  friend void operator+=(type &f, const type &g) {
    rep(i, 0, 34) f.a[i] += g.a[i];
  }
  friend type operator+(type f, const type &g) {
    rep(i, 0, 34) f.a[i] += g.a[i];
    return f;
  }
  friend type operator-(type f, const type &g) {
    rep(i, 0, 34) f.a[i] -= g.a[i];
    return f;
  }
};

map<int, type> mp;
type make(int x) {
  if(mp.find(x) == mp.end()) {
    type t;
    rep(i, 0, 34) t.a[i] = uniform_int_distribution<ll>(0, 10000000000000ll)(rng);
    return mp[x] = t;
  } else return mp[x];
}

struct Bit {
  type s[N];
  void add(int x, const type &v) {
    while(x <= n) s[x] += v, x += x & -x;
  }
  type ask(int x) {
    type t;
    while(x) t += s[x], x -= x & -x;
    return t;
  }
} bit;

void mian() {
  n = rd(), qu = rd();
  rep(i, 1, n) a[i] = rd(), bit.add(i, make(a[i]));
  while(qu--) {
    int tp = rd();
    if(tp == 1) {
      int i = rd(), x = rd();
      bit.add(i, make(x) - make(a[i]));
      a[i] = x;
    } else {
      int l = rd(), r = rd(), k = rd();
      type t = bit.ask(r) - bit.ask(l - 1);
      puts(t.ok(k) ? "YES" : "NO");
    }
  }
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  int cases = 1;
  // cases = rd();
  while(cases--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}

/*
g++ f.cpp -o f -O2 -std=c++14 -static -Wall -Wno-parentheses -Wextra -Wshadow -DLOCAL -Wl,--stack=1145141919

Author: chenxia25
Start coding at: 
Finish debugging at: 
*/
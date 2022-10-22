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

const int N = 1e5 + 10;

int qp(int x, int e = P - 2) { int res = 1; for(; e; e >>= 1, x = (ll)x * x % P) if(e & 1) res = (ll)res * x % P; return res; }
int fc[N], ifc[N];
int comb(int n, int m) {
  if(m < 0 || m > n) return 0;
  return (ll)fc[n] * ifc[m] % P * ifc[n - m] % P;
}

int n;
int A[N], a[N], b[N];
map<int, tii> mp;

void mian() {
  n = rd();
  rep(i, 1, n) A[i] = rd(), a[i] = a[i - 1] + A[i];
  b[n + 1] = 0; per(i, n, 1) b[i] = b[i + 1] + A[i];
  map<int, tii>().swap(mp);
  for(int i = 1, ie; i <= n; i = ie + 1) {
    ie = i; while(ie < n && b[ie + 1] == b[i]) ++ie;
    mp[b[i]] = mt(i, ie);
  }
  int ans = 1;
  for(int i = 1, ie; i <= n; i = ie + 1) {
    ie = i; while(ie < n && a[ie + 1] == a[i]) ++ie;
    int l = i, r = ie, val = a[i];
    int L, R; tie(L, R) = mp[val];
    if(!L) continue;
    if(R <= l) continue;
    if(r < L) {
      int sum = 0;
      rep(j, 0, min(r - l + 1, R - L + 1)) sum = (sum + (ll)comb(r - l + 1, j) * comb(R - L + 1, j)) % P;
      ans = (ll)ans * sum % P;
    } else if(l == L - 1 && r == R - 1) {
      ans = (ll)ans * qp(2, r - l + 1) % P;
    } else if(l == L && r == R - 1) {
      ans = (ll)ans * qp(2, r - l + 1) % P;
    } else if(l == L - 1 && r == R) {
      ans = (ll)ans * qp(2, r - l) % P;
    } else {
      assert(l == L && r == R);
      ans = (ll)ans * qp(2, r - l) % P;
    }
  }
  prt(ans), pc('\n');
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  fc[0] = 1; rep(i, 1, N - 1) fc[i] = (ll)fc[i - 1] * i % P;
  ifc[N - 1] = qp(fc[N - 1]); per(i, N - 2, 0) ifc[i] = (ll)ifc[i + 1] * (i + 1) % P;
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
//{{{
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BR putchar('\n')
#define MS0(ar) memset(ar, 0, sizeof(ar))
#define MS1(ar) memset(ar, -1, sizeof(ar))
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef complex<double> CD;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<LL> VL;

void R(int &x) { scanf("%d", &x); }
void R(LL &x) { scanf("%lld", &x); }
void R(ULL &x) { scanf("%llu", &x); }
void R(double &x) { scanf("%lf", &x); }
void R(LD &x) { scanf("%Lf", &x); }

template <typename T> void R(T &t) { cin >> t; }
template <typename A, typename B> void R(pair<A, B> &x) {
  R(x.F);
  R(x.S);
}

template <typename T> void R(vector<T> &ar) {
  for (auto &it : ar)
    R(it);
}

template <typename T, typename... Args> void R(T &t, Args &... args) {
  R(t);
  R(args...);
}

void W(const char &c) { putchar(c); };
void W(const int &x) { printf("%d", x); }
void W(const LL &x) { printf("%lld", x); }
void W(const ULL &x) { printf("%llu", x); }
void W(const double &x) { printf("%lf", x); }
void W(const LD &x) { printf("%Lf", x); }

template <typename T> void W(const T &t) { cout << t; }
template <typename T> void W(const vector<T> &ar) {
  for (size_t i = 0; i < ar.size(); ++i) {
    W(ar[i]);
    putchar(" \n"[i + 1u == ar.size()]);
  }
}
template <typename T, typename... Args>
void W(const T &t, const Args &... args) {
  W(t);
  W(args...);
}
#define BR putchar('\n')

template <typename T> void Min(T &x, T v) { x = min(x, v); }
template <typename T> void Max(T &x, T v) { x = max(x, v); }
//}}}
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 500010;

int n;
LL sx, sy;
int type[maxn];
LL x[maxn], y[maxn];

void f() {
  puts("YES");
  exit(0);
}

int main() {
  R(n, sx, sy);
  LL u, d, r, l;
  u = l = LLONG_MIN;
  d = r = LLONG_MAX;
  LL ur, ul, dr, dl;
  ur = dr = LLONG_MAX;
  ul = dl = LLONG_MIN;
  REP(i, n) {
    static char s[44];
    scanf("%s", s);
    if (s[0] == 'R') type[i] = 1;
    else type[i] = s[0] == 'B' ? 2 : 3;
    R(x[i], y[i]);
    if (x[i] == sx) {
      if (y[i] > sy) {
        r = min(r, y[i]);
      } else {
        l = max(l, y[i]);
      }
    } else if (y[i] == sy) {
      if (x[i] > sx) {
        d = min(d, x[i]);
      } else {
        u = max(u, x[i]);
      }
    } else if (x[i] + y[i] == sx + sy) {
      if (y[i] > sy) {
        ur = min(ur, y[i]);
      } else {
        dl = max(dl, y[i]);
      }
    } else if (x[i] - y[i] == sx - sy) {
      if (y[i] > sy) {
        dr = min(dr, y[i]);
      } else {
        ul = max(ul, y[i]);
      }
    }
  }
  REP(i, n) {
    if (x[i] == sx) {
      if ((y[i] == r || y[i] == l) && (type[i] & 1)) {
        f();
      }
    } else if (y[i] == sy) {
      if ((x[i] == d || x[i] == u) && (type[i] & 1)) {
        f();
      }
    } else if (x[i] + y[i] == sx + sy) {
      if ((y[i] == ur  || y[i] == dl) && (type[i] & 2)) {
        f();
      }
    } else if (x[i] - y[i] == sx - sy) {
      if ((y[i] == dr  || y[i] == ul) && (type[i] & 2)) {
        f();
      }
    }
  }
  puts("NO");
  return 0;
}
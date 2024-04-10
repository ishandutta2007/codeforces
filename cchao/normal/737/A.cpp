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
const int maxn = 200010;

pair<LL, LL> a[maxn];
LL b[maxn];
vector<LL> v, sum;

LL S(int x) {
  return x >= 0 ? sum[x] : 0;
}

int main() {
  int n, k;
  LL s, t;
  R(n, k, s, t);
  REP(i, n) R(a[i].F, a[i].S);
  REPE(i, 1, k) R(b[i]);
  sort(b, b + k + 1);
  b[++k] = s;
  REPE(i, 1, k) v.push_back(b[i] - b[i - 1]);
  sort(ALL(v));
  sum = v;
  LL all = 0;
  for (auto &it : v) {
    all += it;
  }
  for (int i = 1; i < SZ(sum); ++i)
    sum[i] += sum[i - 1];
  LL ans = -1;
  REP(i, n) {
    LL c = a[i].F;
    LL f = a[i].S;
    if (f < v.back()) continue;
    int pos = upper_bound(ALL(v), f / 2) - v.begin();
    LL acc = S(pos - 1);
    LL normal = all - acc;
    int nn = SZ(v) - pos;
    LL delta = nn * f - normal;
    acc += delta;
    normal -= delta;
    LL myt = acc + normal * 2;
    if (myt <= t) {
      if (ans == -1 || c < ans) ans = c;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
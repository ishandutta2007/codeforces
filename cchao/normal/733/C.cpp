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
const int maxn = 1000010;

int n, k, a[maxn], b[maxn];

int main() {
  R(n);
  REP(i, n) R(a[i]);
  R(k);
  REP(i, k) R(b[i]);
  vector<PII> todo;
  int j = 0;
  for (int i = 0; i < k; ++i) {
    int x = b[i];
    int sum = 0;
    int oj = j;
    while (sum < x && j < n) {
      sum += a[j++];
    }
    if (sum != x) {
      puts("NO");
      return 0;
    }
    todo.EB(oj, j);
  }
  if (j != n) {
    puts("NO");
    return 0;
  }
  reverse(todo.begin(), todo.end());
  vector<pair<int, char>> ans;
  for (auto x : todo) {
    if (x.S - x.F == 1) continue;
    int mx = *max_element(a + x.F, a + x.S);
    int pivot = -1, dir = 0;
    for (int i = x.F; i < x.S; ++i) if (a[i] == mx) {
      if (i > x.F && a[i] > a[i - 1]) pivot = i, dir = 0;
      if (i + 1 < x.S && a[i] > a[i + 1]) pivot = i, dir = 1;
    }
    if (pivot == -1) {
      puts("NO");
      return 0;
    }
    int l = pivot - x.F;
    int r = x.S - pivot - 1;
    if (dir == 0) {
      int cur = pivot + 1;
      REP(i, l) ans.EB(cur--, 'L');
      REP(i, r) ans.EB(cur, 'R');
    } else {
      int cur = pivot + 1;
      REP(i, r) ans.EB(cur, 'R');
      REP(i, l) ans.EB(cur--, 'L');
    }
  }
  puts("YES");
  for (auto x : ans) {
    printf("%d %c\n", x.F, x.S);
  }
  return 0;
}
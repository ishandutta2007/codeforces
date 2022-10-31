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

int n;
LL a[maxn];
LL s[maxn];
vector<PII> g[maxn];
int p[maxn][22];
int dep[maxn];
void dfs(int x, int fa, LL sum, int depth = 0) {
  s[x] = sum;
  p[x][0] = fa;
  dep[x] = depth;
  for (int i = 1; i < 22; ++i) {
    p[x][i] = p[p[x][i - 1]][i - 1];
  }
  for (auto it : g[x]) {
    dfs(it.F, x, sum + it.S, depth + 1);
  }
}

int delta[maxn], ans[maxn];

int dfs2(int x) {
  ans[x] = delta[x];
  for (auto it : g[x])
    ans[x] += dfs2(it.F);
  return ans[x];
}

int main() {
  R(n);
  REPE(i, 1, n) R(a[i]);
  REPE(i, 2, n) {
    int p, w;
    R(p, w);
    g[p].EB(i, w);
  }
  dfs(1, 1, 0);
  REPE(x, 1, n) {
    int cur = x;
    for (int i = 21; i >= 0; --i) {
      if (s[x] - s[p[cur][i]] <= a[x]) cur = p[cur][i];
    }
    int aa = x == 1 ? 0 : p[x][0];
    int bb = cur == 1 ? 0 : p[cur][0];
    delta[aa]++;
    delta[bb]--;
  }
  dfs2(1);
  REPE(i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}
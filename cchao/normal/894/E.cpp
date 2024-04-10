#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second
void R(int &x) { scanf("%d", &x); }
void R(LL &x) { scanf("%lld", &x); }
void R(double &x) { scanf("%lf", &x); }
template <typename T> void R(T &t) { cin >> t; }
template <typename T> void R(vector<T> &ar) {
  for (auto &it : ar)
    R(it);
}
template <typename T, typename... Args> void R(T &t, Args &... args) {
  R(t);
  R(args...);
}
const int maxn = 1e6 + 10;
vector<PII> g[maxn];
int pre[maxn], low[maxn], timer;
int sccno[maxn], scc_cnt;
stack<int> S;
int dfs(int x) {
  pre[x] = low[x] = ++timer;
  S.push(x);
  for (auto yy : g[x]) {
    int y = yy.F;
    if (!pre[y])
      low[x] = min(low[x], dfs(y));
    else if (!sccno[y])
      low[x] = min(low[x], pre[y]);
  }
  if (low[x] == pre[x]) {
    scc_cnt++;
    for (;;) {
      int t = S.top();
      S.pop();
      sccno[t] = scc_cnt;
      if (t == x)
        break;
    }
  }
  return low[x];
}
void directed(int n) {
  memset(pre, 0, sizeof pre);
  memset(sccno, 0, sizeof sccno);
  timer = scc_cnt = 0;
  for (int i = 0; i < n; ++i)
    if (!pre[i])
      dfs(i);
}
int n, m;

LL a[maxn];

int b[20000];
LL c[20000];

vector<PII> g2[maxn];

LL f(int x) {
  if (x <= 0) return x;
  int t = upper_bound(b, b + 20000, x) - b - 1;
  LL r = 1LL * (t + 1) * x - c[t];
  return r;
}

LL mm[maxn];
bool v[maxn];
LL solve(int x) {
  if (v[x]) return mm[x];
  v[x] = true;
  LL ret = 0;
  for (auto it : g2[x]) {
    ret = max(ret, solve(it.F) + it.S);
  }
  ret += a[x];
  return mm[x] = ret;
}

int main() {
  REP(i, 20000) {
    b[i] = i * (i + 1) / 2;
    c[i] = b[i];
    if (i) c[i] += c[i - 1];
  }
  R(n, m);
  REP(i, m) {
    int u, v, w;
    R(u, v, w);
    u--, v--;
    g[u].EB(v, w);
  }
  int s;
  R(s);
  s--;
  directed(n);
  REP(x, n) {
    for (auto yy : g[x]) {
      int y = yy.F, w = yy.S;
      int nx = sccno[x], ny = sccno[y];
      if (nx == ny) {
        a[nx] += f(w);
      } else {
        g2[nx].EB(ny, w);
      }
    }
  }
  printf("%lld\n", solve(sccno[s]));


  return 0;
}
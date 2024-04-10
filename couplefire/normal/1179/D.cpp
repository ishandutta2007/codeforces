#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define REP(i, s, t) for (int i = (s), i##ed = (t); i <= i##ed; i ++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <typename T> void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T> void chkmin(T &x, T y) {
  x = x < y ? x : y;
}
template <typename T> void read(T &x) {
  x = 0; bool w = 0; char ch = 0;
  for (; !isdigit(ch); ch = getchar()) w |= ch == '-';
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  x *= w ? -1 : 1;
}
template <typename T> void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T> void write(T x, char ch) {
  write(x);
  putchar(ch);
}
template <typename T> void writeln(T x) {
  write(x);
  puts("");
}
const int N = 5e5 + 5;
int sz[N];
long long s[N];
vector<int> g[N];
void dfs0(int u, int fa) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa) continue;
    dfs0(v, u);
    sz[u] += sz[v];
  }
}
void dfs1(int u, int fa) {
  for (auto v : g[u]) {
    if (v == fa) continue;
    s[v] = s[u] + (long long) (sz[u] - sz[v]) * sz[v];
    dfs1(v, u);
  }
}
int main() {
  int n; read(n);
  for (int i = 1; i < n; i ++) {
    int u, v; read(u); read(v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  s[1] = (long long) n * (n - 1) / 2;
  dfs0(1, 0);
  dfs1(1, 0);
  int x = 1;
  for (int i = 2; i <= n; i ++) {
    if (s[x] < s[i]) x = i;
  }
  s[x] = (long long) n * (n - 1) / 2;
  dfs0(x, 0);
  dfs1(x, 0);
  for (int i = 1; i <= n; i ++) {
    if (s[x] < s[i]) x = i;
  }
  writeln(s[x]);
  return 0; 
}
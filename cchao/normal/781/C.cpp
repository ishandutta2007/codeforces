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

int n, m, k;
const int maxn = 2e5 + 10;
vector<int> a;
vector<int> g[maxn];
bool v[maxn];
void dfs(int x) {
  a.PB(x);
  v[x] = true;
  for (int y : g[x]) if (!v[y]) {
    dfs(y);
    a.PB(x);
  }
}

vector<int> ans[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  const int ub = (n + n + k - 1) / k;
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1);
  int no = 1;
  for (auto x : a) {
    ans[no].PB(x);
    if (SZ(ans[no]) == ub) no++;
  }
  REPE(i, 1, k) {
    if (ans[i].empty()) ans[i].PB(1);
    printf("%d", SZ(ans[i]));
    for (int x : ans[i])
      printf(" %d", x);
    puts("");
  }
  return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, k;
int arr[200002];
vector<int> g[200002];

int VAL;

int dp[200002], f[200002];

void dfs(int v, int p) {
  int s = 0, one = -1;
  for (int u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
    if (f[u]) s += dp[u];
    else one = max(one, dp[u]);
  }

  f[v] = one == -1;
  dp[v] = 1 + s + (one == -1 ? 0 : one);
  // cout << "V: " << v << endl;

  if (arr[v] < VAL) {
    dp[v] = 0;
    f[v] = false;
  }
}

int ans = 0;

void go(int v, int p, int val, bool full) {
  int mi1 = -1, mi2 = -1, s = 0;
  dp[n] = val; f[n] = full;
  if (full) s += val;
  else if (p != -1) {
    mi1 = n;
  }
  for (int u : g[v]) {
    if (u == p) continue;
    if (f[u]) {
      s += dp[u];
    } else if (dp[u] > dp[mi1]) {
      mi2 = mi1;
      mi1 = u;
    } else if (dp[u] > dp[mi2]) {
      mi2 = u;
    }
  }

  if (arr[v] >= VAL) {
    ans = max(ans, 1 + s + (mi1 == -1 ? 0 : dp[mi1]));
    // cout << v << "  " << (1 + s + (mi1 == -1 ? 0 : dp[mi1])) << " " << val << " " << s << " " << mi1 << " " << mi2 << endl;
    for (int u : g[v]) {
      if (u == p) continue;
      dp[n] = val; f[n] = full;
      
      bool nfull = (mi1 == -1 || mi2 == -1 && mi1 == u);
      int nval = 1 + s;
      if (f[u]) nval -= dp[u];
      int one = u == mi1 ? mi2 : mi1;
      if (one != -1) nval += dp[one];
      // if (u == 4)
        // cout << nval << " " << one << " " << dp[one] << endl;
      go(u, v, nval, nfull);
    }
  } else {
    for (int u : g[v]) {
      if (u == p) continue;
      go(u, v, 0, false);
    }
  }
}

bool check(int m) {
  VAL = m;

  memset(dp, 0, sizeof(dp));
  memset(f, false, sizeof(f));

  ans = 0;
  dfs(0, -1);

  // for (int i = 0; i < n; ++i)
  //   cout << i << "  " << dp[i] << " " << f[i] << endl;

  go(0, -1, 0, true);

  return ans >= k;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // cout << check(5) << endl;
  // return 0;

  int l = 1, r = 1e+6 + 7;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (check(m)) l = m;
    else r = m;
  }
  cout << l << endl;

  return 0;
}
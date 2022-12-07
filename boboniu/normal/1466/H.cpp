#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 1000000007;

map<vector<array<int, 2>>, int> dp;

int n, p[50];
i64 C[50][50], fac[50];
long long Pow(int a, int b) {
  long long ans = 1;
  for (int i = 0; i < b; i++)
    ans = ans * a % P;
  return ans;
}
long long solve(vector<array<int, 2>> cycle) {
  if (dp.count(cycle))
    return dp[cycle];
  if (cycle.empty())
    return 1;
  int tot = 0;
  for (auto x : cycle)
    tot += x[0] * x[1];
  vector<array<int, 2>> rem;
  i64 ans = 0;
  function<void(int, int)> dfs = [&](int dep, i64 w) {
    if (dep == cycle.size()) {
      int ctot = 0;
      for (auto x : rem)
        ctot += x[0] * x[1];
      if (ctot == tot)
        return;
      ans = (ans + w * Pow(C[tot][ctot] * fac[tot - ctot] % P, ctot) % P *
                       solve(rem)) %
            P;
    } else {
      int c = cycle[dep][1], len = cycle[dep][0];
      for (int j = 0; j <= c; j++) {
        if (j != c)
          rem.push_back({len, c - j});
        dfs(dep + 1, w * C[c][j] % P);
        if (j != c)
          rem.pop_back();
        w = (P - w * Pow(fac[tot - 1], len) % P);
      }
    }
  };
  dfs(0, P - 1);
  return dp[cycle] = ans;
}

int vis[50], cnt[50];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % P;
  }

  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  /* for (int i = 1; i <= n; i++) {
     p[i] = i;
   }*/
  i64 ans = 0;
  // while (true) {
  for (int i = 1; i <= n; i++)
    vis[i] = 0, cnt[i] = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      int len = 0, j = i;
      while (true) {
        len += 1;
        vis[j] = true;
        j = p[j];
        if (j == i)
          break;
      }
      cnt[len] += 1;
    }
  vector<array<int, 2>> initc;
  for (int i = 1; i <= n; i++)
    if (cnt[i])
      initc.push_back({i, cnt[i]});
  i64 val = solve(initc);
  ans = (ans + val) % P;
  printf("%lld\n", val);
  // printf("%lld\n", solve(initc));
  // if (!next_permutation(p + 1, p + n + 1))
  //      break;
  //}
  // assert(ans == Pow(fac[n], n));
}
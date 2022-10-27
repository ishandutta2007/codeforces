#include <bits/stdc++.h>
const int mod = 31607;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ull * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ull * x * y % mod;}
inline int power(int a, int b, int c = 1) {for (; b; b >>= 1, mul(a, a)) if (b & 1) mul(c, a); return c;}
const int N = 22, S = 1 << 21 | 5;
int n, a[N][N], b[N][N], c[N], cc[N], pop[S], low[S], tr[S][N], par[S];
bool vis[N][N];
 
int solve() {
  int ans = 0;
  for (int s = 0; s < 1 << n; ++s) {
    if (!s) memcpy(tr[s], c, sizeof c), par[s] = 1;
    else {
      int k = low[s], t = s ^ (1 << k);
      memcpy(tr[s], tr[t], sizeof tr[t]), par[s] = par[t];
      for (int j = 0; j < n; ++j) 
        if (!vis[k][j]) mul(par[s], a[k][j]), mul(tr[s][j], b[k][j]);
    }
    int cur = par[s];
    for (int i = 0; i < n; ++i) mul(cur, Sub(1, tr[s][i]));
    if (pop[s] & 1) sub(ans, cur);
    else add(ans, cur);
  }
  return ans;
}
 
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) cc[i] = c[i] = 1;
  for (int i = 0; i < 1 << n; ++i) pop[i] = pop[i >> 1] + (i & 1);
  for (int i = 1; i < 1 << n; ++i) low[i] = (i & 1) ? 0 : (low[i >> 1] + 1);
  for (int i = 0; i < n; ++i)  
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      a[i][j] = power(10000, mod - 2, a[i][j]); // prob
      b[i][j] = power(a[i][j], mod - 2);
      mul(cc[j], a[i][j]), mul(c[j], a[i][j]);
    }
  auto color = [&](bool type) {
    int coef = 1;
    if (type) {
      for (int i = 0; i < n; ++i)
        if (!vis[i][i]) vis[i][i] = true, mul(coef, a[i][i]), mul(c[i], b[i][i]);
    } else {
      for (int i = 0; i < n; ++i) 
        if (!vis[i][n - 1 - i]) vis[i][n - 1 - i] = true, mul(coef, a[i][n - 1 - i]), mul(c[n - 1 - i], b[i][n - 1 - i]); 
    }
    return coef;
  };
  int ans = solve(), coef;
  
  coef = color(0), sub(ans, Mul(coef, solve()));
  
  memset(vis, false, sizeof vis);
  memcpy(c, cc, sizeof c);
  coef = color(1), sub(ans, Mul(coef, solve()));
  
  memset(vis, false, sizeof vis);
  memcpy(c, cc, sizeof c);
  coef = Mul(color(0), color(1)), add(ans, Mul(coef, solve()));
  
  printf("%d\n", Sub(1, ans));
  return 0;
}
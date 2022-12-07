#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
 
const int NX = 4005, KX = 80, mod = 998244353;

int k;

inline void add(int &u, int v) {
  u += v; u >= mod ? u -= mod : 0;
}

const LL mod_2 = (LL) mod * mod * 7;

inline void add(LL &u, LL v) {
  u += v; u >= mod_2 ? u -= mod_2 : 0;
}

struct Tree {
  int n, e_u[NX], e_v[NX], f[2][NX]; LL g[KX]; 
  void read_() {
    for (int i = 1; i < n; i++)
      scanf("%d%d", e_u + i, e_v + i);
  }
  
  void dp() {
    for (int x = 1; x <= n; x++) {
      memset(f, 0, sizeof(f));
      f[0][x] = 1;
      ++g[0];
      for (int l = 1; l <= (k >> 1); l++) {
        int p = l & 1, q = p ^ 1;
        memset(f[p], 0, sizeof(f[p]));
        for (int e = 1; e < n; e++) {
          int u = e_u[e];
          int v = e_v[e];
          add(f[p][u], f[q][v]);
          add(f[p][v], f[q][u]);
        }
        for (int y = 1; y <= n; y++)
          add(g[l << 1], (LL) f[p][y] * f[p][y]);
      }
    }  
    for (int l = 0; l <= k; l += 2) 
      g[l] %= mod;
  }
}a, b;

int c[KX][KX];

int main() {
  scanf("%d%d%d", &a.n, &b.n, &k);
  if (k & 1)
    return puts("0"), 0;
  a.read_();
  b.read_();
  for (int i = 0; i <= k; i++) {
    for (int j = c[i][0] = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  
  a.dp();
  b.dp();  
  int ans = 0;
  for (int x = 0; x <= k; x += 2) {
    int y = k - x;
    ans = (ans + (LL) c[k][x] * a.g[x] % mod * b.g[y]) % mod;
  } 
  
  cout << ans << "\n";
  return 0;
  
}
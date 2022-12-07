#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void read(int &x) {
  x = 0; char ch;
  while (!isdigit(ch = getchar()));
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

const int MaxN = 400010;
const int N = 1 << 18, G = 3;
const int mod = 998244353;

int exp(int a, int n) {
  int res = 1;
  for (; n; n >>= 1) {
    if (n & 1)
      res = (ll) res * a % mod;
    a = (ll) a * a % mod; 
  }
  return res;
}

int n, k;
vector<int> edge[MaxN];
int siz[MaxN];
int eps[MaxN], fac[MaxN], rfac[MaxN];

void preprocess() {
  int g = exp(G, (mod - 1) / N);
  eps[0] = 1;
  for (int i = 1; i < N; i++) eps[i] = (ll) eps[i - 1] * g % mod;
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = (ll) fac[i - 1] * i % mod;
  rfac[N- 1] = exp(fac[N - 1], mod - 2);
  for (int i = N - 1; i; i--) rfac[i - 1] = (ll) rfac[i] * i % mod;
}

void dft(int n, int x[]) {
  for (int i = 0, j = 0; i < n; i++) {
    if (i > j) swap(x[i], x[j]);
    for (int l = n >> 1; (j ^= l) < l; l >>= 1);
  }  
  for (int i = 2; i <= n; i <<= 1) {
    int l = i >> 1, d = N / i;
    for (int j = 0; j < n; j += i) {
      for (int k = 0; k < l; k++) {
        int t = (ll) eps[d * k] * x[j + k + l] % mod;
        x[j + k + l] = (x[j + k] + mod - t) % mod;
        x[j + k] = (x[j + k] + t) % mod;
      }
    }
  }
}

void idft(int n, int x[]) {
  dft(n, x); reverse(x + 1, x + n); 
  for (int i = 0, rn = exp(n, mod - 2); i < n; i++)
    x[i] = (ll) x[i] * rn % mod;
}

int da[MaxN], db[MaxN];
vector<int> mul(vector<int> a, vector<int> b) {
  int n = a.size() + b.size();
  for (int i = 0; i < n; i++) {
    da[i] = i < a.size() ? a[i] : 0;
    db[i] = i < b.size() ? b[i] : 0;
  }
  dft(n, da); dft(n, db);
  for (int i = 0; i < n; i++) da[i] = (ll) da[i] * db[i] % mod;
  idft(n, da);
  vector<int> c;
  for (int i = 0; i < n; i++) c.push_back(da[i]);
  return c;
}

int c(int n, int m) {
  return (ll) fac[n] * rfac[m] % mod * rfac[n - m] % mod;
}

int seq[MaxN << 1], f[MaxN], g[MaxN]; 
int cal(int n) {
  if (n < 1)
    return 1;
  for (int t = n << 1; (n & -n) != n; n++)
    seq[t++] = 1, seq[t++] = 0;
  int m = n << 1;
  for (int i = 4; i <= m; i <<= 1) {
    int l = i >> 1;
    for (int j = 0; j < m; j += i) {
      vector<int> x, y;
      for (int k = 0; k < l; k++)
        x.push_back(seq[j + k]),
        y.push_back(seq[j + k + l]);
      x = mul(x, y);
      for (int k = 0; k < i; k++)
        seq[j + k] = x[k]; 
    }
  }    
  int ans = 0;
  for (int i = 0; i < m && i <= k; i++)
    ans = (ans + (ll) seq[i] * fac[i] % mod * c(k, i)) % mod;
  return ans;
}

int ans;
void dfs1(int x, int fa = 0) {
  siz[x] = 1;
  for (int y : edge[x])
    if (y != fa) {
      dfs1(y, x);
      siz[x] += siz[y];
      ans = (ans + (ll) f[x] * f[y]) % mod;
      f[x] = (f[x] + f[y]) % mod;
    }
  
  int q = (int)edge[x].size() - (x != 1), t = 0;
  for (int y : edge[x])
    if (y != fa) seq[t++] = 1, seq[t++] = siz[y];
  f[x] = (f[x] + cal(q)) % mod;
  
  if (q) {
    if (x != 1) {
      seq[q + 1] = 0;
      for (int i = q; ~i; i--)
        seq[i + 1] = (seq[i + 1] + (ll) seq[i] * (n - siz[x])) % mod;
      ++q;
    }
    for (int y : edge[x]) {
      if (y != fa) {
        int p = siz[y];
        if (!g[p]) {
          int tmp = 0;
          for (int i = 0; i <= k && i < q; i++) {
            tmp = (seq[i] + mod - (ll) tmp * p % mod) % mod; 
            g[p] = (g[p] + (ll) fac[i] * tmp % mod * c(k, i)) % mod;
          }
        }
        ans = (ans + (ll) g[p] * f[y]) % mod;
      }
    }
    for (int y : edge[x])
      g[siz[y]] = 0;
  }
}

int main() {
  preprocess();
  read(n); read(k);
  if (k == 1)
    return printf("%lld\n", (ll) n * (n - 1) / 2 % mod), 0;
  for (int i = 1, u, v; i < n; i++) {
    read(u); read(v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }  
  
  dfs1(1, 0);
  
  cout << ans << "\n";
  return 0;
}
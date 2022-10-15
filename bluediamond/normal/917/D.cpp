#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 100 + 7;
int n, dp[N][N][N], sub[N], ret[N];
vector<int> g[N];

int old[N][N];
int nw[N][N];

void baga(int &x, int val) {
  x = add(x, val);
}

void dfs(int a, int p = -1) {
  vector<int> kids;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
    kids.push_back(b);
    sub[a] += sub[b];
  }
  g[a] = kids;
  int cur = 1;
  old[1][0] = 1;
  for (auto &b : g[a]) {
    for (int sz = 1; sz <= cur; sz++) {
      for (int cnt = 0; cnt < cur; cnt++) {
        if (!old[sz][cnt]) continue;
        for (int sb = 1; sb <= sub[b]; sb++) {
          for (int cb = 0; cb < sub[b]; cb++) {

            int prod = mul(old[sz][cnt], dp[b][sb][cb]);
            baga(nw[sz + sb][cnt + cb], prod);

            baga(nw[sz][cnt + cb + 1], mul(prod, sb));

          }
        }
      }
    }
    cur += sub[b];
    for (int sz = 0; sz <= cur; sz++) {
      for (int cnt = 0; cnt < cur; cnt++) {
        old[sz][cnt] = nw[sz][cnt];
        nw[sz][cnt] = 0;
      }
    }
  }
  assert(cur == sub[a]);
  for (int sz = 1; sz <= cur; sz++){
    for (int cnt = 0; cnt < cur; cnt++) {
      dp[a][sz][cnt] = old[sz][cnt];
    }
  }
}

int fact[N], ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed realMain() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  for (int last = 1; last <= n; last++) {
    for (int cnt = 0; cnt <= n - 1; cnt++) {
      int now = mul(dp[1][last][cnt], last);
      ret[n - 1 - cnt] = add(ret[n - 1 - cnt], now);
    }
  }
  for (int k = 0; k < n; k++) {
    if (n - k >= 2) {
      ret[k] = mul(ret[k], pw(n, n - k - 2));
    } else {
      ret[k] = 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      ret[i] = add(ret[i], -mul(ret[j], comb(j, i)));
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ret[i] << " ";
  }
  cout << "\n";
  return 0;
}
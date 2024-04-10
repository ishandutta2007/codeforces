#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
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

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N = (int) 2e5 + 7;
int n, k, fact[N], ifact[N], comb[N];
vector<int> g[N];

int get_comb(int n, int k) {
  assert(0 <= k && k <= n && n < N);
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int sub[N], sum[N], sc[N], print;

void compute(int a, int p = -1) {
  sub[a] = 1;
  sum[a] = 0;
  sc[a] = 0;
  for (auto &b : g[a]) {
    if (b == p) continue;
    sub[a] += sub[b];
    addup(sc[a], -comb[sub[b]]);
    addup(sum[a], sum[b]);
  }
  addup(sc[a], +comb[sub[a]]);
  addup(sum[a], mul(sc[a], sub[a]));
}

void dfs(int a, int p = -1) {
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
  }
  compute(a);
}

void reroot(int a, int p) {
  assert(1 <= a && a <= n);
  assert(1 <= p && p <= n);
  addup(sum[a], -mul(sc[a], sub[a]));
  addup(sc[a], -comb[sub[a]]);
  sub[a] -= sub[p];
  addup(sum[a], -sum[p]);
  addup(sc[a], comb[sub[p]]);
  addup(sc[a], comb[sub[a]]);
  addup(sum[a], mul(sc[a], sub[a]));
  addup(sum[p], -mul(sc[p], sub[p]));
  addup(sc[p], -comb[sub[p]]);
  sub[p] = n;
  addup(sc[p], -comb[sub[a]]);
  addup(sum[p], sum[a]);
  addup(sc[p], comb[sub[p]]);
  addup(sum[p], mul(sc[p], sub[p]));
}

void solve(int a, int p = -1) {
  addup(print, sum[a]);
  for (auto &b : g[a]) {
    if (b == p) continue;
    reroot(a, b);
    solve(b, a);
    reroot(b, a);
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

  cin >> n >> k;


  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = k; i <= n; i++) {
    comb[i] = get_comb(i, k);
  }

  dfs(1);
  solve(1);

  cout << print << "\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

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

void addup(int &a, int x) {
  a = add(a, x);
}

const int P = 31;
const int INVP = dv(1, P);
const int BZ = 1 << 23;

void fft(vector<int> &a, bool inv) {
  int n = (int) a.size(), k = log2(n);
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (int bit = 0; bit < k; bit++) {
      if (i & (1 << bit)) j += (1 << (k - 1 - bit));
    }
    if (i < j) swap(a[i], a[j]);
  }
  for (int l = 2; l <= n; l *= 2) {
    int mlt = inv ? INVP : P;
    for (int j = l; j < BZ; j *= 2) mlt = mul(mlt, mlt);
    for (int i = 0; i < n; i += l) {
      int cur = 1;
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j];
        int y = mul(cur, a[i + l / 2 + j]);
        a[i + j] = add(x, y);
        a[i + l / 2 + j] = add(x, -y);
        cur = mul(cur, mlt);
      }
    }
  }
  if (inv) {
    int invn = dv(1, n);
    for (auto &x : a) x = mul(x, invn);
  }
}

void pop(vector<int> &a) {
  while (!a.empty() && a.back() == 0) a.pop_back();
}

vector<int> mult(vector<int> a, vector<int> b) {
  pop(a);
  pop(b);
  int n = 1;
  while (n <= (int) a.size() + (int) b.size()) n *= 2;
  a.resize(n, 0);
  b.resize(n, 0);
  fft(a, 0);
  fft(b, 0);
  for (int i = 0; i < n; i++) a[i] = mul(a[i], b[i]);
  fft(a, 1);
  pop(a);
  return a;
}

const int N = (int) 3e5 + 7;
const int K = 5 + 7;
int n, k, a[N], b[K], q, qs[N], fact[N], ifact[N], f[N], total[4 * N], kek[2 * N], p2[N], inv[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);



 /// freopen ("input", "r", stdin);

  p2[0] = 1;
  for (int i = 1; i < N; i++) p2[i] = mul(p2[i - 1], 2);
  inv[N - 1] = dv(1, p2[N - 1]);
  for (int i = N - 2; i >= 0; i--) inv[i] = mul(inv[i + 1], 2);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }

  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) cin >> b[i];
  cin >> q;
  for (int i = 1; i <= q; i++) cin >> qs[i];

  for (int ib = 1; ib <= k; ib++) {
    for (int i = 0; i < N; i++) f[i] = 0;
    for (int i = 0; i <= n; i++) kek[i] = 0;

    int tot1, tot2;
    tot1 = tot2 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= b[ib]) continue;
      f[a[i]]++;
      if (f[a[i]] == 1) tot1++;
      if (f[a[i]] == 2) tot1--, tot2++;
    }
    vector<int> k1(tot1 + 1), k2(2 * tot2 + 1);
    for (int x = 0; x <= tot1; x++) k1[x] = mul(comb(tot1, x), p2[x]);
    for (int y = 0; y <= 2 * tot2; y++) k2[y] = comb(2 * tot2, y);
    vector<int> k3 = mult(k1, k2);
    for (int i = 0; i <= n; i++) {
      int perim = 2 * (b[ib] + i + 1);
      addup(total[perim], i < (int) k3.size() ? k3[i] : 0);
    }
  }


  for (int i = 1; i <= q; i++) {
    cout << total[qs[i]] << "\n";
  }

  return 0;
}
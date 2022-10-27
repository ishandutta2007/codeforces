#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long long ll;
typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int add(int a, int b, int c) {
  return add(add(a, b), c);
}

int mul(int a, int b, int c) {
  return mul(mul(a, b), c);
}

int add(int a, int b, int c, int d) {
  return add(add(a, b, c), d);
}

int mul(int a, int b, int c, int d) {
  return mul(mul(a, b, c), d);
}

int add(int a, int b, int c, int d, int e) {
  return add(add(a, b, c, d), e);
}

int mul(int a, int b, int c, int d, int e) {
  return mul(mul(a, b, c, d), e);
}

int add(int a, int b, int c, int d, int e, int f) {
  return add(add(a, b, c, d, e), f);
}

int mul(int a, int b, int c, int d, int e, int f) {
  return mul(mul(a, b, c, d, e), f);
}

int add(int a, int b, int c, int d, int e, int f, int g) {
  return add(add(a, b, c, d, e, f), g);
}

int mul(int a, int b, int c, int d, int e, int f, int g) {
  return mul(mul(a, b, c, d, e, f), g);
}

int add(int a, int b, int c, int d, int e, int f, int g, int h) {
  return add(add(a, b, c, d, e, f, g), h);
}

int mul(int a, int b, int c, int d, int e, int f, int g, int h) {
  return mul(mul(a, b, c, d, e, f, g), h);
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

void dvup(int& a, int b) {
  a = dv(a, b);
}

const int K = 17;
int fact[K];
int ifact[K];
int dp[1 << K][K];
int ndp[1 << K][K];
int mx[1 << K];
int cb[K][K];


void computeFACT() {
  fact[0] = 1;
  for (int i = 1; i < K; i++) fact[i] = mul(fact[i - 1], i);
  ifact[K - 1] = dv(1, fact[K - 1]);
  for (int i = K - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
}



int main() {
  computeFACT();
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE
  for (int sub = 0; sub < K; sub++) {
    for (int u = 0; sub + u < K; u++) {
      cb[sub][u] = mul(fact[u + sub], ifact[u], ifact[sub]);
    }
  }

  int n, k, c;
  cin >> n >> k >> c;

  for (int x = k; x < (1 << c); x++) {
    for (int sub = 0; sub <= k; sub++) {
      mx[x] = max(mx[x], x ^ (x - sub));
    }
  }

  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }

  sort(a.begin(), a.end(), [&](int i, int j) {return mx[i] < mx[j]; });



  dp[0][0] = 1;
  int dim = 1;
  int ttl = 0;
  for (auto& cur : a) {
    ttl ^= cur;
    while (!(mx[cur] < dim)) {
      dim *= 2;
    }
    for (int x = 0; x < dim; x++) {
      ndp[x ^ cur ^ (cur - 0)][0] = (ndp[x ^ cur ^ (cur - 0)][0] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][1] = (ndp[x ^ cur ^ (cur - 0)][1] + dp[x][1] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][2] = (ndp[x ^ cur ^ (cur - 0)][2] + dp[x][2] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][3] = (ndp[x ^ cur ^ (cur - 0)][3] + dp[x][3] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][4] = (ndp[x ^ cur ^ (cur - 0)][4] + dp[x][4] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][5] = (ndp[x ^ cur ^ (cur - 0)][5] + dp[x][5] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][6] = (ndp[x ^ cur ^ (cur - 0)][6] + dp[x][6] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][7] = (ndp[x ^ cur ^ (cur - 0)][7] + dp[x][7] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][8] = (ndp[x ^ cur ^ (cur - 0)][8] + dp[x][8] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][9] = (ndp[x ^ cur ^ (cur - 0)][9] + dp[x][9] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][10] = (ndp[x ^ cur ^ (cur - 0)][10] + dp[x][10] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][11] = (ndp[x ^ cur ^ (cur - 0)][11] + dp[x][11] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][12] = (ndp[x ^ cur ^ (cur - 0)][12] + dp[x][12] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][13] = (ndp[x ^ cur ^ (cur - 0)][13] + dp[x][13] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][14] = (ndp[x ^ cur ^ (cur - 0)][14] + dp[x][14] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][15] = (ndp[x ^ cur ^ (cur - 0)][15] + dp[x][15] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 0)][16] = (ndp[x ^ cur ^ (cur - 0)][16] + dp[x][16] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 1)][1] = (ndp[x ^ cur ^ (cur - 1)][1] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 1)][2] = (ndp[x ^ cur ^ (cur - 1)][2] + dp[x][1] * 1LL * 2) % M;
      ndp[x ^ cur ^ (cur - 1)][3] = (ndp[x ^ cur ^ (cur - 1)][3] + dp[x][2] * 1LL * 3) % M;
      ndp[x ^ cur ^ (cur - 1)][4] = (ndp[x ^ cur ^ (cur - 1)][4] + dp[x][3] * 1LL * 4) % M;
      ndp[x ^ cur ^ (cur - 1)][5] = (ndp[x ^ cur ^ (cur - 1)][5] + dp[x][4] * 1LL * 5) % M;
      ndp[x ^ cur ^ (cur - 1)][6] = (ndp[x ^ cur ^ (cur - 1)][6] + dp[x][5] * 1LL * 6) % M;
      ndp[x ^ cur ^ (cur - 1)][7] = (ndp[x ^ cur ^ (cur - 1)][7] + dp[x][6] * 1LL * 7) % M;
      ndp[x ^ cur ^ (cur - 1)][8] = (ndp[x ^ cur ^ (cur - 1)][8] + dp[x][7] * 1LL * 8) % M;
      ndp[x ^ cur ^ (cur - 1)][9] = (ndp[x ^ cur ^ (cur - 1)][9] + dp[x][8] * 1LL * 9) % M;
      ndp[x ^ cur ^ (cur - 1)][10] = (ndp[x ^ cur ^ (cur - 1)][10] + dp[x][9] * 1LL * 10) % M;
      ndp[x ^ cur ^ (cur - 1)][11] = (ndp[x ^ cur ^ (cur - 1)][11] + dp[x][10] * 1LL * 11) % M;
      ndp[x ^ cur ^ (cur - 1)][12] = (ndp[x ^ cur ^ (cur - 1)][12] + dp[x][11] * 1LL * 12) % M;
      ndp[x ^ cur ^ (cur - 1)][13] = (ndp[x ^ cur ^ (cur - 1)][13] + dp[x][12] * 1LL * 13) % M;
      ndp[x ^ cur ^ (cur - 1)][14] = (ndp[x ^ cur ^ (cur - 1)][14] + dp[x][13] * 1LL * 14) % M;
      ndp[x ^ cur ^ (cur - 1)][15] = (ndp[x ^ cur ^ (cur - 1)][15] + dp[x][14] * 1LL * 15) % M;
      ndp[x ^ cur ^ (cur - 1)][16] = (ndp[x ^ cur ^ (cur - 1)][16] + dp[x][15] * 1LL * 16) % M;
      ndp[x ^ cur ^ (cur - 2)][2] = (ndp[x ^ cur ^ (cur - 2)][2] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 2)][3] = (ndp[x ^ cur ^ (cur - 2)][3] + dp[x][1] * 1LL * 3) % M;
      ndp[x ^ cur ^ (cur - 2)][4] = (ndp[x ^ cur ^ (cur - 2)][4] + dp[x][2] * 1LL * 6) % M;
      ndp[x ^ cur ^ (cur - 2)][5] = (ndp[x ^ cur ^ (cur - 2)][5] + dp[x][3] * 1LL * 10) % M;
      ndp[x ^ cur ^ (cur - 2)][6] = (ndp[x ^ cur ^ (cur - 2)][6] + dp[x][4] * 1LL * 15) % M;
      ndp[x ^ cur ^ (cur - 2)][7] = (ndp[x ^ cur ^ (cur - 2)][7] + dp[x][5] * 1LL * 21) % M;
      ndp[x ^ cur ^ (cur - 2)][8] = (ndp[x ^ cur ^ (cur - 2)][8] + dp[x][6] * 1LL * 28) % M;
      ndp[x ^ cur ^ (cur - 2)][9] = (ndp[x ^ cur ^ (cur - 2)][9] + dp[x][7] * 1LL * 36) % M;
      ndp[x ^ cur ^ (cur - 2)][10] = (ndp[x ^ cur ^ (cur - 2)][10] + dp[x][8] * 1LL * 45) % M;
      ndp[x ^ cur ^ (cur - 2)][11] = (ndp[x ^ cur ^ (cur - 2)][11] + dp[x][9] * 1LL * 55) % M;
      ndp[x ^ cur ^ (cur - 2)][12] = (ndp[x ^ cur ^ (cur - 2)][12] + dp[x][10] * 1LL * 66) % M;
      ndp[x ^ cur ^ (cur - 2)][13] = (ndp[x ^ cur ^ (cur - 2)][13] + dp[x][11] * 1LL * 78) % M;
      ndp[x ^ cur ^ (cur - 2)][14] = (ndp[x ^ cur ^ (cur - 2)][14] + dp[x][12] * 1LL * 91) % M;
      ndp[x ^ cur ^ (cur - 2)][15] = (ndp[x ^ cur ^ (cur - 2)][15] + dp[x][13] * 1LL * 105) % M;
      ndp[x ^ cur ^ (cur - 2)][16] = (ndp[x ^ cur ^ (cur - 2)][16] + dp[x][14] * 1LL * 120) % M;
      ndp[x ^ cur ^ (cur - 3)][3] = (ndp[x ^ cur ^ (cur - 3)][3] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 3)][4] = (ndp[x ^ cur ^ (cur - 3)][4] + dp[x][1] * 1LL * 4) % M;
      ndp[x ^ cur ^ (cur - 3)][5] = (ndp[x ^ cur ^ (cur - 3)][5] + dp[x][2] * 1LL * 10) % M;
      ndp[x ^ cur ^ (cur - 3)][6] = (ndp[x ^ cur ^ (cur - 3)][6] + dp[x][3] * 1LL * 20) % M;
      ndp[x ^ cur ^ (cur - 3)][7] = (ndp[x ^ cur ^ (cur - 3)][7] + dp[x][4] * 1LL * 35) % M;
      ndp[x ^ cur ^ (cur - 3)][8] = (ndp[x ^ cur ^ (cur - 3)][8] + dp[x][5] * 1LL * 56) % M;
      ndp[x ^ cur ^ (cur - 3)][9] = (ndp[x ^ cur ^ (cur - 3)][9] + dp[x][6] * 1LL * 84) % M;
      ndp[x ^ cur ^ (cur - 3)][10] = (ndp[x ^ cur ^ (cur - 3)][10] + dp[x][7] * 1LL * 120) % M;
      ndp[x ^ cur ^ (cur - 3)][11] = (ndp[x ^ cur ^ (cur - 3)][11] + dp[x][8] * 1LL * 165) % M;
      ndp[x ^ cur ^ (cur - 3)][12] = (ndp[x ^ cur ^ (cur - 3)][12] + dp[x][9] * 1LL * 220) % M;
      ndp[x ^ cur ^ (cur - 3)][13] = (ndp[x ^ cur ^ (cur - 3)][13] + dp[x][10] * 1LL * 286) % M;
      ndp[x ^ cur ^ (cur - 3)][14] = (ndp[x ^ cur ^ (cur - 3)][14] + dp[x][11] * 1LL * 364) % M;
      ndp[x ^ cur ^ (cur - 3)][15] = (ndp[x ^ cur ^ (cur - 3)][15] + dp[x][12] * 1LL * 455) % M;
      ndp[x ^ cur ^ (cur - 3)][16] = (ndp[x ^ cur ^ (cur - 3)][16] + dp[x][13] * 1LL * 560) % M;
      ndp[x ^ cur ^ (cur - 4)][4] = (ndp[x ^ cur ^ (cur - 4)][4] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 4)][5] = (ndp[x ^ cur ^ (cur - 4)][5] + dp[x][1] * 1LL * 5) % M;
      ndp[x ^ cur ^ (cur - 4)][6] = (ndp[x ^ cur ^ (cur - 4)][6] + dp[x][2] * 1LL * 15) % M;
      ndp[x ^ cur ^ (cur - 4)][7] = (ndp[x ^ cur ^ (cur - 4)][7] + dp[x][3] * 1LL * 35) % M;
      ndp[x ^ cur ^ (cur - 4)][8] = (ndp[x ^ cur ^ (cur - 4)][8] + dp[x][4] * 1LL * 70) % M;
      ndp[x ^ cur ^ (cur - 4)][9] = (ndp[x ^ cur ^ (cur - 4)][9] + dp[x][5] * 1LL * 126) % M;
      ndp[x ^ cur ^ (cur - 4)][10] = (ndp[x ^ cur ^ (cur - 4)][10] + dp[x][6] * 1LL * 210) % M;
      ndp[x ^ cur ^ (cur - 4)][11] = (ndp[x ^ cur ^ (cur - 4)][11] + dp[x][7] * 1LL * 330) % M;
      ndp[x ^ cur ^ (cur - 4)][12] = (ndp[x ^ cur ^ (cur - 4)][12] + dp[x][8] * 1LL * 495) % M;
      ndp[x ^ cur ^ (cur - 4)][13] = (ndp[x ^ cur ^ (cur - 4)][13] + dp[x][9] * 1LL * 715) % M;
      ndp[x ^ cur ^ (cur - 4)][14] = (ndp[x ^ cur ^ (cur - 4)][14] + dp[x][10] * 1LL * 1001) % M;
      ndp[x ^ cur ^ (cur - 4)][15] = (ndp[x ^ cur ^ (cur - 4)][15] + dp[x][11] * 1LL * 1365) % M;
      ndp[x ^ cur ^ (cur - 4)][16] = (ndp[x ^ cur ^ (cur - 4)][16] + dp[x][12] * 1LL * 1820) % M;
      ndp[x ^ cur ^ (cur - 5)][5] = (ndp[x ^ cur ^ (cur - 5)][5] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 5)][6] = (ndp[x ^ cur ^ (cur - 5)][6] + dp[x][1] * 1LL * 6) % M;
      ndp[x ^ cur ^ (cur - 5)][7] = (ndp[x ^ cur ^ (cur - 5)][7] + dp[x][2] * 1LL * 21) % M;
      ndp[x ^ cur ^ (cur - 5)][8] = (ndp[x ^ cur ^ (cur - 5)][8] + dp[x][3] * 1LL * 56) % M;
      ndp[x ^ cur ^ (cur - 5)][9] = (ndp[x ^ cur ^ (cur - 5)][9] + dp[x][4] * 1LL * 126) % M;
      ndp[x ^ cur ^ (cur - 5)][10] = (ndp[x ^ cur ^ (cur - 5)][10] + dp[x][5] * 1LL * 252) % M;
      ndp[x ^ cur ^ (cur - 5)][11] = (ndp[x ^ cur ^ (cur - 5)][11] + dp[x][6] * 1LL * 462) % M;
      ndp[x ^ cur ^ (cur - 5)][12] = (ndp[x ^ cur ^ (cur - 5)][12] + dp[x][7] * 1LL * 792) % M;
      ndp[x ^ cur ^ (cur - 5)][13] = (ndp[x ^ cur ^ (cur - 5)][13] + dp[x][8] * 1LL * 1287) % M;
      ndp[x ^ cur ^ (cur - 5)][14] = (ndp[x ^ cur ^ (cur - 5)][14] + dp[x][9] * 1LL * 2002) % M;
      ndp[x ^ cur ^ (cur - 5)][15] = (ndp[x ^ cur ^ (cur - 5)][15] + dp[x][10] * 1LL * 3003) % M;
      ndp[x ^ cur ^ (cur - 5)][16] = (ndp[x ^ cur ^ (cur - 5)][16] + dp[x][11] * 1LL * 4368) % M;
      ndp[x ^ cur ^ (cur - 6)][6] = (ndp[x ^ cur ^ (cur - 6)][6] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 6)][7] = (ndp[x ^ cur ^ (cur - 6)][7] + dp[x][1] * 1LL * 7) % M;
      ndp[x ^ cur ^ (cur - 6)][8] = (ndp[x ^ cur ^ (cur - 6)][8] + dp[x][2] * 1LL * 28) % M;
      ndp[x ^ cur ^ (cur - 6)][9] = (ndp[x ^ cur ^ (cur - 6)][9] + dp[x][3] * 1LL * 84) % M;
      ndp[x ^ cur ^ (cur - 6)][10] = (ndp[x ^ cur ^ (cur - 6)][10] + dp[x][4] * 1LL * 210) % M;
      ndp[x ^ cur ^ (cur - 6)][11] = (ndp[x ^ cur ^ (cur - 6)][11] + dp[x][5] * 1LL * 462) % M;
      ndp[x ^ cur ^ (cur - 6)][12] = (ndp[x ^ cur ^ (cur - 6)][12] + dp[x][6] * 1LL * 924) % M;
      ndp[x ^ cur ^ (cur - 6)][13] = (ndp[x ^ cur ^ (cur - 6)][13] + dp[x][7] * 1LL * 1716) % M;
      ndp[x ^ cur ^ (cur - 6)][14] = (ndp[x ^ cur ^ (cur - 6)][14] + dp[x][8] * 1LL * 3003) % M;
      ndp[x ^ cur ^ (cur - 6)][15] = (ndp[x ^ cur ^ (cur - 6)][15] + dp[x][9] * 1LL * 5005) % M;
      ndp[x ^ cur ^ (cur - 6)][16] = (ndp[x ^ cur ^ (cur - 6)][16] + dp[x][10] * 1LL * 8008) % M;
      ndp[x ^ cur ^ (cur - 7)][7] = (ndp[x ^ cur ^ (cur - 7)][7] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 7)][8] = (ndp[x ^ cur ^ (cur - 7)][8] + dp[x][1] * 1LL * 8) % M;
      ndp[x ^ cur ^ (cur - 7)][9] = (ndp[x ^ cur ^ (cur - 7)][9] + dp[x][2] * 1LL * 36) % M;
      ndp[x ^ cur ^ (cur - 7)][10] = (ndp[x ^ cur ^ (cur - 7)][10] + dp[x][3] * 1LL * 120) % M;
      ndp[x ^ cur ^ (cur - 7)][11] = (ndp[x ^ cur ^ (cur - 7)][11] + dp[x][4] * 1LL * 330) % M;
      ndp[x ^ cur ^ (cur - 7)][12] = (ndp[x ^ cur ^ (cur - 7)][12] + dp[x][5] * 1LL * 792) % M;
      ndp[x ^ cur ^ (cur - 7)][13] = (ndp[x ^ cur ^ (cur - 7)][13] + dp[x][6] * 1LL * 1716) % M;
      ndp[x ^ cur ^ (cur - 7)][14] = (ndp[x ^ cur ^ (cur - 7)][14] + dp[x][7] * 1LL * 3432) % M;
      ndp[x ^ cur ^ (cur - 7)][15] = (ndp[x ^ cur ^ (cur - 7)][15] + dp[x][8] * 1LL * 6435) % M;
      ndp[x ^ cur ^ (cur - 7)][16] = (ndp[x ^ cur ^ (cur - 7)][16] + dp[x][9] * 1LL * 11440) % M;
      ndp[x ^ cur ^ (cur - 8)][8] = (ndp[x ^ cur ^ (cur - 8)][8] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 8)][9] = (ndp[x ^ cur ^ (cur - 8)][9] + dp[x][1] * 1LL * 9) % M;
      ndp[x ^ cur ^ (cur - 8)][10] = (ndp[x ^ cur ^ (cur - 8)][10] + dp[x][2] * 1LL * 45) % M;
      ndp[x ^ cur ^ (cur - 8)][11] = (ndp[x ^ cur ^ (cur - 8)][11] + dp[x][3] * 1LL * 165) % M;
      ndp[x ^ cur ^ (cur - 8)][12] = (ndp[x ^ cur ^ (cur - 8)][12] + dp[x][4] * 1LL * 495) % M;
      ndp[x ^ cur ^ (cur - 8)][13] = (ndp[x ^ cur ^ (cur - 8)][13] + dp[x][5] * 1LL * 1287) % M;
      ndp[x ^ cur ^ (cur - 8)][14] = (ndp[x ^ cur ^ (cur - 8)][14] + dp[x][6] * 1LL * 3003) % M;
      ndp[x ^ cur ^ (cur - 8)][15] = (ndp[x ^ cur ^ (cur - 8)][15] + dp[x][7] * 1LL * 6435) % M;
      ndp[x ^ cur ^ (cur - 8)][16] = (ndp[x ^ cur ^ (cur - 8)][16] + dp[x][8] * 1LL * 12870) % M;
      ndp[x ^ cur ^ (cur - 9)][9] = (ndp[x ^ cur ^ (cur - 9)][9] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 9)][10] = (ndp[x ^ cur ^ (cur - 9)][10] + dp[x][1] * 1LL * 10) % M;
      ndp[x ^ cur ^ (cur - 9)][11] = (ndp[x ^ cur ^ (cur - 9)][11] + dp[x][2] * 1LL * 55) % M;
      ndp[x ^ cur ^ (cur - 9)][12] = (ndp[x ^ cur ^ (cur - 9)][12] + dp[x][3] * 1LL * 220) % M;
      ndp[x ^ cur ^ (cur - 9)][13] = (ndp[x ^ cur ^ (cur - 9)][13] + dp[x][4] * 1LL * 715) % M;
      ndp[x ^ cur ^ (cur - 9)][14] = (ndp[x ^ cur ^ (cur - 9)][14] + dp[x][5] * 1LL * 2002) % M;
      ndp[x ^ cur ^ (cur - 9)][15] = (ndp[x ^ cur ^ (cur - 9)][15] + dp[x][6] * 1LL * 5005) % M;
      ndp[x ^ cur ^ (cur - 9)][16] = (ndp[x ^ cur ^ (cur - 9)][16] + dp[x][7] * 1LL * 11440) % M;
      ndp[x ^ cur ^ (cur - 10)][10] = (ndp[x ^ cur ^ (cur - 10)][10] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 10)][11] = (ndp[x ^ cur ^ (cur - 10)][11] + dp[x][1] * 1LL * 11) % M;
      ndp[x ^ cur ^ (cur - 10)][12] = (ndp[x ^ cur ^ (cur - 10)][12] + dp[x][2] * 1LL * 66) % M;
      ndp[x ^ cur ^ (cur - 10)][13] = (ndp[x ^ cur ^ (cur - 10)][13] + dp[x][3] * 1LL * 286) % M;
      ndp[x ^ cur ^ (cur - 10)][14] = (ndp[x ^ cur ^ (cur - 10)][14] + dp[x][4] * 1LL * 1001) % M;
      ndp[x ^ cur ^ (cur - 10)][15] = (ndp[x ^ cur ^ (cur - 10)][15] + dp[x][5] * 1LL * 3003) % M;
      ndp[x ^ cur ^ (cur - 10)][16] = (ndp[x ^ cur ^ (cur - 10)][16] + dp[x][6] * 1LL * 8008) % M;
      ndp[x ^ cur ^ (cur - 11)][11] = (ndp[x ^ cur ^ (cur - 11)][11] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 11)][12] = (ndp[x ^ cur ^ (cur - 11)][12] + dp[x][1] * 1LL * 12) % M;
      ndp[x ^ cur ^ (cur - 11)][13] = (ndp[x ^ cur ^ (cur - 11)][13] + dp[x][2] * 1LL * 78) % M;
      ndp[x ^ cur ^ (cur - 11)][14] = (ndp[x ^ cur ^ (cur - 11)][14] + dp[x][3] * 1LL * 364) % M;
      ndp[x ^ cur ^ (cur - 11)][15] = (ndp[x ^ cur ^ (cur - 11)][15] + dp[x][4] * 1LL * 1365) % M;
      ndp[x ^ cur ^ (cur - 11)][16] = (ndp[x ^ cur ^ (cur - 11)][16] + dp[x][5] * 1LL * 4368) % M;
      ndp[x ^ cur ^ (cur - 12)][12] = (ndp[x ^ cur ^ (cur - 12)][12] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 12)][13] = (ndp[x ^ cur ^ (cur - 12)][13] + dp[x][1] * 1LL * 13) % M;
      ndp[x ^ cur ^ (cur - 12)][14] = (ndp[x ^ cur ^ (cur - 12)][14] + dp[x][2] * 1LL * 91) % M;
      ndp[x ^ cur ^ (cur - 12)][15] = (ndp[x ^ cur ^ (cur - 12)][15] + dp[x][3] * 1LL * 455) % M;
      ndp[x ^ cur ^ (cur - 12)][16] = (ndp[x ^ cur ^ (cur - 12)][16] + dp[x][4] * 1LL * 1820) % M;
      ndp[x ^ cur ^ (cur - 13)][13] = (ndp[x ^ cur ^ (cur - 13)][13] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 13)][14] = (ndp[x ^ cur ^ (cur - 13)][14] + dp[x][1] * 1LL * 14) % M;
      ndp[x ^ cur ^ (cur - 13)][15] = (ndp[x ^ cur ^ (cur - 13)][15] + dp[x][2] * 1LL * 105) % M;
      ndp[x ^ cur ^ (cur - 13)][16] = (ndp[x ^ cur ^ (cur - 13)][16] + dp[x][3] * 1LL * 560) % M;
      ndp[x ^ cur ^ (cur - 14)][14] = (ndp[x ^ cur ^ (cur - 14)][14] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 14)][15] = (ndp[x ^ cur ^ (cur - 14)][15] + dp[x][1] * 1LL * 15) % M;
      ndp[x ^ cur ^ (cur - 14)][16] = (ndp[x ^ cur ^ (cur - 14)][16] + dp[x][2] * 1LL * 120) % M;
      ndp[x ^ cur ^ (cur - 15)][15] = (ndp[x ^ cur ^ (cur - 15)][15] + dp[x][0] * 1LL * 1) % M;
      ndp[x ^ cur ^ (cur - 15)][16] = (ndp[x ^ cur ^ (cur - 15)][16] + dp[x][1] * 1LL * 16) % M;
      ndp[x ^ cur ^ (cur - 16)][16] = (ndp[x ^ cur ^ (cur - 16)][16] + dp[x][0] * 1LL * 1) % M;
    }
    for (int x = 0; x < dim; x++) {
      for (int u = 0; u <= k; u++) {
        dp[x][u] = ndp[x][u];
        ndp[x][u] = 0;
      }
    }
  }

  int mlt = dv(1, pw(n, k));
  for (int i = 0; i < (1 << c); i++) {
    cout << mul(dp[i ^ ttl][k], mlt) << " ";
  }
  cout << "\n";

}
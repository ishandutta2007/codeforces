#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 

bool home = true;
using namespace std;
typedef long long ll;

const int N = 250000 + 7;
const int C = 16;
int n;
int dp[C + 1][N];
int mod;
int fact[N];
int ifact[N];
int some[N];
int p[N], cnt;


int add(int a, int b) {
  a += b;
  if (a >= mod) {
    return a - mod;
  }
  if (a < 0) {
    return a + mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % mod;
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
  return mul(a, pw(b, mod - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}
void mulup(int& a, int b) {
  a = mul(a, b);
}

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  int n, k;
  cin >> n >> k >> mod;

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    for (int bit = 0; (1 << bit) <= i; bit++) {
      if (i & (1 << bit)) {
        some[i] = bit;
      }
    }
  }
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);

  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

  if (n % 2 == 1) {
    cout << pw(k, n) << "\n";
    return 0;
  }
  vector<int> guys;
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    if ((i & n) != i) continue;
    cnt = 0;
    for (int mask = i | (i + 1); mask <= n; mask = (mask + 1) | i) {
      if ((mask & n) == mask) p[cnt++] = mask;
    }
    for (int step = 1; step <= min(C, k); step++) {
      if (!dp[step - 1][i]) continue;
      for (int j = 0; j < cnt; j++) {
        dp[step][p[j]] = (dp[step][p[j]] + dp[step - 1][i] * (ll)ifact[p[j] - i]) % mod;
      }
    }
  }

  int total = 0;
  for (int cnt = 1; cnt <= min(C, k); cnt++) {
    addup(total, mul(comb(k, cnt), dp[cnt][n]));
  }
  mulup(total, fact[n]);
  cout << add(pw(k, n), -total) << "\n";
}
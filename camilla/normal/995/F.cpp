#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

const int N = 3e3 + 10;
int dp[N][N];
vector<int> a[N];
int n, m;

void DFS(int u) {
  for (int k = 1; k <= n; ++k) dp[u][k] = 1;
  for (auto& v : a[u]) {
    DFS(v);
    for (int k = 1; k <= n; ++k) {
      dp[u][k] = 1LL * dp[u][k] * dp[v][k] % MOD;
    }
  }
  // for (int k = 0; k <= n; ++k) {
  //   trace(u, k, dp[u][k]);
  // }
  for (int k = 1; k <= n; ++k) {
    dp[u][k] = (dp[u][k] + dp[u][k - 1]) % MOD;
  }
}

int64 power_mod(int64 a, int64 n, int p = MOD) {
  int64 ret = 1;
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * a % p;
    a = a * a % p;
  }
  return ret;
}

int F[N], G[N];

int64 comb(int n, int m) {
  if (n < m) return 0;
  return (int64)F[n] * G[m] % MOD * G[n - m] % MOD;
}

void init(int n) {
  static int inv[N];
  inv[1] = 1;
  for (int i = 2; i < n; ++i) {
    inv[i] = (MOD - MOD / i) * (int64)inv[MOD % i] % MOD;
  }
  F[0] = G[0] = 1;
  for (int i = 1; i < n; ++i) {
    F[i] = (int64)F[i - 1] * i % MOD;
    G[i] = (int64)G[i - 1] * inv[i] % MOD;
  }
}

int64 lagrange(const vector<int>& a, int n) {
  int m = a.size();
  if (n < m) return a[n];
  int64 ret = 0;
  for (int i = 0; i < m; ++i) {
    int64 cur = (int64)G[i] * G[m - 1 - i] % MOD *
      power_mod(n + MOD - i, MOD - 2) % MOD * a[i] % MOD;
    if ((m - 1 - i) % 2) cur = MOD - cur;
    ret += cur;
  }
  ret %= MOD;
  for (int i = 0; i < m; ++i) ret = ret * (n + MOD - i) % MOD;
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int j;
    scanf("%d", &j);
    a[j - 1].push_back(i);
  }
  DFS(0);

  vector<int> a(dp[0], dp[0] + n + 1);
  init(N);
  printf("%lld\n", lagrange(a, m));
  return 0;
}
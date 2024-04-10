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
typedef pair<int64, int64> ii;
const int INF = 1 << 29;
const int MOD = 998244353;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

const int N = 1e6 + 10;
int F[N], G[N];

int64 comb(int n, int m) {
  if (n < m || m < 0) return 0;
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

int main() {
  init(N);
  int64 n;
  scanf("%lld", &n);
  vector<int64> a;
  for (int64 p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      while (n % p == 0) {
        n /= p;
      }
      a.push_back(p);
    }
  }
  if (n > 1) a.push_back(n);
  int m;
  scanf("%d", &m);
  for (int k = 0; k < m; ++k) {
    int64 u, v, ret = 1;
    scanf("%lld%lld", &u, &v);
    int pos = 0, neg = 0;
    for (auto& p : a) {
      int cnt = 0;
      while (u % p == 0) {
        ++cnt;
        u /= p;
      }
      while (v % p == 0) {
        --cnt;
        v /= p;
      }
      if (cnt >= 0) {
        pos += cnt;
      } else {
        cnt = -cnt;
        neg += cnt;
      }
      ret = ret * G[cnt] % MOD;
    }
    ret = ret * F[pos] % MOD * F[neg] % MOD;
    printf("%lld\n", ret);
  }

  return 0;
}
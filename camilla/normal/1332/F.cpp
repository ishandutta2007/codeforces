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

const int N = 3e5 + 10;
vector<int> a[N];
int64 dp[N][2][2]; // vertex, vertex select, up_edge select

void DFS(int u, int parent) {
  dp[u][0][0] = dp[u][1][0] = dp[u][0][1] = dp[u][1][1] = 1;
  int64 isolation = 1;
  for (auto& v : a[u]) {
    if (v == parent) continue;
    DFS(v, u);
    int64 cur = 0;
    for (int i = 0; i < 4; ++i) cur += dp[v][i / 2][i % 2];
    for (int up_edge = 0; up_edge < 2; ++up_edge) {
      dp[u][0][up_edge] = dp[u][0][up_edge] * cur % MOD;
      dp[u][1][up_edge] = dp[u][1][up_edge] * (cur - dp[v][1][1]) % MOD;
    }
    isolation = isolation * (dp[v][0][0] + dp[v][1][0]) % MOD;
  }
  for (int i = 0; i < 1; ++i) {
    dp[u][i][0] = (dp[u][i][0] + MOD - isolation) % MOD;
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

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  DFS(0, -1);
  // for (int i = 0; i < n; ++i) {
  //   trace(i, dp[i][0][0], dp[i][1][0], dp[i][0][1], dp[i][1][1]);
  // }
  int ret = (dp[0][0][0] + dp[0][1][0]) % MOD;
  // ret = (ret + MOD - power_mod(2, n)) % MOD;
  printf("%d\n", (ret + MOD - 1) % MOD);
  return 0;
}
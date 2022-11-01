// #define LOCAL
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
#define SZ(x) (int)((x).size())
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
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

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int64>> g(n, vector<int64>(n, inf<int64>));
  for (int i = 0; i < n; ++i) g[i][i] = 0;
  vector<array<int, 3>> e(m);
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g[x][y] = g[y][x] = z;
    e[i] = {x, y, z};
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  trace(g);

  vector<vector<int64>> h(n, vector<int64>(n, -inf<int64>));
  int q;
  cin >> q;
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    h[x][y] = h[y][x] = z;
  }

  trace(h);

  vector<vector<int64>> best(n, vector<int64>(n, -inf<int64>));
  for (int i = 0; i < n; ++i) {
    for (int y = 0; y < n; ++y) {
      for (int j = 0; j < n; ++j) {
        best[i][y] = max(best[i][y], h[i][j] - g[y][j]);
      }
    }
  }
  trace(best);

  vector<bool> ret(m);
  for (int k = 0; k < m; ++k) {
    int x = e[k][0], y = e[k][1], z = e[k][2];
    for (int i = 0; i < n; ++i) {
      if (g[i][x] != inf<int64>) {
        if (best[i][y] - g[i][x] - z >= 0) ret[k] = true;
      }
      swap(x, y);
      if (g[i][x] != inf<int64>) {
        if (best[i][y] - g[i][x] - z >= 0) ret[k] = true;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < m; ++i) sum += ret[i];
  cout << sum << '\n';

  return 0;
}
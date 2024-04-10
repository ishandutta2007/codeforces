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

const int N = 2e5 + 10;
int dep[N], f[N];
int tin[N], tout[N];
vector<int> a[N];

int stamp = 0;
void DFS(int u, int parent) {
  f[u] = parent;
  dep[u] = parent < 0 ? 0 : dep[parent] + 1;
  tin[u] = stamp++;
  for (auto& v : a[u]) {
    if (v == parent) continue;
    DFS(v, u);
  }
  tout[u] = stamp;
}

bool contain(int u, int v) {
  if (u < 0) return false;
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  DFS(0, -1);
  vector<bool> c(n);
  while (m--) {
    int len;
    scanf("%d", &len);
    vector<int> b;
    int best = -INF, best_x = -1;
    for (int i = 0; i < len; ++i) {
      int x;
      scanf("%d", &x);
      --x;
      b.push_back(x);
      if (dep[x] > best) {
        best = dep[x];
        best_x = x;
      }
    }
    bool found = false;
    for (auto& u : b) {
      if (!contain(u, best_x) && !contain(f[u], best_x)) {
        found = true;
        break;
      }
    }
    puts(found ? "NO" : "YES");
  }
  return 0;
}
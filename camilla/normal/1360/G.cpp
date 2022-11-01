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

#define SZ(x) (int)(x.size())

struct Edge {
  int v, c, dual;
  Edge(int v, int c, int dual) : v(v), c(c), dual(dual) {}
};

template<size_t N>
struct maxflow {
  vector<Edge> a[N];
  vector<Edge>::iterator idx[N];
  int d[N];

  void add_edge(int u, int v, int c) {
    a[u].emplace_back(v, c, SZ(a[v]));
    a[v].emplace_back(u, 0, SZ(a[u]) - 1);
  }
  void add_bidirection_edge(int u, int v, int c) {
    a[u].emplace_back(v, c, SZ(a[v]));
    a[v].emplace_back(u, c, SZ(a[u]) - 1);
  }
  int augment(int u, int t, int bound) {
    if (u == t) return bound;
    int ret = 0;
    // current arc optimization
    for (auto& it = idx[u]; it != a[u].end() && ret < bound; ++it) {
      if (it->c && d[it->v] == d[u] + 1) {
        int aug = augment(it->v, t, min(it->c, bound - ret));
        ret += aug;
        it->c -= aug;
        a[it->v][it->dual].c += aug;
      }
    }
    if (ret == 0) d[u] = -1;
    return ret;
  }
  int n;
  bool path(int s, int t) {
    fill(d, d + n, -1);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto& p : a[u]) {
        if (p.c && d[p.v] == -1) {
          Q.push(p.v);
          d[p.v] = d[u] + 1;
          if (p.v == t) return true;
        }
      }
    }
    return false;
  }
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) a[i].clear();
  }
  int dinic(int s, int t) {
    int ret = 0;
    while (path(s, t)) {
      // current arc optimization
      for (int i = 0; i < n; ++i) idx[i] = a[i].begin();
      while (int aug = augment(s, t, INF)) {
        ret += aug;
      }
    }
    return ret;
  }
};

const int N = 120;
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int n, m, A, B;
    scanf("%d%d%d%d", &n, &m, &A, &B);
    if (n * A != m * B) {
      puts("NO");
      continue;
    }
    int s = n + m, t = s + 1;
    maxflow<N> flow;
    flow.init(t + 1);
    for (int i = 0; i < n; ++i) {
      flow.add_edge(s, i, A);
    }
    for (int j = 0; j < m; ++j) {
      flow.add_edge(j + n, t, B);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        flow.add_edge(i, n + j, 1);
      }
    }
    int ans = flow.dinic(s, t);
    if (ans != n * A) {
      puts("NO");
      continue;
    }
    puts("YES");
    vector<vector<int>> ret(n, vector<int>(m));
    for (int u = 0; u < n; ++u) {
      for (auto& p : flow.a[u]) {
        if (p.v >= n && p.v < n + m) {
          int v = p.v - n;
          ret[u][v] = 1 - p.c;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) printf("%d", ret[i][j]);
      puts("");
    }

  }
  return 0;
}
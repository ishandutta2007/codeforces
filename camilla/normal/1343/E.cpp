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
int A[N], B[N], C[N];
vector<int> a[N];

void BFS(int s, int n, int d[]) {
  queue<int> Q;
  Q.push(s);
  fill(d, d + n, -1);
  d[s] = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto& v : a[u]) {
      if (d[v] >= 0) continue;
      d[v] = d[u] + 1;
      Q.push(v);
    }
  }
}

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int n, m, u, v, w;
    scanf("%d%d%d%d%d", &n, &m, &u, &v, &w);
    --u; --v; --w;
    for (int i = 0; i < n; ++i) a[i].clear();
    vector<int> e(m);
    for (int i = 0; i < m; ++i) scanf("%d", &e[i]);
    sort(e.begin(), e.end());
    vector<int64> pre(m + 1);
    for (int i = 0; i < m; ++i) pre[i + 1] = pre[i] + e[i];
    for (int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x; --y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    BFS(v, n, C);
    BFS(u, n, A);
    BFS(w, n, B);
    int64 ret = 1LL << 60;
    for (int i = 0; i < n; ++i) {
      if (C[i] + A[i] + B[i] > m) continue;
      // trace(i, A[i], B[i], C[i]);
      int64 cur = pre[C[i] + A[i] + B[i]] + pre[C[i]];
      ret = min(ret, cur);
    }
    printf("%lld\n", ret);
  }
  return 0;
}
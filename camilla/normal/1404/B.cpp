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
#define SZ(x) (int)((x).size())
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

const int N = 1e5 + 10;
vector<int> a[N];
int d[N];
int len[N][2];

void merge(int u, int cur) {
  if (cur > len[u][0]) {
    len[u][1] = len[u][0];
    len[u][0] = cur;
  } else if (cur > len[u][1]) {
    len[u][1] = cur;
  }
}

void DFS(int u, int parent) {
  len[u][0] = 0; len[u][1] = -INF;
  for (auto& v : a[u]) {
    if (v == parent) continue;
    d[v] = d[u] + 1;
    DFS(v, u);
    merge(u, len[v][0] + 1);
  }
}

int best;
void solve(int u, int parent, int up_len) {
  best = min(best, max(len[u][0], up_len));
  for (auto& v : a[u]) {
    if (v == parent) continue;
    int nxt_up_len = up_len;
    nxt_up_len = max(nxt_up_len, (len[u][0] == len[v][0] + 1 ? len[u][1] : len[u][0]));
    nxt_up_len += 1;
    solve(v, u, nxt_up_len);
  }
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n, u, v, du, dv;;
    cin >> n >> u >> v >> du >> dv;
    --u; --v;
    for (int i = 0; i < n; ++i) a[i].clear();
    for (int i = 1; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    // trace(u, v, du, dv);
    if (dv <= du * 2) {
      cout << "Alice\n";
      continue;
    }
    d[u] = 0;
    DFS(u, -1);
    if (d[v] <= du) {
      cout << "Alice\n";
      continue;
    }
    best = INF;
    solve(u, -1, 0);
    if (best <= du) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
  return 0;
}
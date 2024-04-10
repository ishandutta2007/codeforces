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

const int N = 3e5 + 10;
vector<int> a[N], layer[N];
int dep[N], f[N];
bool visit[N], leaf[N];

void DFS(int u, int parent) {
  visit[u] = true;
  f[u] = parent;
  dep[u] = parent < 0 ? 0 : dep[parent] + 1;
  for (auto& v : a[u]) {
    if (!visit[v]) {
      DFS(v, u);
      leaf[u] = false;
    }
  }
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  fill(leaf, leaf + n, true);
  DFS(0, -1);
  for (int i = 0; i < n; ++i) {
    if (dep[i] == (n + k - 1) / k - 1) {
      puts("PATH");
      vector<int> ret;
      for (int t = i; t != -1; t = f[t]) {
        ret.push_back(t);
      }
      printf("%d\n", (int)ret.size());
      for (int i = 0; i < (int)ret.size(); ++i) {
        printf("%d%c", ret[i] + 1, " \n"[i + 1 == (int)ret.size()]);
      }
      return 0;
    }
  }

  puts("CYCLES");
  vector<int> can;
  for (int i = 0; i < n; ++i) {
    if (leaf[i]) {
      can.push_back(i);
    }
    if (can.size() == k) break;
  }

  for (auto& u : can) {
    vector<int> back;
    for (auto& v : a[u]) {
      if (v == f[u]) continue;
      back.push_back(v);
      if (back.size() == 2) break;
    }
    vector<int> ret;
    if ((dep[u] - dep[back[0]] + 1) % 3) {
      for (int t = u; ; t = f[t]) {
        ret.push_back(t);
        if (t == back[0]) break;
      }
    } else if ((dep[u] - dep[back[1]] + 1) % 3) {
      for (int t = u; ; t = f[t]) {
        ret.push_back(t);
        if (t == back[1]) break;
      }
    } else {
      ret.push_back(u);
      int x = back[0], y = back[1];
      if (dep[x] > dep[y]) swap(x, y);
      for (int t = y; t != x; t = f[t]) ret.push_back(t);
      ret.push_back(x);
    }
    printf("%d\n", (int)ret.size());
    for (int i = 0; i < (int)ret.size(); ++i) {
      printf("%d%c", ret[i] + 1, " \n"[i + 1 == (int)ret.size()]);
    }
  }
  return 0;
}
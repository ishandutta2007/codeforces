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
  for (auto v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
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

template <class T> auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
  return vector<decltype(vect(v, m...))>(n, vect(v, m...));
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

const int N = 3e5 + 10;
vector<int> a[N], b[N];
int tin[N], tout[N];
int stamp;

void DFS(int u) {
  tin[u] = stamp++;
  for (auto& v : b[u]) {
    DFS(v);
  }
  tout[u] = stamp;
}

int c[N];
void add(int x, int y) {
  for (; x < N; x += x & -x) {
    c[x] += y;
  }
}
int query(int x) {
  int ret = 0;
  for (; x; x -= x & -x) {
    ret += c[x];
  }
  return ret;
}

struct Node {
  Node *left, *right;
  ii mx;
  void pushup() {
    mx = max(left->mx, right->mx);
  }
};
Node pool[N << 1], *last;
Node* build(int a, int b) {
  Node* ret = last++;
  ret->mx = {0, 0};
  if (a + 1 == b) return ret;
  int mid = (a + b) / 2;
  ret->left = build(a, mid);
  ret->right = build(mid, b);
  return ret;
}
void insert(Node* cur, int a, int b, int pos, ii v) {
  if (pos >= b || pos < a) return;
  if (a + 1 == b) {
    cur->mx = v;
    return;
  }
  int mid = (a + b) / 2;
  insert(cur->left, a, mid, pos, v);
  insert(cur->right, mid, b, pos, v);
  cur->pushup();
}
ii query(Node* cur, int a, int b, int ll, int rr) {
  if (ll >= rr || a >= rr || b <= ll) return {0, 0};
  if (a >= ll && b <= rr) {
    return cur->mx;
  }
  int mid = (a + b) / 2;
  ii ret = {0, 0};
  ret = max(ret, query(cur->left, a, mid, ll, rr));
  ret = max(ret, query(cur->right, mid, b, ll, rr));
  return ret;
}


int best, cur, n;
Node* rt;
void solve(int u) {
  int L = tin[u], R = tout[u];
  bool contains_other = query(R - 1) - query(L - 1);
  int v = -1;
  if (!contains_other) {
    add(L, 1);
    insert(rt, 0, n + 1, L, {R, u});
    cur++;
    auto right_most = query(rt, 0, n + 1, 0, L);
    if (right_most.first > L) {
      v = right_most.second;
      add(tin[v], -1);
      insert(rt, 0, n + 1, tin[v], {0, 0});
      cur--;
    }
  }
  trace(u, L, R, contains_other, v, cur);
  best = max(best, cur);
  for (auto& v : a[u]) {
    solve(v);
  }
  if (!contains_other) {
    add(L, -1);
    insert(rt, 0, n + 1, L, {0, 0});
    cur--;
    if (v != -1) {
      add(tin[v], 1);
      insert(rt, 0, n + 1, tin[v], {tout[v], v});
      cur++;
    }
  }
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    cin >> n;
    last = pool;
    rt = build(0, n + 1);
    for (int i = 1; i <= n; ++i) {
      c[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      a[i].clear();
      b[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int p;
      cin >> p;
      --p;
      a[p].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
      int p;
      cin >> p;
      --p;
      b[p].push_back(i);
    }
    stamp = 1;
    DFS(0);
    best = cur = 0;
    solve(0);
    cout << best << '\n';
  }

  return 0;
}
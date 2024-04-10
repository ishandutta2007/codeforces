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

struct Node {
  Node *left, *right;
  int64 sum, c;
  bool flag;
  void update(int a, int b, int64 c) {
    sum = (b - a) * c;
    this->c = c;
    flag = true;
  }
  void pushup() {
    sum = left->sum + right->sum;
  }
  void pushdown(int a, int b) {
    if (flag) {
      int mid = (a + b) / 2;
      left->update(a, mid, c);
      right->update(mid, b, c);
      flag = false;
    }
  }
};

const int N = 2e5 + 10;
Node pool[N << 1], *last;

Node* build(int a, int b) {
  Node* ret = last++;
  ret->sum = ret->c = ret->flag = 0;
  if (a + 1 == b) return ret;
  int mid = (a + b) / 2;
  ret->left = build(a, mid);
  ret->right = build(mid, b);
  return ret;
}

void insert(Node* cur, int a, int b, int ll, int rr, int64 c) {
  if (ll >= rr || a >= rr || b <= ll) return;
  if (a >= ll && b <= rr) {
    cur->update(a, b, c);
    return;
  }
  cur->pushdown(a, b);
  int mid = (a + b) / 2;
  insert(cur->left, a, mid, ll, rr, c);
  insert(cur->right, mid, b, ll, rr, c);
  cur->pushup();
}

int64 query(Node* cur, int a, int b, int ll, int rr) {
  if (ll >= rr || a >= rr || b <= ll) return 0LL;
  if (a >= ll && b <= rr) {
    return cur->sum;
  }
  cur->pushdown(a, b);
  int mid = (a + b) / 2;
  int64 ret = 0;
  ret += query(cur->left, a, mid, ll, rr);
  ret += query(cur->right, mid, b, ll, rr);
  return ret;
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    last = pool;
    Node* rt = build(0, n);
    for (int i = 0; i < n; ++i) {
      insert(rt, 0, n, i, i + 1, t[i] - '0');
    }

    vector<array<int, 2>> a(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i][0] >> a[i][1];
    }
    bool found = false;
    for (int i = m - 1; i >= 0; --i) {
      int L = a[i][0] - 1, R = a[i][1];
      int64 cnt = query(rt, 0, n, L, R);
      if (cnt * 2 == R - L) {
        found = true;
        break;
      }
      if (cnt * 2 < R - L) {
        insert(rt, 0, n, L, R, 0);
      } else {
        insert(rt, 0, n, L, R, 1);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] - '0' != query(rt, 0, n, i, i + 1)) {
        found = true;
        break;
      }
    }
    cout << (found ? "NO" : "YES") << '\n';
  }

  return 0;
}
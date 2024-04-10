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

typedef long long int64;
typedef pair<int, int> ii;
#define SZ(x) (int)((x).size())
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
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

const int N = 2e5 + 10;
int64 pre[2][N];

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int solve(const vector<int>& b, int x, int y, int64 target) {
  if (x + y >= SZ(b)) return 0;
  vector<int> a;
  if (y) target -= b.back();
  for (int i = x; i < SZ(b) - y; ++i) a.push_back(b[i]);
  // trace(x, y, a, target);
  int n = SZ(a);
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < n; ++i) {
      pre[k][i + 1] = pre[k][i] + (i % 2 == k ? a[i] : 0);
    }
  }

  int64 cur = 0;
  int ret = 0;
  for (int L = 0; L <= n && cur < target; ++L) {
    if (!(x && L <= 1)) {
      int k = 1 - L % 2;
      int low = 0, high = (n - L) / 2;
      int R = n - (high * 2 + L);
      if (y && R <= 1) --high;
      if (low <= high) {
        while (low != high) {
          int mid = (low + high + 1) / 2;
          int64 t = pre[k][L + mid * 2] - pre[k][L];
          if (cur + t >= target) {
            high = mid - 1;
          } else {
            low = mid;
          }
        }
        add(ret, high + 1);
        // trace(L, high, (n - high * 2 - L), target, ret);
      }
    }
    if (L < n) cur += a[L];
  }
  return ret;
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int64 sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }

    int64 target = (sum + 1) / 2;

    int ret = 0;
    for (int x = 0; x < 2; ++x) {
      for (int y = 0; y < 2; ++y) {
        int cur = solve(a, x, y, target);
        // trace(x, y, cur);
        add(ret, cur);
      }
    }

    trace(ret);
    if (n >= 4) {
      reverse(a.begin(), a.end());
      int64 cur = a[0] + a[1];
      for (int k = 2; k <= n - 2; ++k) {
        if (cur < target) add(ret, 1);
        cur += a[k];
      }
    }

    cout << ret << '\n';
  }

  return 0;
}
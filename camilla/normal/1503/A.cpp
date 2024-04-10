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
  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<int, 2>> a(n + 1);
    a[0] = {0, 0};
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        a[i + 1] = {a[i][0] + 1, a[i][1] + 1};
      } else {
        a[i + 1] = {a[i][0] + 1, a[i][1] - 1};
        if (a[i + 1][0] > a[i + 1][1]) swap(a[i + 1][0], a[i + 1][1]);
      }
    }
    trace(a);
    if (a[n][0] != a[n][1] || a[n][0] < 0) {
      cout << "NO" << '\n';
      continue;
    }
    int k = n - 1, cnt = a[n][0] / 2;
    trace(a, cnt);
    for (; k >= 0; --k) {
      if (s[k] == '1') --cnt;
      if (cnt == 0) break;
    }
    if (k < 0) {
      cout << "NO" << '\n';
      continue;
    }
    trace(k, cnt);
    for (int i = k; i < n; ++i) {
      if (s[i] == '1') {
        a[i + 1] = {a[i][0] - 1, a[i][1] - 1};
      } else {
        a[i + 1] = {a[i][0] + 1, a[i][1] - 1};
        if (a[i + 1][0] > a[i + 1][1]) swap(a[i + 1][0], a[i + 1][1]);
      }
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      if (a[i][0] < 0 || a[i][1] < 0) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    vector<string> ret(2);
    for (int i = 0; i < n; ++i) {
      for (int k = 0; k < 2; ++k) {
        if (a[i + 1][k] > a[i][k]) {
          ret[k] += '(';
        } else {
          ret[k] += ')';
        }
      }
    }
    cout << "YES" << '\n';
    cout << ret[0] << '\n';
    cout << ret[1] << '\n';
  }

  return 0;
}
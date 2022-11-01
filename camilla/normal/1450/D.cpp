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

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    vector<int> a(n), ll(n + 1, n), rr(n + 1, -1), cnt(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      cnt[a[i]]++;
      ll[a[i]] = min(ll[a[i]], i);
      rr[a[i]] = max(rr[a[i]], i);
    }
    int L = 0, R = n - 1;
    vector<int> ret(n + 1);
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool found = false;
    for (int i = 0; i < n; ++i) {
      if (i + 1 != b[i]) found = true;
    }
    ret[1] = !found;
    int k;
    for (k = 1; k <= n; ++k) {
      if (cnt[k] == 0) {
        for (int i = R - L + 2; i <= n; ++i) ret[i] = 1;
        break;
      }
      if (a[L] != k && a[R] != k) {
        for (int i = R - L + 1; i <= n; ++i) ret[i] = 1;
        break;
      }
      if (a[L] == k && a[R] == k) {
        for (int i = R - L + 1; i <= n; ++i) ret[i] = 1;
        break;
      }
      if (cnt[k] > 1) {
        for (int i = R - L + 1; i <= n; ++i) ret[i] = 1;
        break;
      }
      if (a[L] == k) {
        ++L;
      } else {
        --R;
      }
    }
    if (k > n) {
      for (int i = 1; i <= n; ++i) ret[i] = 1;
    }
    for (int i = 1; i <= n; ++i) cout << ret[i];
    cout << '\n';
  }
  return 0;
}
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
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto& x : p) cin >> x;
  vector<int> downL(n), downR(n), upL(n), upR(n);
  for (int i = 1; i < n; ++i) {
    if (p[i - 1] < p[i]) downL[i] = downL[i - 1] + 1;
    if (p[i - 1] > p[i]) upL[i] = upL[i - 1] + 1;
  }
  for (int i = n - 2; i >= 0; --i) {
    if (p[i] > p[i + 1]) downR[i] = downR[i + 1] + 1;
    if (p[i] < p[i + 1]) upR[i] = upR[i + 1] + 1;
  }
  set<ii, greater<ii>> A;
  for (int i = 0; i < n; ++i) {
    int cur = max(upL[i], upR[i]);
    A.insert({cur, i});
  }
  int ret = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (p[i] < p[i - 1] || p[i] < p[i + 1]) continue;
    if (downL[i] == downR[i] && downL[i] % 2 == 0) {
      trace(i, downL[i], downR[i]);
      bool found = false;
      for (auto it = A.begin(); it != A.end(); ++it) {
        if (it->first > downL[i]) {
          found = true;
          break;
        }
        if (it->first < downL[i]) break;
        int j = it->second;
        if (j != i - downL[i] && j != i + downR[i]) {
          found = true;
          break;
        } else if (j == i - downL[i]) {
          if (upL[j] == downL[i]) {
            found = true;
            break;
          }
        } else {
          if (upR[j] == downL[i]) {
            found = true;
            break;
          }
        }
      }
      if (!found) ++ret;
    }
  }
  cout << ret << '\n';

  return 0;
}
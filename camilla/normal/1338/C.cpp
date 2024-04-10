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

int main() {
  // set<int> S;
  // for (int u = 0; u < 20; ++u) {
  //   int i, j;
  //   for (i = 1; S.count(i); ++i);
  //   S.insert(i);
  //   for (j = i + 1; ; ++j) {
  //     if (!S.count(j) && !S.count(i ^ j)) break;
  //   }
  //   int k = i ^ j;
  //   S.insert(j);
  //   S.insert(k);
  //   cout << i << " " << j << " " << k << (j == 2 * i && k == 3 * i ? "*" : "") << endl;
  // }

  vector<int> offset = {0, 2, 3, 1};
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int64 n;
    scanf("%lld", &n);
    int64 p = 1, sum = 3;
    while (sum < n) {
      p *= 4;
      sum += p * 3;
    }
    int r = n % 3;
    sum -= p * 3;
    n -= sum;
    // trace(p, n);
    if (r == 1) {
      printf("%lld\n", p + (n - 1) / 3);
    } else if (r == 2) {
      int64 ret = 0, q = 1;
      for (int64 row = (n - 1) / 3; row; row /= 4) {
        ret += offset[row % 4] * q;
        q *= 4;
      }
      ret += p * 2;
      printf("%lld\n", ret);
    } else {
      int64 u = p + (n - 1) / 3;
      int64 ret = 0, q = 1;
      for (int64 row = (n - 1) / 3; row; row /= 4) {
        ret += offset[row % 4] * q;
        q *= 4;
      }
      ret += p * 2;
      // trace(u, ret);
      printf("%lld\n", ret ^ u);
    }
  }
  return 0;
}
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

int64 F2(int64 n) {
  return n * (n - 1) / 2;
}

int64 F3(int64 n) {
  return n * (n - 1) / 2 * (n - 2) / 3;
}

int64 row(int64 r, int64 c1, int64 c2) {
  int64 ret = F2(r + 1) * (c2 - c1 + 1);
  ret += F3(c2) - F3(c1 - 1);
  ret += (F2(c2) - F2(c1 - 1)) * r;
  // trace(r, c1, c2, ret);
  return ret;
}

int64 col(int64 r1, int64 r2, int64 c) {
  int64 ret = F2(c - 1) * (r2 - r1 + 1);
  ret += F3(r2 + 2) - F3(r1 + 1);
  ret += (F2(r2 + 1) - F2(r1)) * (c - 1);
  // trace(r1, r2, c, ret);
  return ret;
}


int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int64 x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    int64 L = row(x1, y1, y2) + col(x1, x2, y2);
    L -= F2(x1 + 1) + x1 * (y2 - 1) + F2(y2 - 1);
    int64 R = col(x1, x2, y1) + row(x2, y1, y2);
    R -= F2(x2 + 1) + x2 * (y1 - 1) + F2(y1 - 1);
    // trace(L, R);
    printf("%lld\n", R - L + 1);
  }
  return 0;
}
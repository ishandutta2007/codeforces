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

bool check(const vector<int>& a, int L) {
  int64 sum = 0;
  int n = a.size();
  for (int i = 0; i + L <= n; ++i) {
    if (i == 0) {
      for (int j = 0; j < L; ++j) sum += a[j];
    } else {
      sum -= a[i - 1];
      sum += a[i + L - 1];
    }
    if (sum <= 0) return false;
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  int L = (n + 1) / 2;
  for (int i = 0; i < L; ++i) {
    scanf("%d", &a[i]);
  }
  int x;
  scanf("%d", &x);
  for (int i = L; i < n; ++i) a[i] = x;
  if (x > 0) {
    int64 sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    if (sum > 0) {
      printf("%d\n", n);
    } else {
      puts("-1");
    }
  } else {
    int pos = L - 1;
    int64 rr = 1LL * x * (n - L);
    for (; pos >= 0; --pos) {
      rr += a[pos];
      if (rr > 0) break;
    }
    if (pos < 0) {
      puts("-1");
      return 0;
    }
    int len = n - pos;
    int64 sum = 0;
    vector<int64> b(n - len + 1);
    for (int i = 0; i + len <= n; ++i) {
      if (i == 0) {
        for (int j = 0; j < len; ++j) sum += a[j];
      } else {
        sum -= a[i - 1];
        sum += a[i + len - 1];
      }
      b[i] = sum;
    }
    int64 minb = 1LL << 60;
    // trace(len);
    for (int i = 0; i + len <= n; ++i) {
      minb = min(minb, b[i]);
      // trace(i, b[i], minb, (n - len - i) * x);
      if (minb + 1LL * (n - len - i) * x > 0) {
        printf("%d\n", n - i);
        return 0;
      }
    }
    puts("-1");
  }
  return 0;
}
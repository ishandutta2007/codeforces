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
  int cas;
  cin >> cas;
  while (cas--) {
    string s;
    int n, m;
    cin >> n >> m;
    cin >> s;
    // trace(n, m, s);
    bool found = false;
    for (int i = 0; i < m; ++i) {
      int k = 0;
      for (int j = i; j < n; j += m) {
        if (s[j] != '?') {
          k |= 1 << (s[j] - '0');
        }
      }
      if (k == 3) {
        found = true;
        break;
      }
      if (k == 1) {
        for (int j = i; j < n; j += m) s[j] = '0';
      } else if (k == 2) {
        for (int j = i; j < n; j += m) s[j] = '1';
      }
    }
    // trace(s);
    vector<int> cnt(2);
    for (int i = 0; i + m <= n; ++i) {
      if (i == 0) {
        for (int j = 0; j < m; ++j) if (s[j] != '?') cnt[s[j] - '0']++;
      } else {
        if (s[i - 1] != '?') cnt[s[i - 1] - '0']--;
        if (s[i + m - 1] != '?') cnt[s[i + m - 1] - '0']++;
      }
      // trace(i, cnt[0], cnt[1]);
      if (cnt[0] > m / 2 || cnt[1] > m / 2) found = true;
    }
    cout << (found ? "NO" : "YES") << '\n';
  }
  return 0;
}
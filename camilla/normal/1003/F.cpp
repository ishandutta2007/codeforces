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
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> pre(n + 1);
  map<string, int> A;
  int total = -1;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    pre[i + 1] = pre[i] + (int)s[i].size();
    total += s[i].size() + 1;
    if (A.find(s[i]) == A.end()) A[s[i]] = A.size();
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = A[s[i]];
  int best = 0;
  for (int len = 1; len * 2 <= n; ++len) {
    vector<int> v(len);
    map<vector<int>, vector<int>> pos;
    for (int i = 0; i + len <= n; ++i) {
      copy(a.begin() + i, a.begin() + i + len, v.begin());
      pos[v].push_back(i);
    }
    for (auto& [k, v] : pos) {
      if (v.size() < 2) continue;
      int cnt = 1;
      for (int i = 0, j; i < v.size(); i = j) {
        for (j = i + 1; j < v.size() && v[j] - v[i] < len; ++j);
        if (j == v.size()) break;
        ++cnt;
      }
      int cur = (pre[v[0] + len] - pre[v[0]] - 1) * cnt;
      // trace(len, k, v, cnt, cur);
      best = max(best, cur);
    }
  }
  cout << total - best << endl;
  return 0;
}
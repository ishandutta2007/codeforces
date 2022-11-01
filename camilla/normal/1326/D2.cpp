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

const int N = 1e6 + 10;
char s[N];

void manacher(char s[], int n, vector<int>& odd, vector<int>& even) {
  int L = 0, R = -1;
  for (int i = 0; i < n; ++i) {
    int k = (i > R) ? 1 : min(odd[L + R - i], R - i) + 1;
    while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
    odd[i] = --k;
    if (R < i + k) {
      L = i - k;
      R = i + k;
    }
  }
  L = 0; R = -1;
  for (int i = 0; i < n; ++i) {
    int k = (i > R) ? 1 : min(even[L + R - i + 1], R - i + 1) + 1;
    while (i - k >= 0 && i + k - 1 < n && s[i - k] == s[i + k - 1]) k++;
    even[i] = --k;
    if (R < i + k - 1) {
      L = i - k;
      R = i + k - 1;
    }
  }
}

int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%s", s);
    int n = strlen(s);
    vector<int> odd(n), even(n);
    manacher(s, n, odd, even);
    vector<bool> match(n);
    match[0] = true;
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - 1 - i]) break;
      match[i + 1] = true;
    }
    vector<ii> ret;
    int best = 0;
    for (int i = 0; i < n; ++i) {
      // i-odd[i]..i+odd[i]+1
      int len = min(i - odd[i], n - i - odd[i] - 1);
      if (match[len] && best < len * 2 + odd[i] * 2 + 1) {
        best = len * 2 + odd[i] * 2 + 1;
        ret = {{0, len}, {i - odd[i], i + odd[i] + 1}, {n - len, n}};
      }
    }
    for (int i = 1; i < n; ++i) {
      // i-even[i]..i+even[i]
      int len = min(i - even[i], n - i - even[i]);
      if (match[len] && best < len * 2 + even[i] * 2) {
        best = len * 2 + even[i] * 2;
        ret = {{0, len}, {i - even[i], i + even[i]}, {n - len, n}};
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = ret[i].first; j < ret[i].second; ++j) {
        putchar(s[j]);
      }
    }
    puts("");
  }
  return 0;
}
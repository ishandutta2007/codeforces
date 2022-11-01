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

const int N = 3e3 + 10;
char s[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == 'R' && s[j] == 'L') ++cnt;
    }
  }
  queue<int> Q;
  vector<bool> visit(n);
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      Q.push(i);
      visit[i] = true;
    }
  }
  // trace(m, cnt);
  if (m > cnt) {
    puts("-1");
    return 0;
  }
  vector<vector<int>> ret;
  vector<int> touched;
  for (int k = 0; k < m; ++k) {
    int used = min((int)Q.size(), cnt - m + k + 1);
    // trace(k, cnt, Q.size(), used);
    cnt -= used;
    vector<int> cur;
    cur.reserve(used);
    // printf("%d", used);
    touched.clear();
    while (used--) {
      int i = Q.front();
      cur.push_back(i + 1);
      // printf(" %d", i + 1);
      Q.pop();
      visit[i] = false;
      swap(s[i], s[i + 1]);
      touched.push_back(i);
    }
    // trace(touched);
    for (auto& i : touched) {
      if (i - 1 >= 0 && s[i - 1] == 'R' && !visit[i - 1]) {
        // trace(i, s[i - 1], s[i]);
        Q.push(i - 1);
        visit[i - 1] = true;
      }
      if (i + 2 < n && s[i + 2] == 'L' && !visit[i + 1]) {
        Q.push(i + 1);
        visit[i + 1] = true;
      }
    }
    ret.push_back(cur);
    // trace(s, Q.size());
  }
  if (cnt) {
    puts("-1");
  } else {
    for (auto& cur : ret) {
      printf("%d", (int)cur.size());
      for (int i = 0; i < cur.size(); ++i) {
        printf(" %d", cur[i]);
      }
      puts("");
    }
  }
  return 0;
}
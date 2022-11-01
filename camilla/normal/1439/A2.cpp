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

void rev(vector<string>& s, array<int, 6>& v) {
  for (int i = 0; i < 6; i += 2) {
    int x = v[i], y = v[i + 1];
    s[x][y] = '0' + '1' - s[x][y];
  }
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    trace(s);
    vector<array<int, 6>> ret;
    if (n % 2 && m % 2) {
      int i = n - 1, j = m - 1;
      if (s[i][j] == '1') {
        array<int, 6> v = {i, j - 1, i, j, i - 1, j};
        rev(s, v);
        ret.push_back(v);
      }
    }
    trace(s, ret);
    if (n % 2) {
      int i = n - 1;
      for (int j = 0; j < m / 2 * 2; ++j) {
        if (s[i][j] == '1') {
          array<int, 6> v;
          if (j == 0) {
            v = {i, j, i - 1, j, i - 1, j + 1};
          } else {
            v = {i, j, i - 1, j, i - 1, j - 1};
          }
          rev(s, v);
          ret.push_back(v);
        }
      }
    }
    trace(s, ret);
    if (m % 2) {
      int j = m - 1;
      for (int i = 0; i < n / 2 * 2; ++i) {
        if (s[i][j] == '1') {
          array<int, 6> v;
          if (i == 0) {
            v = {i, j, i, j - 1, i + 1, j - 1};
          } else {
            v = {i, j, i, j - 1, i - 1, j - 1};
          }
          rev(s, v);
          ret.push_back(v);
        }
      }
    }
    int pos = SZ(ret);
    trace(s);
    trace(SZ(ret), ret);
    for (int i = 0; i < n / 2 * 2; i += 2) {
      for (int j = 0; j < m / 2 * 2; j += 2) {
        vector<array<int, 2>> w, all;
        for (int u = 0; u < 2; ++u) {
          for (int v = 0; v < 2; ++v) {
            if (s[i + u][j + v] == '1') w.push_back({i + u, j + v});
            all.push_back({i + u, j + v});
          }
        }
        trace(i, j, w, all);
        if (SZ(w) == 0) continue;
        if (SZ(w) == 1) {
          for (int k = 0; k < 4; ++k) {
            array<int, 6> v;
            bool found = false;
            for (int u = 0, len = 0; u < 4; ++u) {
              if (u == k) continue;
              v[len++] = all[u][0];
              v[len++] = all[u][1];
              if (all[u] == w[0]) found = true;
            }
            if (found) ret.push_back(v);
          }
        } else if (SZ(w) == 2) {
          if (abs(w[0][0] - w[1][0]) == 1 && abs(w[0][1] - w[1][1]) == 1) {
            ret.push_back({w[0][0], w[1][1], w[1][0], w[0][1], w[0][0], w[0][1]});
            ret.push_back({w[0][0], w[1][1], w[1][0], w[0][1], w[1][0], w[1][1]});
          } else {
            vector<array<int, 2>> other;
            for (auto& v : all) {
              if (v == w[0] || v == w[1]) continue;
              other.push_back(v);
            }
            ret.push_back({other[0][0], other[0][1], other[1][0], other[1][1], w[0][0], w[0][1]});
            ret.push_back({other[0][0], other[0][1], other[1][0], other[1][1], w[1][0], w[1][1]});
          }
        } else if (SZ(w) == 3) {
          ret.push_back({w[0][0], w[0][1], w[1][0], w[1][1], w[2][0], w[2][1]});
        } else {
          for (int k = 0; k < 4; ++k) {
            array<int, 6> v;
            for (int u = 0, len = 0; u < 4; ++u) {
              if (u == k) continue;
              v[len++] = all[u][0];
              v[len++] = all[u][1];
            }
            ret.push_back(v);
          }
        }
      }
    }
    for (int i = pos; i < SZ(ret); ++i) rev(s, ret[i]);
    trace(s);
    cout << SZ(ret) << '\n';
    for (auto& v : ret) {
      for (int i = 0; i < 6; ++i) {
        cout << v[i] + 1 << " \n"[i + 1 == 6];
      }
    }
  }
  return 0;
}
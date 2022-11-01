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
char buf[N];
map<char, int> direction;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int stamp;
int label[N], pre[N], dist[N];
bool visit[N];
int n, m;
vector<vector<int>> circle;

bool solve(int sx, int sy, vector<vector<int>>& c, vector<vector<int>>& d) {
  // trace(sx, sy);
  queue<int> Q;
  int s = sx * m + sy;
  Q.push(s);
  visit[s] = true;
  while (!Q.empty()) {
    int cur = Q.front();
    int x = cur / m, y = cur % m;
    Q.pop();
    int nx = x + dir[d[x][y]][0];
    int ny = y + dir[d[x][y]][1];
    int nxt = nx * m + ny;
    if (!visit[nxt]) {
      visit[nxt] = true;
      pre[nxt] = cur;
      Q.push(nxt);
    } else {
      if (!label[nxt]) {
        vector<int> v;
        for (int t = cur; true; t = pre[t]) {
          dist[t] = v.size();
          // trace(t, v.size());
          v.push_back(c[t / m][t % m]);
          label[t] = stamp;
          if (t == nxt) break;
        }
        // trace(v);
        int len = v.size();
        for (int t = pre[nxt], k = 0; t != -1; t = pre[t], ++k) {
          dist[t] = k;
          v[k % len] |= c[t / m][t % m];
          label[t] = stamp;
        }
        circle.push_back(v);
        ++stamp;
        // trace(dist[0], dist[1]);
        return 1;
      } else {
        int len = circle[label[nxt]].size();
        for (int t = cur, k = dist[nxt] + 1; true; t = pre[t], ++k) {
          label[t] = label[nxt];
          dist[t] = k;
          circle[label[nxt]][k % len] |= c[t / m][t % m];
          if (t == s) break;
        }
        return 0;
      }
    }
  }
  return 0;
}

int main() {
  direction['U'] = 0;
  direction['D'] = 1;
  direction['L'] = 2;
  direction['R'] = 3;
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d", &n, &m);
    vector<vector<int>> c(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      scanf("%s", buf);
      for (int j = 0; j < m; ++j) {
        c[i][j] = 1 - (buf[j] - '0');
      }
    }
    for (int i = 0; i < n; ++i) {
      scanf("%s", buf);
      for (int j = 0; j < m; ++j) {
        d[i][j] = direction[buf[j]];
      }
    }
    fill(visit, visit + n * m, false);
    fill(label, label + n * m, 0);
    fill(pre, pre + n * m, -1);
    stamp = 1;
    circle = {{}};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (visit[i * m + j]) continue;
        solve(i, j, c, d);
      }
    }
    // trace(stamp);
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     cout << dist[i * m + j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << "-------" << endl;
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     cout << label[i * m + j] << " ";
    //   }
    //   cout << endl;
    // }
    int ret = 0, black = 0;
    for (int k = 1; k < stamp; ++k) {
      auto& cur = circle[k];
      int len = cur.size();
      for (int i = 0; i < len; ++i) black += cur[i];
      ret += len;
    }
    printf("%d %d\n", ret, black);
  }
  return 0;
}
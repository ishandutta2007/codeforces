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

const int N = 1e5 + 10;
vector<int> a[N];
int dep[N], f[N], son[N];

void DFS(int u, int parent) {
  f[u] = parent;
  dep[u] = parent < 0 ? 0 : dep[parent] + 1;
  son[u] = 0;
  for (auto& v : a[u]) {
    if (v == parent) continue;
    DFS(v, u);
    son[u]++;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  int r = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i].size() > 1) {
      r = i;
      break;
    }
  }
  DFS(r, -1);
  vector<bool> cnt(2);
  vector<int> F;
  for (int i = 0; i < n; ++i) {
    if (son[i] == 0) {
      cnt[dep[i] % 2] = true;
      F.push_back(f[i]);
    }
  }
  int L = 1, R = n - 1;
  if (cnt[0] && cnt[1]) L = 3;
  sort(F.begin(), F.end());
  // trace(F);
  for (int i = 0, j; i < F.size(); i = j) {
    for (j = i + 1; j < F.size() && F[j] == F[i]; ++j);
    R -= j - i - 1;
  }
  printf("%d %d\n", L, R);
  return 0;
}
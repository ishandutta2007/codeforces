%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair <int, int> 
#define sz(x) (int)x.size()

typedef long long ll;
const int N = 2000005;
const int mod = 1e9 + 7;

void Add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

template <class T>
struct Bit_tree {
  #define lowbit(x) ((x) & (-x))
  T a[N];
  int n;
  void init(int _n) {
    fill_n(a + 1, n = _n, 0);
  }
  void add(int x, T d) {
    for (; x <= n; x += lowbit(x))
      Add(a[x], d);
  }
  T sum(int x) {
    T r = 0;
    for (; x >= 1; x ^= lowbit(x))
      Add(r, a[x]);
    return r;
  }
};
Bit_tree <int> f;

vector <pii> in[N], out[N];
set <pii> inv;
set <int> pts;

int n, m, k;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  f.init(n);
  for (int i = 1; i <= k; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    in[y1].push_back(make_pair(x1, x2));
    out[y2 + 1].push_back(make_pair(x1, x2));
  }
  
  m++; in[m].push_back(make_pair(1, n - 1));
  pts.insert(1);
  inv.insert(make_pair(0, 0));
  
  f.add(1, 1);
  for (int i = 1; i <= m; i++) {
    if (sz(in[i]) || sz(out[i])) {
      //printf("I am zz! %d\n", i);
      sort(in[i].begin(), in[i].end());
      reverse(in[i].begin(), in[i].end());
      sort(out[i].begin(), out[i].end());
      //printf("I am AK! %d\n", i);
      for (auto e: in[i]) {
        auto it = inv.upper_bound(make_pair(e.second + 1, n));
        it--;
        //printf("qwq?");
        if (it->second <= e.second) {
          //printf("Oh, ");
          int s = (f.sum(e.second) - f.sum(it->second) + mod) % mod;
          //printf("I ");
          f.add(e.second + 1, i > 1 ? s : 0);
          //printf("AK ");
          pts.insert(e.second + 1);
          //printf("IOI");
        }
        //printf("\nqwq!\n");
      }
      //printf("I am fake! %d\n", i);
      for (auto e: in[i]) {
        auto it = pts.lower_bound(e.first);
        while (it != pts.end() && *it <= e.second) {
          int s = (f.sum(*it - 1) - f.sum(*it) + mod) % mod;
          f.add(*it, s);
          pts.erase(it++);
        }
      }
      //printf("I am faker! %d\n", i);
      for (auto e: out[i]) inv.erase(e);
      for (auto e: in[i]) inv.insert(e);
    }
  }
  
  printf("%d\n", f.sum(n));
  return 0;
}
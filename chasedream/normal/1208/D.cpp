#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...); 
}

const int N = 200005;

ll p[N];
int a[N], n;

struct Bit_tree {
  ll c[N];
  #define lowbit(x) (x & -x)
  void add(int x, int ad) {
    while (x <= n) {
      c[x] += ad; x += lowbit(x);
    }
  }
  ll query(int x) {
    ll res = 0LL;
    while (x > 0) {
      res += c[x]; x -= lowbit(x);
    }
    return res;
  }
} tr;

int find(ll k) {
  int l = 1, r = n + 1, ans = 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (tr.query(mid - 1) > k) r = mid;
    else l = mid + 1, ans = mid;
  }
  return ans;
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(p[i]);
    tr.add(i, i);
  } 
  
  for (int i = n; i >= 1; i--) {
    int jk = find(p[i]);
    a[i] = jk;
    tr.add(jk, -jk);
  }
  
  for (int i = 1; i <= n; i++) {
    printf("%d%c", a[i], (i == n ? '\n' : ' '));
  }
  return 0;
}
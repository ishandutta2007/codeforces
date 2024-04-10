%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const ll mod = 1e9 + 7;

struct MAT {
  long long v[3][3];
  int n, m;
  
  MAT (int n = 0, int m = 0): n(n), m(m) {}
  void init() {
    memset(v, 0, sizeof(v));
  }
  MAT operator * (const MAT& b) const {
    MAT ans(n, b.m); ans.init();
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= b.m; j++)
        for (int k = 1; k <= m; k++) {
          (ans.v[i][j] += v[i][k] * b.v[k][j]) %= mod;
          if (ans.v[i][j] < 0) ans.v[i][j] += mod;
        }
    return ans;
  }
};

long long x, y;
int n;

long long work() {
  MAT ans(2, 1), tmp(2, 2);
  ans.init(); tmp.init();
  ans.v[1][1] = y, ans.v[2][1] = x;
  tmp.v[1][1] = 1, tmp.v[1][2] = -1, tmp.v[2][1] = 1, tmp.v[2][2] = 0;
 
  while (n > 0) {
    if (n & 1) ans = tmp * ans;
    n >>= 1; tmp = tmp * tmp;
  }
  return ans.v[1][1];
}

int main() {
  scanf("%lld%lld", &x, &y);
  x %= mod; if (x < 0) x += mod;
  y %= mod; if (y < 0) y += mod;

  scanf("%d", &n);
  if (n <= 2) {
    if (n == 1) printf("%lld\n", x);
    else printf("%lld\n", y);
    exit(0);
  }
  n -= 2;
  printf("%d\n", work());
  return 0;
}

// wlzhouzhuan, 233
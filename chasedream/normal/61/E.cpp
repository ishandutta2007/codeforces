%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1000005;

int a[N], b[N], n;
struct Bit_tree {
  int c[N];
  
  int lowbit(int x) {
    return x & -x;
  }
  
  void update(int x, int val) {
    while (x <= n) {
      c[x] += val;
      x += lowbit(x); 
    }
  }
  ll query(int x) {
    ll ans = 0;
    while (x > 0) {
      ans += c[x];
      x -= lowbit(x);
    } 
    return ans;
  }
} l, r;


int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  }
  
  long long ans = 0LL;
  for (int i = n; i >= 2; i--)
    r.update(a[i], 1);
  for (int i = 2; i <= n; i++) {
    l.update(n + 1 - a[i - 1], 1);
    r.update(a[i], -1);
    ans += l.query(n - a[i]) * r.query(a[i] - 1);
  }
  printf("%lld\n", ans);
  return 0;
}
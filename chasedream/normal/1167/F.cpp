%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 500001;
const ll mod = 1e9 + 7;


int a[N], n;
struct ele {
  int x, id;
  ele (int x = 0, int id = 0): x(x), id(id) {}
  bool operator < (const ele& b) const { return x < b.x; } 
} b[N];

struct Bit_tree {
  long long c[N];
  void init() {
    memset(c, 0, sizeof(c));
  }

  #define lowbit(x) (x & -x)
  void add(int x, int val) {
    while (x <= n) { c[x] += val; x += lowbit(x); }
  }

  long long query(int x) {
    long long ans = 0;
    while (x > 0) { ans += c[x]; x -= lowbit(x); }
    return ans;
  }
} tr;

long long ans = 0LL;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = ele(a[i], i);
  }
  sort(b + 1, b + n + 1);
  
  for (int i = 1; i <= n; i++) {
    ans = (ans + (long long)i * (n - i + 1) % mod * a[i] % mod) % mod;
  }
  
  tr.init();
  for (int i = 1; i <= n; i++) {
    int x = b[i].id;
    ans = (ans + (long long)(n - x + 1) * tr.query(x) % mod * a[x] % mod) % mod;
    tr.add(x, x);
  }
  
  tr.init();
  for (int i = 1; i <= n; i++) {
    int x = b[i].id;
    ans = (ans + (long long)x * (tr.query(n) - tr.query(x) + mod) % mod * a[x] % mod) % mod;
    tr.add(x, n - x + 1);
  }
  if (ans < 0) ans += mod; 
  printf("%lld\n", ans);
  return 0;
}
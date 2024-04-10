#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i > 0; i = edge[i].nxt)
#define pii pair <int, int>
#define pci pair <char, int>
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

#define int long long

const int N = 200005;
const ll inf = 2e9;

int a[N], n, m, w;

int nu[N];
bool check(int k) {
  memset(nu, 0, sizeof(nu));
  int used = 0;
  for (int i = 1; i <= n; i++) {
    //printf("nu[%d] = %d\n", i, nu[i]);
    nu[i] += nu[i - 1];
    //printf("nu[%d] = %d\n", i, nu[i]);
    if (a[i] + nu[i] < k) {
      used += (k - a[i] - nu[i]);
      nu[i + w] -= (k - a[i] - nu[i]);
      nu[i] += k - a[i] - nu[i];
    }
  }
  return used > m;
}

signed main() {
  read(n, m, w);
  for (int i = 1; i <= n; i++) {
    read(a[i]); 
  } 
  
  ll l = 1, r = 2e9, ans = 1;
  while (l < r) {
    //printf("%d %d\n", l, r);
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1, ans = mid;
  }
  printf("%lld\n", ans);
  return 0;
}
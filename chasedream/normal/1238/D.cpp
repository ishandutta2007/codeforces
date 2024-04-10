#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rint register int

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

ll ckmin(ll &a, ll b) {
  if (a > b) a = b;
}

const int N = 300005;

int pre[N];
char a[N];
int n;

struct Bit_tree {
  int c[N];
  #define lowbit(x) (x & -x)
  void add(int x, int ad) {
    if (x == 0) return ;
    while (x <= n) {
      c[x] += ad; x += lowbit(x);
    }
  }
  int query(int x) {
    int ret = 0;
    while (x > 0) {
      ret += c[x];
      x -= lowbit(x); 
    }
    return ret;
  }
} bit;

int main() {
  read(n);
  cin >> (a + 1);

  int preA = 0, preB = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 'A') {
      pre[i] = preA;
      preA = i;
    }
    else {
      pre[i] = preB;
      preB = i;
    }
  }
  /*
  for (int i = 1; i <= n; i++) {
    printf("pre[%d] = %d\n", i, pre[i]);
  }
  */
  ll ans = 0LL;
  for (int i = 1; i <= n; i++) {
    if (pre[i] == 0) continue;
    bit.add(pre[i], 1);
    ans += bit.query(pre[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
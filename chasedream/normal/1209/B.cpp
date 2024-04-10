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

const int N = 305;

int a[N], b[N];
int vis[N], st;
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%1d", &vis[i]);
    st += vis[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  
  for (rint times = 0; times <= 500000; times++) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (times >= b[i] && (times - b[i]) % a[i] == 0)
        vis[i] ^= 1;
      ans += vis[i];
    }
    st = max(st, ans);
  }
  printf("%d\n", st);
  return 0;
}
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

const int N = 100005;
int a[N], tmp[N], n;
int cnt[N], over;
int ans = INT_MAX;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    tmp[i] = a[i];
  }
  sort(tmp + 1, tmp + n + 1);
  int m = unique(tmp + 1, tmp + n + 1) - tmp - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(tmp + 1, tmp + m + 1, a[i]) - tmp;
    cnt[a[i]] ++;
    if (cnt[a[i]] == 2) over ++;
  }
  
  for (int i = 1; i <= n; i++) {
    int j = i, fuck = over;
    for (int j = 1; j <= n; j++) tmp[j] = cnt[j];
    while (j <= n && fuck) {
      if (--tmp[a[j]] == 1) fuck--;
      j++;
    }
    if (fuck == 0) ans = min(ans, j - i);
  }
  printf("%d\n", ans);
  return 0;
}
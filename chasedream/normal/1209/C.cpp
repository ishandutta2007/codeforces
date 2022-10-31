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

int a[N], n;
int vis[N];

bool check(int dig) {
  int lower = -1, id = 0;
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < dig) {
      if (lower <= a[i]) vis[i] = 1, lower = a[i], id = i;
      else return 0;
    }
  }
  for (int i = id + 1; i <= n; i++) {
    if (a[i] == dig) vis[i] = 1;
  }
  
  lower = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > dig || (a[i] == dig && !vis[i])) {
      if (lower <= a[i]) lower = a[i];
      else return 0;
    }
  }
  return 1;
}

void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%1d", &a[i]);
  }
  int ans = -1;
  for (int dig = 0; dig <= 9; dig++) {
    if (check(dig)) {
      ans = dig;
      break;
    }
  }
  if (ans == -1) puts("-");
  else {
    for (int i = 1; i <= n; i++) {
      if (vis[i]) putchar('1');
      else putchar('2');
    }
    putchar('\n');
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}
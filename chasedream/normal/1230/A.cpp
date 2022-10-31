#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
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

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

int a[4], ans;

int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%d", &a[i]);
    ans += a[i];
  }
  if (ans & 1) {
    puts("NO"); exit(0);
  }
  for (int i = 0; i < 15; i++) {
    int tot = 0;
    for (int j = 0; j < 4; j++)
      if (i & (1 << j))
        tot += a[j];
    if (tot * 2 == ans) {
      puts("YES"); exit(0);
    }
  }
  puts("NO");
  return 0;
}
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

const int N = 300005;

char s[N];
int len, r;
long long ans = 0LL;

int main() {
  cin >> s;
  len = strlen(s); r = len + 1;
  for (int i = len - 1; i >= 0; i--) {
    for (int j = 1; i + 2 * j < min(len, r); j++) {
      if (s[i] == s[i + j] && s[i] == s[i + 2 * j]) {
        r = min(r, i + 2 * j);
        break;
      }
    }
    ans += max(len - r, 0);
  }
  printf("%lld\n", ans);
  return 0;
}
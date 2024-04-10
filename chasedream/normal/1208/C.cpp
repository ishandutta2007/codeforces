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

const int N = 2005;
int a[N][N], times;
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= n / 2; j++) {
      a[i][j] = 4 * times;
      a[i][j + n / 2] = 4 * times + 1;
      a[i + n / 2][j] = 4 * times + 2;
      a[i + n / 2][j + n / 2] = 4 * times + 3;
      times++;    
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d%c", a[i][j], j == n ? '\n' : ' ');
    }
  } 
  return 0;
}
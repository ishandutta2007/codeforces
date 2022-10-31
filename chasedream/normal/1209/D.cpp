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

int f[N];

int find(int k) {
  return f[k] == k ? k : f[k] = find(f[k]);
}

int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) f[i] = i;

  for (int i = 1; i <= k; i++) {
    int u, v; read(u, v);
    f[find(u)] = find(v);
  }
  
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) cnt++;
  }
  printf("%d\n", k - (n - cnt));
  return 0;
}
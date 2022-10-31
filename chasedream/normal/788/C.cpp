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

const int N = 1001;

int a[N * N], p[10 * N];
int n, k;

void bfs() {
  queue <int> q;
  for (int i = 0; i <= 2000; i++) {
    if (p[i] == 1) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i <= 2000; i++) {
      if (p[i] == 1 && p[u + i - 1000] == 1e9) {
        //printf(">>> %d\n", u + i);
        //assert(u + i - 1000 >= 0);
        p[u + i - 1000] = p[u] + 1;
        q.push(u + i - 1000); 
      }
    }
  }
  return ; 
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= 2000; i++) p[i] = 1e9;

  for (int i = 1; i <= k; i++) {
    scanf("%d", &a[i]);
    a[i] = a[i] - n + 1000;
    p[a[i]] = true;
  }
  
  bfs();
  
  if (p[1000] == 1e9)
    printf("-1\n");
  else
    printf("%d\n", p[1000]);
  return 0;
}
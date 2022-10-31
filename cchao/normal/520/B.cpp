#include <bits/stdc++.h>
using namespace std;

int n, m;

int d[10010];
bool inq[10010];
int main() {
  memset(d, -1, sizeof d);
  scanf("%d%d", &n, &m);
  if (n >= m) {
    printf("%d\n", n - m);
    return 0;
  }
  queue<int> q;
  q.push(n);
  fill(d, d + m + 1, 1e9);
  d[n] = 0;
  while (q.size()) {
    int x = q.front(); q.pop(); inq[x] = false;
    int nxt[] = {x - 1, x * 2};
    for (int y : nxt) {
      if (y <= 0) continue;
      int w = 1;
      if (y > m) {
        w += y - m;
        y = m;
      }
      if (d[y] > d[x] + w) {
        d[y] = d[x] + w;
        if (!inq[y]) {
          q.push(y);
          inq[y] = true;
        }
      }
    }
  }
  printf("%d\n", d[m]);
  return 0;
}
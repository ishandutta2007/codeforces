#include <cstdio>

const int N = 1000 + 10;

int anc[N];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) anc[i] = i;
  if (m != n - 1) return puts("no"), 0;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = find(x);
    y = find(y);
    if (x == y) return puts("no"), 0;
    anc[x] = y;
  }
  puts("yes");
  return 0;
}
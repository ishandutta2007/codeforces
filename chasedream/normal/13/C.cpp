%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 500005;
int heap[N];
int n, cnt;
long long ans = 0LL;

void up(int u) {
  int fa = u >> 1;
  if (fa != 0 && heap[fa] < heap[u]) {
    swap(heap[fa], heap[u]);
    up(fa);
  }
}

void down(int u) {
  int son = u << 1;
  if (son <= cnt) {
    if (son < cnt && heap[son] < heap[son + 1]) son++;
    if (heap[u] < heap[son]) {
      swap(heap[u], heap[son]);
      down(son);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x; scanf("%d", &x);
    heap[++cnt] = x; up(cnt);
    
    int cxk = heap[1];
    if (x < cxk) {
      ans += cxk - x;
      heap[1] = heap[cnt--]; down(1);
      heap[++cnt] = x; up(cnt);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
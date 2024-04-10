#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt[101] = {};
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    int s = m - t;
    int pass = 0;
    for (int j = 1; j <= 100; ++j) {
      int t = min(cnt[j], s / j);
      s -= t * j;
      pass += t;
    }
    printf("%d%c", i - pass, " \n"[i == n - 1]);
    cnt[t]++;
  }
  return 0;
}
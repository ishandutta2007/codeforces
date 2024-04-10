#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int N = 40005;
int vis[N], n;
int ans;

int main() {
  scanf("%d", &n);
  for (int i = 3; i <= n; i++) {
    int c = i * i;
    for (int j = 1; j < i; j++) {
      if (c % j == 0) {
        if ((j + c / j) % 2 != 0) continue;
        int _c = (j + c / j) >> 1;
        if (_c <= n)
          ans++;
      }
    }
  } 
  /*
  for (int i = 3; i <= n; i += 2) {
    int c = (i * i + 1) >> 1;
    if (c > n) break;
    for (int j = i; j / i * c <= n; j += i) {
      if (!vis[j]) {
        vis[j] = 1;
        printf("%d %d %d\n", j, (int)sqrt((j / i * c) * (j / i * c) - j * j), j / i * c);
        ans++;
      }
    }    
  }
  */
  printf("%d\n", ans >> 1);
  return 0;
}
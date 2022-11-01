#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    while(x--) {
      int y;
      scanf("%d", &y);
      a[y] = 1;
    }
  }
  for(int i = 1; i<=m; i++)
    if(a[i] != 1) {
      puts("NO");
      return 0;
    }
  puts("YES");

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define maxN 222222

int n, q;
long long a[50][50];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2 == 0)
        a[i][j] = 1ll << (i + j);
      printf("%lld ", a[i][j]);
    }
    printf("\n");
  }
  fflush(stdout);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    long long k;
    scanf("%lld", &k);
    int x = 0, y = 0;
    vector<array<int, 2>> path;
    path.push_back({0, 0});
    k = (k - 1) / 2;
    for (int j = 0; j < n + n - 2; j++) {
      if (x == n - 1)
        y++;
      else if (y == n - 1)
        x++;
      else {
        if (k % 2 == 1) {
          if (a[x + 1][y])
            x++;
          else
            y++;
        } else {
          if (a[x + 1][y])
            y++;
          else
            x++;
        }
      }
      if (a[x][y])
        k -= 1;
      k /= 2;
      path.push_back({x, y});
    }
    for (auto cord : path)
      printf("%d %d\n", cord[0] + 1, cord[1] + 1);
    fflush(stdout);
  }
}
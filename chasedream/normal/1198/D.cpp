%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 51;
char a[N][N];
int f[N][N][N][N];
int n;
 
char read_char() {
  for (;;) {
    char op = getchar();
    if (op == '#' || op == '.')
      return op;
  }  
}
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = (read_char() == '#');
      f[i][j][i][j] = a[i][j];
    }
  }
 
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (x == 1 && y == 1) continue;
      for (int i = 1; i <= n - x + 1; i++) {
        for (int j = 1; j <= n - y + 1; j++) {
          int k = i + x - 1, l = j + y - 1;
          f[i][j][k][l] = max(x, y);
          for (int z = i; z < k; z++)
            f[i][j][k][l] = min(f[i][j][k][l], f[i][j][z][l] + f[z + 1][j][k][l]);
          for (int z = j; z < l; z++)
            f[i][j][k][l] = min(f[i][j][k][l], f[i][j][k][z] + f[i][z + 1][k][l]);
        }
      }
    }
  }
  printf("%d\n", f[1][1][n][n]);
  return 0;
}
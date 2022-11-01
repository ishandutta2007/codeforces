#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int h, w;
char s[N][N];

int lef[N][N], up[N][N];

int main() {
  scanf("%d%d", &h, &w);
  for(int i = 0; i<h; i++)
    scanf("%s", s[i]);
  for(int i = 0; i<h; i++) {
    lef[i][0] = 0;
    for(int j = 1; j<w; j++) {
      lef[i][j] = lef[i][j-1] + (s[i][j] == '.' && s[i][j-1] == '.');
    }
    if(i > 0)
      for(int j = 0; j<w; j++)
        lef[i][j] += lef[i-1][j];
  }
  for(int i = 1; i<h; i++) {
    for(int j = 0; j<w; j++)
      up[i][j] = up[i-1][j] + (s[i][j] == '.' && s[i-1][j] == '.');
  }
  for(int i = 1; i<h; i++) {
    for(int j = 1; j<w; j++)
      up[i][j] += up[i][j-1];
  }

  int q;
  scanf("%d", &q);
  while(q--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    r1--; c1--; r2--; c2--;
    int ans = lef[r2][c2] + up[r2][c2];
    ans -= up[r1][c2];
    ans -= lef[r2][c1];
    if(r1 > 0) 
      ans += lef[r1-1][c1]-lef[r1-1][c2];
    if(c1 > 0)
      ans += up[r1][c1-1] - up[r2][c1-1];
    printf("%d\n", ans);
  }
  return 0;
}
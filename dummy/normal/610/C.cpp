#include <bits/stdc++.h>

using namespace std;

const int N = (1<<10) + 5;

char s[10][N][N], inv[256];

int main() {
  inv['*'] = '+';
  inv['+'] = '*';
  s[0][0][0] = '*';
  int k;
  cin >> k;
  for(int i = 1; i<=k; i++) {
    int off = (1<<(i-1));
    for(int j = 0; j<off; j++) {
      for(int z = 0; z<off; z++) {
        s[i][j][z] = s[i][off+j][z] = s[i][j][off+z] = s[i-1][j][z];
        s[i][off+j][off+z] = inv[s[i-1][j][z]];
      }
    }
  }
  int off = (1<<k);
  for(int i = 0; i<off; i++) {
    s[k][i][off] = '\0';
    printf("%s\n", s[k][i]);
  }
  return 0;
}
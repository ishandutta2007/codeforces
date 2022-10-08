/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.05.07
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 501;
int mod, f[2][N][N];

void add( int &a, int b ) {
  if ((a += b) >= mod)
    a -= mod;
}


int main() {
  int n, m, b;
  cin >> n >> m >> b >> mod;
  int a[n];
  forn(i, n)
    cin >> a[i];
  memset(f, 0, sizeof(f));
  f[0][0][0] = 1 % mod;
  forn(i, m) {
    int x = i & 1, y = (i + 1) & 1;
    memset(f[y], 0, sizeof(f[y]));
    auto relax = [&]( int t, int i, int j, int df ) {
      if (i < n && j <= b)
        add(f[t][i][j], df);
    };
    forn(i, n)
      forn(j, b + 1) {
        relax(x, i + 1, j, f[x][i][j]);
        relax(y, i, j + a[i], f[x][i][j]);
      }
  }
  int res = 0;
  forn(i, n)
    forn(j, b + 1)
      add(res, f[m & 1][i][j]);
  cout << res << endl;
  return 0;
}
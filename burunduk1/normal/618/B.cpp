/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  int a[n][n];
  forn(i, n)
    forn(j, n)
      cin >> a[i][j];
  vector<int> u(n, 0);
  forn(i, n) 
    forn(j, n) {
      if (!u[j]) {
        int bad = 0;
        forn(k, n)
          bad |= (a[j][k] > i + 1);
        if (!bad) {
          //printf("%d: %d\n", i, j);
          u[j] = i + 1;
          break;
        }
      }
	}
  forn(i, n)
    printf("%d ", u[i]);
  return 0;
}
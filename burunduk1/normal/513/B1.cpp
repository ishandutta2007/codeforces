/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.06
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int calc( int n, int *p ) {
  int sum = 0;
  forn(i, n) {
    int mi = p[i];
    for (int j = i; j < n; j++) 
      mi = min(mi, p[j]), sum += mi;
  }
  return sum;
}

int main() {
  int n, m;
  cin >> n >> m;
  int p[n];

  forn(i, n) p[i] = i;
  int ma = 0;
  do 
    ma = max(ma, calc(n, p));
  while (next_permutation(p, p + n));

  forn(i, n) p[i] = i;
  do 
    if (calc(n, p) == ma && !--m)
      break;
  while (next_permutation(p, p + n));

  forn(i, n)
    printf("%d ", p[i] + 1);
  return 0;
}
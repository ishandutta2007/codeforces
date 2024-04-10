/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int g = 0;
  forn(i, n) {
    scanf("%d", &a[i]);
    g = __gcd(g, a[i]);
  }
  forn(i, n)  {
    a[i] /= g;
    while (a[i] % 2 == 0) a[i] /= 2;
    while (a[i] % 3 == 0) a[i] /= 3;
    if (a[i] != 1) {
      puts("No");
      return 0;
    }
  }
      puts("Yes");

  return 0;
}
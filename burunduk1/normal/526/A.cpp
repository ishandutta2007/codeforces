/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.04
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  string s;
  cin >> n >> s;
  forn(i, n)
    for (int k = 1; i + 4 * k < n; k++) {
      int good = 1;
      forn(j, 5)
        if (s[i + k * j] == '.')
          good = 0;
      if (good) {
        puts("yes");
        return 0;
      }
    }
  puts("no");
  return 0;
}
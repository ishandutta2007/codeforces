/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n; 
  cin >> n;
  for (int k = 30; k >= 0; k--)
    if ((n >> k) & 1)
      cout << (k + 1) << " ";
      
  return 0;
}
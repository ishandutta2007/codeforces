/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.04
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
  int c, hr, hb, wr, wb;
  ll sum = 0, ma = 0;
  cin >> c >> hr >> hb >> wr >> wb;
  if (wr > wb)
    swap(wr, wb), swap(hr, hb);
  int x = max(0LL, c / ((ll)wr * wb) - 2);
  sum += x * max((ll)hr * wb, (ll)hb * wr);
  c -= x * wr * wb;
  for (int i = 0; wb * i <= c; i++) 
    ma = max(ma, (ll)hb * i + (ll)hr * ((c - wb * i) / wr));
  cout << sum + ma << endl;
  return 0;
}
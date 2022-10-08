/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.12.06
 */

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int N = (int)1e5 + 10;

int n, d, a[N];

int main()
{
  scanf("%d%d", &n, &d);
  forn(i, n)
    scanf("%d", &a[i]);

  int k = 0;
  ll sum = 0;
  forn(i, n)
  {
    while (k < n && a[k] <= a[i] + d)
      k++;
    int x = k - i - 1;
    //printf("[%d,%d) x=%d\n", i, k, x);
    sum += (ll)x * (x - 1) / 2;
  }
  cout << sum;
  return 0;
}
/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.24
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n, a, sum = 0;
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a), sum += a;
  printf("%.9f\n", (double)sum / n);
    
  return 0;
}
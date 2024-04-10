/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.11
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int N = (int)1e5 + 10;

int n, m, k, a[N], l[N], r[N], d[N], add[N];
ll sum[N];

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  forn(i, n)
    scanf("%d", &a[i]);
  forn(i, m)
    scanf("%d%d%d", &l[i], &r[i], &d[i]);
  forn(i, k)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    add[x - 1]++, add[y]--;
  }

  int cnt = 0;
  forn(i, m)
  {
    cnt += add[i];
    sum[l[i] - 1] += (ll)cnt * d[i];
    sum[r[i]] -= (ll)cnt * d[i];
  }

  ll add = 0;
  forn(i, n)
    printf("%I64d ", a[i] + (add += sum[i]));
  return 0;
}
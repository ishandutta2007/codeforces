#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int maxn = 1010;

int n, t, a[maxn], x[maxn];

set <int> s;

void Try( int z )
{
//  printf("%d\n", z);
  forn(i, n)
    if (z + t > x[i] && z < x[i] + a[i])
      return;
  s.insert(z);
}

int main()
{
  scanf("%d%d", &n, &t), t *= 2;
  forn(i, n)
    scanf("%d%d", &x[i], &a[i]), x[i] *= 2, x[i] -= a[i], a[i] *= 2;
  forn(i, n)
    Try(x[i] + a[i]), Try(x[i] - t);
  printf("%d\n", s.size());
  return 0;
}
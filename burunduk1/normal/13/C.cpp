#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = 5010;

int n, a[maxn], x[maxn];
ll f[maxn];

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a[i]), x[i] = a[i];
  sort(x, x + n);

  memset(f, 0, sizeof(f));
  forn(i, n)
  {
    forn(j, n)
      f[j] += abs(x[j] - a[i]);
    forn(j, n) if (j)
    {
      int add = x[j] - x[j - 1];
      if (x[j] <= a[i])
        add = -add;
      f[j] = min(f[j], f[j - 1] + add);
    }
/*
    printf("%d:\n", i);
    forn(j, n)
      printf("f(%d) = %I64d\n", x[j], f[j]);
*/
  }

  ll res = (ll)1e18;
  forn(i, n)
    res = min(res, f[i]);
  cout << res << endl;
  return 0;
}
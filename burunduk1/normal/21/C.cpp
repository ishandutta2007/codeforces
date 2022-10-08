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

const int maxn = (int)1e5 + 10;

int sum = 0, n, a[maxn], is1[maxn], cnt1[maxn];

void Exit( int ans )
{
  printf("%d\n", ans);
  exit(0);
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a[i]), sum += a[i];
  if (sum % 3 != 0)
    Exit(0);

  int x = 0;
  sum /= 3;
  forn(i, n)
  {
    x += a[i];
    if (x == sum)
      is1[i] = 1;
  }
  forn(i, n)
    cnt1[i + 1] = cnt1[i] + is1[i];

  ll res = 0;
  x = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    x += a[i];
    if (i > 0 && x == sum)
      res += cnt1[i - 1];
  }
  cout << res << endl;
  return 0;
}
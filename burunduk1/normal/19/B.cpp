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

const int maxn = 2030;

int n, t, c;
ll f1[2 * maxn];
ll f2[2 * maxn];

inline void relax( ll &a, ll b )
{
  a = min(a, b);
}

int main()
{
  scanf("%d", &n);
  memset(f1, 0x10, sizeof(f1));
  f1[maxn] = 0;
  forn(i, n)
  {
    scanf("%d%d", &t, &c);

    memset(f2, 0x10, sizeof(f2));
    forn(i, 2 * maxn)
    {
      if (i)
        relax(f2[i - 1], f1[i]);
      relax(f2[min(i + t, 2 * maxn - 1)], f1[i] + c);
    }
    memcpy(f1, f2, sizeof(f1));
  }

  ll ans = (ll)1e18;
  for (int i = maxn; i < 2 * maxn; i++)
    relax(ans, f1[i]);
  cout << ans << endl;
  return 0;
}
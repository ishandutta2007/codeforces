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

int n;

ll F( ll x )
{
  ll res = 0;
  forn(k, 60)
  {
    ll len = 1LL << k;
    ll num = x / (len * 2);
    ll sum = num * len;
    ll rest = x % (len * 2);
    if (rest >= len)
      sum += rest - len;
    if (sum & 1)
      res |= 1LL << k;
  }
  return res;
}

int main()
{
  ll res = 0;
  scanf("%d", &n);
  while (n--)
  {
    ll l, n;
    scanf("%I64d%I64d", &l, &n);
//    printf("%I64d ^ %I64d\n", F(l), F(l + n));
    res ^= F(l) ^ F(l + n);
  }
  puts(!res ? "bolik" : "tolik");
  return 0;
}
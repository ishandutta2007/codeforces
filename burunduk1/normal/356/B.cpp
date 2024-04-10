/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.10.15
 */

#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fill(a, x) memset(a, x, sizeof(a))

typedef long long ll;

const int N = (int)1e6 + 1;

int sn, tn, cs[26], ct[26];
char s[N], t[N];

int main()
{
  ll n, m;
  scanf("%I64d%I64d ", &n, &m);
  gets(s), sn = strlen(s);
  gets(t), tn = strlen(t);
  int g = __gcd(sn, tn);
  ll ans = 0;
  //printf("%d : %d, %d : %s, %s\n", g, sn, tn ,s, t);
  forn(i, g)
  {
    fill(cs, 0);
    fill(ct, 0);
    for (int j = i; j < sn; j += g)
      cs[s[j] - 'a']++;
    for (int j = i; j < tn; j += g)
      ct[t[j] - 'a']++;
    forn(i, 26)
      ans += (ll)cs[i] * ct[i];
  }
  printf("%I64d\n", (n / (tn / g)) * ((ll)(sn / g) * tn - ans));
  return 0;
}
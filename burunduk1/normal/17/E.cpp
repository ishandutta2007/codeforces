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

const int MOD = 51123987;
const int mlen = (int)4e6 + 10;

char s[mlen];
int k, n, L, R, z[mlen];

ll sum = 0;
int K[mlen], cnt[mlen];

inline void Add( int l, int r )
{  
  K[l]++, K[r + 1]--;
}

inline void inc( int &a, int b )
{
  if ((a += b) >= MOD)
    a -= MOD;
}

int main()
{
  scanf("%d ", &k);
  s[n++] = '#';
  s[n++] = '*';
  forn(i, k)
    s[n++] = getc(stdin), s[n++] = '*';
  s[n++] = '$';
  L = R = -1;
  for (int i = 1; i < n - 1; i++)
  {
    k = 0;
    if (R > i)
      k = min(R - i, z[L + (R - i)]);
    while (s[i - k] == s[i + k])
      k++;
    z[i] = k;
    if (i + k > R)
      L = i - k, R = i + k;
  }

  forn(i, n)
    if (z[i] > 0)
    {
      int len = z[i] - 1;
      if (s[i - len] == '*')
        len--;
      if (len >= 0)
      {
        z[i] = len / 2 + 1;
        Add(i / 2 - z[i] + 1, i / 2);
      }
      else
        z[i] = 0;
    }

  int sumA = 0, sumK = 0, x = 0;
  forn(i, mlen)
    inc(sumK, K[i]), inc(sumA, sumK), inc(x, sumA), inc(cnt[i], x);

  int skip = 0;
  forn(i, n)
    if (z[i] > 0)
    {
      inc(skip, z[i]);
      int L = (i + 1) / 2;
      sum += (cnt[L + z[i] - 1] - cnt[L - 1] - (ll)skip * z[i]) % MOD;
      sum += ((ll)z[i] * (z[i] - 1) / 2) % MOD;
    }

  cout << (sum % MOD + MOD) % MOD << endl;
  return 0;
}
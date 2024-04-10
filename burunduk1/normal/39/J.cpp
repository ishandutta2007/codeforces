#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

const int mlen = (int)1e6 + 10;

char s[mlen], t[mlen];
int n;

int main()
{
  gets(t);
  gets(s);
  n = strlen(s);

  int L = 0, R = 0;
  while (s[L] == t[L])
    L++;
  while (s[n - R - 1] == t[n - R])
    R++;

  int cnt = 0;
  forn(i, n + 1)
    if (L >= i && i + R >= n)
      cnt++;
  printf("%d\n", cnt);
  forn(i, n + 1)
    if (L >= i && i + R >= n)
      printf("%d ", i + 1);
  return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

const int maxn = 103;

int main()
{
  int k;
  scanf("%d", &k);
  forn(i, k) if (i)
  {
    forn(j, k) if (j)
    {
      char s[20];
      int n = 0, x = i * j;
      while (!n || x)
        s[n++] = x % k, x /= k;
      while (n--)
        printf("%d", s[n]);
      printf(" ");
    }
    puts("");
  }
  return 0;
}
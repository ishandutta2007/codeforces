#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

const int maxn = 103;

int n, m, k, a[maxn], b[maxn], res = (int)1e9;
vector <int> v;

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  forn(i, m)
    scanf("%d", &a[i]);
  forn(i, k)
    scanf("%d", &b[i]);

  forn(i, m)
  {
    int cnt = 0;
    forn(j, k)
      cnt += (b[j] % a[i] == 0);
    if (cnt < res)
      res = cnt, v.clear();
    if (res == cnt)
      v.pb(i);
  }
  printf("%d\n", sz(v));
  forn(i, sz(v))
    printf("%d ", v[i] + 1);
  return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

int n;
vector <int> v;

int main()
{
  scanf("%d", &n);

  int cc = 1, a;
  forn(i, n)
  {
    scanf("%d", &a);
    if (a == cc)
      v.pb(i), cc++;
  }

  printf("%d\n", sz(v));
  forn(i, sz(v))
    printf("%d ", v[i] + 1 + 2000);
  return 0;
}
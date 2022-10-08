#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

int main()
{
  int x[2][3], cnt = 0;
  forn(i, 2)
    forn(j, 3)
      scanf("%d", &x[i][j]);
  forn(j, 3)
    cnt += (x[0][j] != x[1][j]);
  puts(cnt == 3 ? "NO" : "YES");
  return 0;
}
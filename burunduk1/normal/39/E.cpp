#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

const int mlen = (int)1e6 + 10;

int m[(int)1e5][50];
int a, b, n;

int Solve( int a, int b )
{
  // a^b
//  fprintf(stderr, "a=%d, b=%d\n", a, b);

  int x = n - 1;
  forn(i, b)
    x /= a;
  if (x == 0)
    return 1;

  if (a == 1 && b >= 40)
    return 0;

  int &res = m[a][b];
  if (res <= 1)
    return res;
  return res = max(-Solve(a + 1, b), -Solve(a, b + 1));
}

int main()
{
  scanf("%d%d%d", &a, &b, &n);
  memset(m, 0x10, sizeof(m));

  int f = Solve(a, b);
  if (f == 1)
    puts("Masha");
  else if (f == -1)
    puts("Stas");
  else
    puts("Missing");
  return 0;
}
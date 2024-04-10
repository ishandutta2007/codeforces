/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

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

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }

const int mlen = 303;

int p[6];
char s[6][mlen];
char res[mlen][mlen];
vector <vector<string> > x;

void draw( int sx, int sy, const char *s, int dx, int dy )
{
  while (*s)
    res[sy][sx] = *s++, sx += dx, sy += dy;
}

int main()
{
  forn(i, 6)
    gets(s[i]), p[i] = i;
  do
  {
    #define S(i) s[p[i]]
    int H = strlen(S(0)) - 1;
    int W = strlen(S(1)) - 1;
    int h = strlen(S(2)) - 1;
    int w = strlen(S(3)) - 1;
    int bad = 0;
    bad |= (strlen(S(0)) != strlen(S(2)) + strlen(S(4)) - 1);
    bad |= (strlen(S(1)) != strlen(S(3)) + strlen(S(5)) - 1);
    bad |= (S(0)[0] != S(3)[w]);
    bad |= (S(0)[h] != S(1)[w]);
    bad |= (S(0)[H] != S(5)[0]);
    bad |= (S(2)[0] != S(3)[0]);
    bad |= (S(2)[h] != S(1)[0]);
    bad |= (S(4)[0] != S(1)[W]);
    bad |= (S(4)[H - h] != S(5)[W - w]);
    if (bad)
      continue;
    memset(res, '.', sizeof(res));
    draw(0, 0, S(2), 0, 1);
    draw(w, 0, S(0), 0, 1);
    draw(W, h, S(4), 0, 1);
    draw(0, 0, S(3), 1, 0);
    draw(0, h, S(1), 1, 0);
    draw(w, H, S(5), 1, 0);

    vector <string> R;
    forn(i, H + 1)
      res[i][W + 1] = 0, R.pb(res[i]);
    x.pb(R);
  } while (next_permutation(p, p + 6));

  sort(all(x));
  if (!x.size())
    puts("Impossible");
  else
  {
    forn(i, x[0].size())
    {
      forn(j, x[0][0].size())
        printf("%c", x[0][i][j]);
      puts("");
    }
  }
  return 0;
}
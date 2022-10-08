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

enum {EMPTY, LINE, INF};

int Type( int a, int b, int c )
{
  if (a == 0 && b == 0)
    if (c == 0)
      return INF;
    else
      return EMPTY;
  return LINE;
}

void Exit( int ans )
{
  printf("%d\n", ans);
  exit(0);
}

int main()
{
  int a1, b1, c1;
  int a2, b2, c2;
  scanf("%d%d%d", &a1, &b1, &c1);
  scanf("%d%d%d", &a2, &b2, &c2);

  int t1 = Type(a1, b1, c1);
  int t2 = Type(a2, b2, c2);
  if (t1 == EMPTY || t2 == EMPTY)
    Exit(0);
  if (t1 == INF || t2 == INF)
    Exit(-1);
  if (a1 * b2 - a2 * b1 != 0)
    Exit(1);
  if (a1 * c2 - a2 * c1 == 0 && b1 * c2 - b2 * c1 == 0)
    Exit(-1);
  Exit(0);
  return 0;
}
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

int main()
{
  int minr = 1e7, mins = 1e7, maxr = -1, maxs = -1;
  int red, stup;
  scanf("%d%d", &red, &stup);

  char s[200];

  REP(i, red) {
    scanf(" %s", s);
    REP(j, stup) {
      if (s[j] == 'B') {
        minr = min(minr, i);
        mins = min(mins, j);
        maxr = max(maxr, i);
        maxs = max(maxs, j);
      }
    }
  }

  printf("%d %d\n", (minr + maxr) / 2 + 1, (mins + maxs) / 2 + 1);

  return 0;
}
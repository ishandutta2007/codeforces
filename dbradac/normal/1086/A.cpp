#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1005;

int x[3], y[3];
int cl[MAX][MAX];

int main()
{
  REP(i, 3) scanf("%d%d", &x[i], &y[i]);

  int sol = MAX*MAX*MAX, r=-1, s=-1;
    
  REP(i, MAX) {
    REP(j, MAX) {
      int tmp = 0;
      REP(k, 3)
	tmp += abs(x[k] - i) + abs(y[k] - j);
      
      tmp++;
      if (tmp < sol) {
	sol = tmp;
	r = i, s = j;
      }
    }
  }

  printf("%d\n", sol);
  REP(k, 3) {
    int x1 = r, x2 = x[k];
    int y1 = s, y2 = y[k];
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    for (int i=x1; i<=x2; i++)
      cl[i][y[k]] = 1;

    for (int j=y1; j<=y2; j++)
      cl[r][j] = 1;
  }

  REP(i, MAX) {
    REP(j, MAX) {
      if (cl[i][j]) {
	printf("%d %d\n", i, j);
	sol--;
      }
    }
  }

  assert(!sol);

  return 0;
}
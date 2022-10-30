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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 400, MAXN = 32;

int pr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ps[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n;
int t[MAXN];
int ima[MAXN][MAX][MAX][8];
int bio[MAX][MAX];

void go()
{
  ima[0][MAX/2][MAX/2][0] = 1;
  bio[MAX/2][MAX/2] = 1;

  REP(i, n) {
    REP(r, MAX)
      REP(s, MAX) {
        REP(sm, 8) {
          if (ima[i][r][s][sm]) {
            int nr = r, ns = s;
            bio[r][s] = 1;
            REP(j, t[i]) {
              nr += pr[sm];
              ns += ps[sm];
              bio[nr][ns] = 1;
            }

            assert(nr >= 0 && ns >= 0 && nr < MAX && ns < MAX);
            ima[i+1][nr][ns][(sm+1) % 8] = 1;
            ima[i+1][nr][ns][(sm+7) % 8] = 1;
          }
        }
      }
  }
}

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &t[i]);
  t[0]--;

  go();
  int rje = 0;

  REP(i, MAX)
    REP(j, MAX)
    rje += bio[i][j];

  printf("%d\n", rje);

  return 0;
}
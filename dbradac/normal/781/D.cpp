#include <bitset>
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

const int MAX = 505, MAXK = 62;
const ll INF = 1e18;

int moze[MAXK][MAX][MAX][2];
bitset <MAX> red[MAXK][MAX][2], stup[MAXK][MAX][2];
bitset <MAX> ima;

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  REP(i, m) {
    int a, b, st;
    scanf("%d%d%d", &a, &b, &st); a--; b--;
    moze[0][a][b][st] = 1;
  }

  REP(i, n) REP(st, 2) REP(j, n) {
    red[0][i][st][j] = moze[0][i][j][st];
    stup[0][i][st][j] = moze[0][j][i][st];
  }

  FOR(kol, 1, MAXK) {    
    REP(i, n) {
      REP(j, n) {
	REP(st, 2) {
	  bitset <MAX> T = red[kol-1][i][st] & stup[kol-1][j][1^st];
	  moze[kol][i][j][st] = T.any();
	}
      }
    }

    REP(i, n) REP(st, 2) REP(j, n) {
      red[kol][i][st][j] = moze[kol][i][j][st];
      stup[kol][i][st][j] = moze[kol][j][i][st];
    }
  }

  ll rje = 0;
  REP(i, n) ima[i] = 1;
  
  int tmpst = 0;
  for (int kol=MAXK-1; kol>=0; kol--) {
    bitset <MAX> T;
    REP(i, n)
      if (ima[i])
	T |= red[kol][i][tmpst];

    if (T.any()) {
      ima = T;
      tmpst ^= 1;
      rje += 1ll << kol;
    }
  }

  printf("%lld\n", rje > INF ? -1 : rje);

  return 0;
}
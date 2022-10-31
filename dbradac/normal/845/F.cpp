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

const int MAXN = 252, MAXS = 15, MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

char s[MAXN][MAXN];
int brred, brstup;
int dp[MAXN][1<<MAXS][2][2];

void transpose() {
  char tmp[MAXN][MAXN];
  memset(tmp, 0, sizeof tmp);
  
  REP(i, brred) REP(j, brstup)
    tmp[j][i] = s[i][j];

  swap(brred, brstup);
  memcpy(s, tmp, sizeof s);
}

int rek(int red, int stup, int msk_stup, int st, int dosad) {
  if (dosad > 1) return 0;
  if (red == brred) return 1;
  if (stup == brstup)
    return rek(red+1, 0, msk_stup, 0, dosad);

  int poz = red * brstup + stup;
  assert(poz < MAXN);
  if (dp[poz][msk_stup][st][dosad] != -1)
    return dp[poz][msk_stup][st][dosad];

  int ret = 0;
  
  if (s[red][stup] == '.') {    
    ret = add(ret, rek(red, stup+1, msk_stup | (1<<stup), 1, dosad));
    ret = add(ret, rek(red, stup+1, msk_stup, st, dosad + !(st || ((msk_stup >> stup) & 1))));
  }
  else
    ret = add(ret, rek(red, stup+1, msk_stup & (((1<<brstup) - 1) ^ (1<<stup)), 0, dosad));

  return dp[poz][msk_stup][st][dosad] = ret;    
}

int main()
{
  scanf("%d%d", &brred, &brstup);

  REP(i, brred) scanf("%s", s[i]);

  if (brred < brstup)
    transpose();

  // REP(i, brred)
  //   printf("%s\n", s[i]);

  assert(brstup <= MAXS);

  memset(dp, -1, sizeof dp);
  printf("%d\n", rek(0, 0, 0, 0, 0));  

  return 0;
}
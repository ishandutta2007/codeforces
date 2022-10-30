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

const int MAX = 16, INF = 0x3f3f3f3f;

int dp[1<<MAX][10+MAX*MAX][2]; //minimizirat ode2
P cij[MAX];
int tip[MAX];
int n;
P suma[1<<MAX];
P br[1<<MAX];

int main()
{
  scanf("%d", &n);

  REP(i, n) {
    char s[3];
    scanf(" %s%d%d", s, &cij[i].X, &cij[i].Y);
    if (s[0] == 'R') tip[i] = 0;
    else tip[i] = 1;      
  }

  REP(i, 1<<n) {
    REP(j, n) {
      if (i>>j & 1) {
        suma[i].X += cij[j].X;
        suma[i].Y += cij[j].Y;

        if (tip[j] == 0) br[i].X++;
        else br[i].Y++;
      }
    }

  }

  memset(dp, -1, sizeof dp);
  dp[0][0][0] = 0;

  int rje = INF;
  REP(msk, (1<<n))
    REP(kol, n*(n+1) / 2 + 4)
      REP(st, 2) {
        int ja = dp[msk][kol][st];

        if (ja == -1) continue;

        if (msk == 2 && kol == 0) {
          TRACE(st);
          TRACE(ja);

        }

        int dosad_pot = max(suma[msk].X - kol, suma[msk].Y - ja);

        int pare1 = dosad_pot - (suma[msk].X - kol);
        int pare2 = dosad_pot - (suma[msk].Y - ja);

        assert(pare1 >= 0 && pare2 >= 0);

        if (msk == (1<<n) - 1) {
          rje = min(rje, dosad_pot);
//          if (dosad_pot == 2)
  //          printf("KKK %d %d %d\n", kol, st, ja);
        }

        REP(i, n) {
          if (!(msk>>i & 1)) {
            int nst;
            int a = cij[i].X - pare1 - br[msk].X;
            int b = cij[i].Y - pare2 - br[msk].Y;

            if (a > b) nst = 0;
            else nst = 1;

            int nkol = kol + min(br[msk].X, cij[i].X);
            int nja = ja + min(br[msk].Y, cij[i].Y);

    //        printf("NMASK %d    %d %d %d\n", msk, msk|(1<<i), nkol, nja);
            dp[msk|(1<<i)][nkol][nst] = max(dp[msk|(1<<i)][nkol][nst], nja);
          } 
        }
      }

  printf("%d\n", rje + n);

  return 0;
}
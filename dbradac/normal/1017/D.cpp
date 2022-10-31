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

const int MLEN = 12, MAXVAL = 105;

int kolko[1<<MLEN];
int cnt[1<<MLEN][MAXVAL];
int val_msk[1<<MLEN];
int val[MLEN+2];
char s[20];

int main()
{
  int len, n, brq;

  scanf("%d%d%d", &len, &n, &brq);

  REP(i, len) scanf("%d", &val[i]);
  REP(i, 1<<len) {
    REP(j, len) {
      if (i>>j & 1)
        val_msk[i] += val[j];
    }
  }

  REP(i, n) {
    scanf(" %s", s);
    int msk=0;
    REP(j, len)
      if (s[j] == '1') msk |= 1<<j;

    kolko[msk]++;
  }

  REP(i, 1<<len) {
    REP(j, 1<<len) {
      int msk = ((1<<len)-1) ^ i ^ j;
      cnt[i][min(val_msk[msk], 102)] += kolko[j];
    }

    FOR(j, 1, 102)
      cnt[i][j] += cnt[i][j-1];
  }

  REP(i, brq) {
    scanf(" %s", s);
    int va;
    scanf("%d", &va);

    int msk=0;
    REP(j, len)
      if (s[j] == '1') msk |= 1<<j;
  
    printf("%d\n", cnt[msk][va]);
  }

  return 0;
}
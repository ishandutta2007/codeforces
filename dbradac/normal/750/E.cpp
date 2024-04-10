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

const int MAX = 1<<18, TOUR = MAX, INF = 0x3f3f3f3f;

struct node {
  int dp[5][5];
  node() {
    memset(dp, INF, sizeof dp);
  }
} t[2*TOUR];

//int DB=0;
node merge(const node &l, const node &r)
{
  node ret;

//  if (DB) printf("DADAD %d\n", r.dp[4][4]);

  REP(poc, 5)
    for (int izm=poc; izm<5; izm++)
      for (int kraj=izm; kraj<5; kraj++)
        ret.dp[poc][kraj] = min(ret.dp[poc][kraj], l.dp[poc][izm] + r.dp[izm][kraj]);

  return ret;
}

char slova[] = "2017";
int n;
char s[MAX];

void init()
{
  REP(i, n) {
    REP(j, 5) t[i+TOUR].dp[j][j] = 0;
    if (s[i] == '2') {
      t[i+TOUR].dp[0][1] = 0;
      t[i+TOUR].dp[0][0] = 1;
    }
    if (s[i] == '0') {
      t[i+TOUR].dp[1][2] = 0;
      t[i+TOUR].dp[1][1] = 1;
    }
    if (s[i] == '1') {
      t[i+TOUR].dp[2][3] = 0;
      t[i+TOUR].dp[2][2] = 1;
    }
    if (s[i] == '7') {
      t[i+TOUR].dp[3][4] = 0;
      t[i+TOUR].dp[3][3] = 1;
    }
    if (s[i] == '6') {
      for (int j=3; j<5; j++)
        for (int k=3; k<5; k++)
          t[i+TOUR].dp[j][k] = INF;
      t[i+TOUR].dp[3][3] = 1;
      t[i+TOUR].dp[4][4] = 1;
    }
  }

  for (int i=TOUR-1; i; i--)
    t[i] = merge(t[2*i], t[2*i+1]);
}

node vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin) {
    node ret;
    REP(i, 5) ret.dp[i][i] = 0;
    return ret;
  }
  if (lo >= begin && hi <= end)
    return t[pos];
/*
  auto a = vrati(2*pos+0, lo, (lo+hi)/2, begin, end);
  auto b = vrati(2*pos+1, (lo+hi)/2, hi, begin, end);
  DB = 0;
  if (lo == 0 && hi == 8) {
    DB = 1;
    printf("BBBB %d\n", b.dp[4][4]);
  }
  merge(a, b);
  DB = 0;  
  return merge(a, b);*/

  return merge(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
               vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int main()
{
  int q;
  scanf("%d%d", &n, &q);
  scanf(" %s", s);

  init();

  for (; q--; ) {
    int l, r;
    scanf("%d%d", &l, &r); l--; r--;
    node tmp = vrati(1, 0, TOUR, l, r + 1);
    if (tmp.dp[0][4] >= INF / 2)
      printf("-1\n");
    else
      printf("%d\n", tmp.dp[0][4]);
  }

  return 0;
}
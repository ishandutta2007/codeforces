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

const int MAX = 1<<19, INF = 0x3f3f3f3f;

P manji[MAX], veci[MAX];
P mn_pref[MAX], mx_pref[MAX];
P mn_suf[MAX], mx_suf[MAX];
int n;

int main()
{
  scanf("%d", &n);

  REP(i, MAX) {
    mn_pref[i] = mn_suf[i] = P(INF, INF);
    mx_pref[i] = mx_suf[i] = P(-INF, -INF);
  }

  FOR(i, 1, n+1) {
    scanf("%d%d%d%d", &manji[i].X, &manji[i].Y, &veci[i].X, &veci[i].Y);
    mn_pref[i].X = min(mn_pref[i-1].X, veci[i].X);
    mn_pref[i].Y = min(mn_pref[i-1].Y, veci[i].Y);
    
    mx_pref[i].X = max(mx_pref[i-1].X, manji[i].X);
    mx_pref[i].Y = max(mx_pref[i-1].Y, manji[i].Y);
  }

  for (int i=n; i>0; i--) {
    mn_suf[i].X = min(mn_suf[i+1].X, veci[i].X);
    mn_suf[i].Y = min(mn_suf[i+1].Y, veci[i].Y);
    
    mx_suf[i].X = max(mx_suf[i+1].X, manji[i].X);
    mx_suf[i].Y = max(mx_suf[i+1].Y, manji[i].Y);
  }

  FOR(i, 1, n+1) {
    P mn, mx;
    mn.X = min(mn_pref[i-1].X, mn_suf[i+1].X);
    mn.Y = min(mn_pref[i-1].Y, mn_suf[i+1].Y);
    
    mx.X = max(mx_pref[i-1].X, mx_suf[i+1].X);
    mx.Y = max(mx_pref[i-1].Y, mx_suf[i+1].Y);

    if (mx.X <= mn.X && mx.Y <= mn.Y) {
      printf("%d %d\n", mx.X, mx.Y);
      return 0;
    }
  }

  return 0;
}
#include <set>
#include <map>
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

const int MAX = 300100;

int p[2][MAX];
ll pref[3][MAX];
int kamo[3][MAX];
int n;
map <P, int> dp;
int minpoz[2][MAX];
set <P> Poz;

void ubaci(int a, int b, int val)
{
  auto tmp = dp.find({a, b});
  if (tmp == dp.end()) {
    dp[{a, b}] = val;
    Poz.insert({a, b});
  }
  else
    dp[{a, b}] = max(dp[{a, b}], val);
}

int main()
{
  scanf("%d", &n);
  REP(i, 2) FOR(j, 1, n+1) scanf("%d", &p[i][j]);

  FOR(i, 1, n+1) {
    REP(j, 2)
      pref[j][i] = pref[j][i-1] + p[j][i];
    pref[2][i] = pref[0][i] + pref[1][i];
  }

  REP(i, 3) REP(j, MAX) kamo[i][j] = MAX - 3;
  REP(i, 3) {
    map <ll, int> M;  
    for (int j=n; j; j--) {
      M[pref[i][j]] = j;

      auto it = M.find(pref[i][j-1]);
      if (it != M.end()) kamo[i][j] = it->Y + 1;
      kamo[i][j] = min(kamo[i][j], kamo[i][j+1]);
    }
  }

  REP(i, 2) REP(j, MAX) minpoz[i][j] = MAX - 3;
  
  ubaci(1, 1, 0);

  for (; !Poz.empty(); ) {
    auto tmp = *Poz.begin(); Poz.erase(Poz.begin());
    if (tmp.X > n + 2 || tmp.Y > n + 2) continue;

    int mn = min(tmp.X, tmp.Y), st = tmp.X > tmp.Y, moj = dp[tmp], dpmn = dp[{mn, mn}];
    int mx = max(tmp.X, tmp.Y);

    if (moj >= dpmn + 2) continue;
    if (moj >= dpmn + 1 && mx > minpoz[st][mn]) continue;
    if (moj == dpmn + 1) minpoz[st][mn] = min(minpoz[st][mn], mx);
    
    if (tmp.X != tmp.Y) ubaci(mx, mx, moj);
    else {
      ubaci(kamo[2][tmp.X], kamo[2][tmp.X], moj + 1);
      ubaci(tmp.X+1, tmp.X+1, moj);
    }
    ubaci(kamo[0][tmp.X], tmp.Y, moj + 1);
    ubaci(tmp.X, kamo[1][tmp.Y], moj + 1);
  }
    
  printf("%d\n", dp[{n+1, n+1}]);

  return 0;
}
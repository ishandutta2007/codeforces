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

const int N = 5;
const ll INF = 1000000;

int n;
int tm[123][N];
int cnt[N];

ll eval(int vr, ll ljud, ll solved) {
  if (vr == -1) return 0;
  int val = 3000, om = 32;
  for (; solved*om > ljud; val -= 500, om /= 2);
  return val - (ll) vr * (val / 250);
}

int moze(ll x) {
  ll dosad = 0;
  REP(i, N) {
    ll tmp = -INF;
    tmp = max(tmp, eval(tm[0][i], n+x, cnt[i]) - eval(tm[1][i], n+x, cnt[i]));
    if (tm[0][i] != -1)
      tmp = max(tmp, eval(tm[0][i], n+x, cnt[i]+x) - eval(tm[1][i], n+x, cnt[i]+x));

    dosad += tmp;
  }

  return dosad > 0;
}

int main()
{
  scanf("%d", &n);

  REP(i, n) {
    REP(j, N) {
      scanf("%d", &tm[i][j]);
      if (tm[i][j] != -1) cnt[j]++;
    }
  }

  ll rje = -1;
  REP(i, INF)
    if (moze(i)) {
      rje = i;
      break;
    }
  
  printf("%lld\n", rje);

  return 0;
}
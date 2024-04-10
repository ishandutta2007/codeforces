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

const int MAX = 1<<20;
const ll INF = 1e12;

int dan[MAX], poc[MAX], kraj[MAX], cost[MAX];
ll pref[MAX], suf[MAX];
vector <P> Tamo[MAX], Nazad[MAX];

int nope() {
  printf("-1\n");
  exit(0);
}

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  REP(i, m) {
    scanf("%d%d%d%d", &dan[i], &poc[i], &kraj[i], &cost[i]);
    if (poc[i] == 0) Nazad[kraj[i]].push_back(P(dan[i], cost[i]));
    else Tamo[poc[i]].push_back(P(dan[i], cost[i]));
  }

  FOR(i, 1, n+1) {
    sort(Tamo[i].begin(), Tamo[i].end());
    sort(Nazad[i].begin(), Nazad[i].end(), greater<P>());
    if (Tamo[i].empty()) nope();
    if (Nazad[i].empty()) nope();

    ll minn = INF;
    pref[0] += minn;

    for (auto it : Tamo[i]) {
      if (it.Y < minn)
	pref[it.X+1] += it.Y - minn;
      minn = min(minn, (ll) it.Y);
    }

    minn = INF;
    suf[MAX-1] += minn;
    for (auto it : Nazad[i]) {
      if (it.Y < minn)
	suf[it.X-1] += it.Y - minn;
      minn = min(minn, (ll) it.Y);
    }
  }  

  FOR(i, 1, MAX) pref[i] += pref[i-1];
  for (int i=MAX-2; i>=0; i--) suf[i] += suf[i+1];

  ll rje = INF;
  FOR(p, 1, MAX) {
    int kr = p + k - 1;
    if (kr >= MAX) break;
    // if (pref[p] + suf[kr] < INF)
    //   TRACE(p _ pref[p] + suf[kr] _ p _ kr);
    rje = min(rje, pref[p] + suf[kr]);
  }
  
  if (rje >= INF) nope();
  cout << rje << endl;

  return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

const int MAX = 1<<13, TOUR = MAX;
const ll INF = 1e15;

Pll t[2*TOUR];
int n, k;
int p[2][MAX];
int pref[MAX];
int done[2][MAX];

void init() {
  REP(i, 2*TOUR) t[i] = {INF, INF};
  REP(i, n) t[i+TOUR] = {p[1][i], i};
  for (int i=TOUR-1; i; i--) t[i] = min(t[2*i], t[2*i+1]);
}

Pll vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return {INF, INF};
  if (lo >= begin && hi <= end) return t[pos];
  return min(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

void stavi(int pos, Pll val) {
  pos += TOUR;
  t[pos] = val;
  for (pos /= 2; pos; pos /= 2)
    t[pos] = min(t[2*pos], t[2*pos+1]);
}

P best() {
  ll ret = INF;
  P ind = {-1, -1};

  int poz = 0;
  int br0 = 0;
  
  REP(i, n) {
    if (!done[0][i]) {
      for (; poz < n && br0; poz++)
	br0 -= pref[poz] == 0;
      
      Pll tmp = vrati(1, 0, TOUR, poz, TOUR);
      ll val = tmp.X + p[0][i];
      
      if (val < ret) {
	ret = val;
	ind = {i, (int) tmp.Y};
      }
    }
    
    br0 += pref[i] == 0;    
  }
  
  return ind;
}

int main()
{
  scanf("%d%d", &n, &k);

  REP(i, 2) REP(j, n)
    scanf("%d", &p[i][j]);

  init();

  ll rje = 0;
  REP(i, k) {
    P tmp = best();
    rje += p[0][tmp.X] + p[1][tmp.Y];

    //    TRACE(tmp.X _ tmp.Y);
    
    done[0][tmp.X] = done[1][tmp.Y] = 1;
    FOR(j, tmp.X, n) pref[j]++;    
    FOR(j, tmp.Y, n) pref[j]--;
    stavi(tmp.Y, {INF, INF});

    //    REP(j, n) TRACE(j _ pref[j]);
    REP(j, n) assert(pref[j] >= 0);
  }

  printf("%lld\n", rje);

  return 0;
}
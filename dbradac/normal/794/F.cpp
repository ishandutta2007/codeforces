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

const int TOUR = 1<<17;

struct tour {
  int prop[10];
  ll sum[10];  
} t[2*TOUR];

ll p[TOUR];
int n, brq;

void upd(int pos) {
  REP(i, 10)
    t[pos].sum[i] = t[2*pos].sum[i] + t[2*pos+1].sum[i];
  REP(i, 10) t[pos].prop[i] = i;
}

void propagiraj(int pos) {
  FOR(i, 2*pos, 2*pos+2) {
    ll nsum[10]; memset(nsum, 0, sizeof nsum);

    REP(j, 10) {
      nsum[t[pos].prop[j]] += t[i].sum[j];
      t[i].prop[j] = t[pos].prop[t[i].prop[j]];
    }
    REP(j, 10) t[i].sum[j] = nsum[j];
  }

  REP(j, 10) t[pos].prop[j] = j;
}

void init() {
  REP(i, n) {
    ll pot = 1, tmp = p[i];
    for (; tmp; tmp /= 10, pot *= 10)
      t[i+TOUR].sum[tmp%10] += pot;
  }
  REP(i, 2*TOUR)
    REP(j, 10) t[i].prop[j] = j;

  for (int j=TOUR-1; j; j--)
    upd(j);
}

void stavi(int pos, int lo, int hi, int begin, int end, int z1, int z2) {
  if (z1 == z2) return;

  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    t[pos].sum[z2] += t[pos].sum[z1];
    t[pos].sum[z1] = 0;

    REP(j, 10)
      if (t[pos].prop[j] == z1)
	t[pos].prop[j] = z2;
    
    return;
  }

  propagiraj(pos);
  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, z1, z2);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, z1, z2);
  upd(pos);
}

ll vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return 0;
  if (lo >= begin && hi <= end) {
    ll ret = 0;
    REP(i, 10)
      ret += i * t[pos].sum[i];
    return ret;
  }

  propagiraj(pos);
  return vrati(2*pos+0, lo, (lo+hi)/2, begin, end) +
    vrati(2*pos+1, (lo+hi)/2, hi, begin, end);
}

int main()
{
  scanf("%d%d", &n, &brq);

  REP(i, n) scanf("%lld", &p[i]);

  init();

  REP(i, brq) {
    int st, l, r;
    scanf("%d%d%d", &st, &l, &r); l--; r--;

    if (st == 1) {
      int z1, z2;
      scanf("%d%d", &z1, &z2);
      stavi(1, 0, TOUR, l, r+1, z1, z2);
    }
    else
      printf("%lld\n", vrati(1, 0, TOUR, l, r+1));
  }

  return 0;
}
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

const int TOUR = 1<<19, MAX = TOUR;

struct node {
  ll hl, hr;
  ll prop;
  int maxx;
  int padl, padr;
  int rastl, rastr;
  int __rastl, __padr; //nakon pregiba
} t[2*TOUR];

node merge(const node &l, const node &r, int polsz)
{
  node ret;
  ret.hl = l.hl;
  ret.hr = r.hr;
  ret.prop = 0;
  ret.padl = (l.padl == polsz && l.hr > r.hl) ? polsz + r.padl : l.padl;
  ret.padr = (r.padr == polsz && l.hr > r.hl) ? polsz + l.padr : r.padr;
  ret.rastl = (l.rastl == polsz && l.hr < r.hl) ? polsz + r.rastl : l.rastl;
  ret.rastr = (r.rastr == polsz && l.hr < r.hl) ? polsz + l.rastr : r.rastr;
  
  ret.__rastl = (l.rastl == polsz && l.hr < r.hl) ? polsz + r.__rastl : l.__rastl;
  if (l.__padr == polsz && l.hr > r.hl) ret.__rastl = max(ret.__rastl, polsz + r.padl);
  if (l.rastl == polsz && l.hr != r.hl) ret.__rastl = max(ret.__rastl, polsz + r.padl);

  ret.__padr = (r.padr == polsz && r.hl < l.hr) ? polsz + l.__padr : r.__padr;
  if (r.__rastl == polsz && r.hl > l.hr) ret.__padr = max(ret.__padr, polsz + l.rastr);
  if (r.padr == polsz && l.hr != r.hl) ret.__padr = max(ret.__padr, polsz + l.rastr);

  ret.maxx = max(l.maxx, r.maxx);
  ret.maxx = max(ret.maxx, ret.__rastl);
  ret.maxx = max(ret.maxx, ret.__padr);
  ret.maxx = max(ret.maxx, ret.rastl);
  ret.maxx = max(ret.maxx, ret.rastr);
  ret.maxx = max(ret.maxx, ret.padl);
  ret.maxx = max(ret.maxx, ret.padr);

  if (l.hr != r.hl) ret.maxx = max(ret.maxx, l.rastr + r.padl);
  if (l.hr < r.hl) ret.maxx = max(ret.maxx, l.rastr + r.__rastl);
  if (l.hr > r.hl) ret.maxx = max(ret.maxx, l.__padr + r.padl);

  return ret;
}

int sajz[2*TOUR];
int p[MAX];
int n;

void upd(int pos, int polsz)
{
  t[pos] = merge(t[2*pos], t[2*pos+1], polsz);
}

void prop(int pos)
{
  FOR(i, 2*pos, 2*pos+2) {
    t[i].prop += t[pos].prop;
    t[i].hl += t[pos].prop;
    t[i].hr += t[pos].prop;
  }
  t[pos].prop = 0;
}

void init()
{
  REP(i, n) {
    t[TOUR+i] = {p[i], p[i], 0, 1, 1, 1, 1, 1, 1, 1};
    sajz[TOUR+i] = 1;
  }

 // printf("HL HR RASTL RASTR PADL PADR __RASTL __PADR MAXX\n");
  for (int i=TOUR-1; i; i--) {
    sajz[i] = sajz[2*i] * 2;
    upd(i, sajz[2*i]);

//    printf("III %d    %lld %lld    %d %d   %d %d   %d %d   %d\n", i, t[i].hl, t[i].hr, t[i].rastl, t[i].rastr, t[i].padl, t[i].padr, t[i].__rastl, t[i].__padr, t[i].maxx);
  }
}

void stavi(int pos, int lo, int hi, int begin, int end, int val)
{
  if (lo >= end || hi <= begin)
    return;
  if (lo >= begin && hi <= end) {
    t[pos].prop += val;
    t[pos].hl += val;
    t[pos].hr += val;
    return;
  }

  prop(pos);
  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  upd(pos, (hi - lo) / 2);
}

int main()
{
  scanf("%d", &n);
  REP(i, n)
    scanf("%d", &p[i]);

  init();

  int q;
  scanf("%d", &q);

  for (; q--; ) {
    int l, r, val;
    scanf("%d%d%d", &l, &r, &val); l--; r--;
    stavi(1, 0, TOUR, l, r + 1, val);
    printf("%d\n", t[1].maxx);
  }

  return 0;
}
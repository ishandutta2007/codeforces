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

int eval(int x, const vector<int> &V) {
  for (auto it : V) {
    if (it > x) x++;
    else if (it < x) x--;
  }

  return x;
}

const int MAXVAL = 1<<19;
const int TOUR = 2*MAXVAL;

struct tour {
  int proppref, propsuf, mnpref, mnsuf;
} t[2*TOUR];

void upd(int pos) {
  assert(pos < TOUR);
  t[pos].mnpref = min(t[2*pos].mnpref, t[2*pos+1].mnpref);
  t[pos].mnsuf = min(t[2*pos].mnsuf, t[2*pos+1].mnsuf);
}

void propagiraj(int pos) {
  assert(pos < TOUR);
  FOR(i, 2*pos, 2*pos+2) {
    t[i].proppref += t[pos].proppref;
    t[i].mnpref += t[pos].proppref;

    t[i].propsuf += t[pos].propsuf;
    t[i].mnsuf += t[pos].propsuf;
  }
  t[pos].proppref = t[pos].propsuf = 0;
}

void stavi(int pos, int lo, int hi, int begin, int end, int val, int st) { //0 - pref, 1 - suf
  //  if (pos == 1) TRACE(st _ begin _ end _ val);
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    if (!st) {
      t[pos].proppref += val;
      t[pos].mnpref += val;
    }
    else {
      t[pos].propsuf += val;
      t[pos].mnsuf += val;
    }
    return;
  }

  propagiraj(pos);
  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val, st);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val, st);
  upd(pos);
}

void init() {
  REP(i, TOUR)
    t[i+TOUR] = {0, 0, i-MAXVAL, i-MAXVAL};
  for (int i=TOUR-1; i; i--)
    upd(i);
}

int zadnji_manji_jednak(int pos, int lo, int hi, int begin, int end, int val) { //mnpref
  //  TRACE(pos _ lo _ hi _ begin _ end _ val _ t[pos].mnpref);

  if (lo >= end || hi <= begin || t[pos].mnpref > val) return TOUR;
  if (lo + 1 == hi) return lo;
  propagiraj(pos);
  int tmp = zadnji_manji_jednak(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  if (tmp != TOUR) return tmp;
  return zadnji_manji_jednak(2*pos, lo, (lo+hi)/2, begin, end, val);  
}

int vrati_min(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return TOUR;
  if (lo >= begin && hi <= end) return t[pos].mnsuf;
  propagiraj(pos);
  return min(vrati_min(2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati_min(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int main()
{
  init();

  int n;  
  scanf("%d", &n);

  REP(i, n) {
    int x;
    scanf("%d", &x);
    stavi(1, 0, TOUR, x+MAXVAL, TOUR, 1, 0);
    stavi(1, 0, TOUR, 0, x+MAXVAL, 1, 1);
    
    int kad = zadnji_manji_jednak(1, 0, TOUR, 0, TOUR, 0);
    //    kad++;

    //    TRACE(kad-MAXVAL);
    int rje = vrati_min(1, 0, TOUR, kad, TOUR);
    printf("%d\n", rje);                
  }

  return 0;
}
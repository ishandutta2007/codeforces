#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <set>
#include <queue>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define X first
#define Y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1<<18, LG = 19, TOUR = 1<<18;

int per[MAX], niz[MAX];
int velper, velniz;
int lst[MAX];
int qq;
int skok[MAX][LG];
int indper[MAX];
int kamo[MAX];
int t[2*TOUR];

int vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return velniz;
  if (lo >= begin && hi <= end) return t[pos];
  return min(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int main() {
  scanf("%d%d%d", &velper, &velniz, &qq);

  REP(i, velper) {
    scanf("%d", &per[i]);
    indper[per[i]] = i;
  }
  
  REP(i, velniz) scanf("%d", &niz[i]);

  if (velper == 1) {
    REP(i, qq) printf("1");
    printf("\n");
    return 0;
  }

  REP(i, MAX) lst[i] = velniz;  
  REP(i, LG) skok[velniz][i] = velniz;
  
  for (int i=velniz-1; i>=0; i--) {
    int ind = indper[niz[i]];
    ind = (ind + 1) % velper;
    skok[i][0] = lst[per[ind]];
    lst[niz[i]] = i;

    FOR(j, 1, LG)
      skok[i][j] = skok[skok[i][j-1]][j-1];

    int kolko = velper - 1;
    int tmp = i;
    
    REP(j, LG)
      if (kolko>>j & 1)
	tmp = skok[tmp][j];

    kamo[i] = tmp;
  }

  REP(i, 2*TOUR) t[i] = velniz;
  REP(i, velniz)
    t[i+TOUR] = kamo[i];

  for (int i=TOUR-1; i; i--)
    t[i] = min(t[2*i], t[2*i+1]);

  REP(i, qq) {
    int l, r;
    scanf("%d%d", &l, &r); l--; r--;
    int tmp = vrati(1, 0, TOUR, l, TOUR);
    if (tmp <= r) printf("1");
    else printf("0");
  }

  printf("\n");      

  return 0;
}
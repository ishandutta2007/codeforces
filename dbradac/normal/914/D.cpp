#include <cstdio>
#include <cmath>
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

const int TOUR = 1<<19;

int t[2*TOUR];
int p[TOUR];
int n;

void init() {
  REP(i, n) t[i+TOUR] = p[i];
  for (int i=TOUR-1; i; i--)
    t[i] = __gcd(t[2*i], t[2*i+1]);
}

int vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return 0;
  if (lo >= begin && hi <= end) return t[pos];
  return __gcd(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
               vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

void stavi(int pos, int val) {
  pos += TOUR;
  t[pos] = val;
  for (pos/=2; pos; pos/=2)
    t[pos] = __gcd(t[2*pos], t[2*pos+1]);
}

int dokle(int pos, int lo, int hi, int begin, int end, int val) {
  if (lo >= end || hi <= begin) return TOUR;
  if (t[pos] % val == 0) return TOUR;
  if (lo + 1 == hi) return lo;

  int tmp = dokle(2*pos, lo, (lo+hi)/2, begin, end, val);
  if (tmp == TOUR) return dokle(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  return tmp;
}

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &p[i]);
  init();

  int q;
  scanf("%d", &q);
  REP(i, q) {
    int st;
    scanf("%d", &st);
    if (st == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      l--; r--;

      if (vrati(1, 0, TOUR, l, r+1) % x == 0)
        printf("YES\n");
      else {
        int tmp = dokle(1, 0, TOUR, l, r+1, x);

        tmp = dokle(1, 0, TOUR, tmp+1, r+1, x);
        if (tmp > r)
          printf("YES\n");
        else
          printf("NO\n");
      }
    }
    else {
      int pos, x;
      scanf("%d%d", &pos, &x); pos--;
      stavi(pos, x);
    }
  }

  return 0;
}
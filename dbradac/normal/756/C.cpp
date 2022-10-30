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

const int TOUR = 1<<17;

struct node {
  int prop, mx;
} t[2*TOUR];

node merge(node l, node r)
{
  return {0, max(l.mx, r.mx)};
}

void propagiraj(int pos)
{
  FOR(i, 2*pos, 2*pos+2) {
    t[i].prop += t[pos].prop;
    t[i].mx += t[pos].prop;
  }
  t[pos].prop = 0;
}

void stavi(int pos, int lo, int hi, int begin, int end, int val)
{
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    t[pos].prop += val;
    t[pos].mx += val;
    return;
  }

  propagiraj(pos);
  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  t[pos] = merge(t[2*pos], t[2*pos+1]);
}

int binr(int pos, int lo, int hi)
{
  if (t[pos].mx < 1) return -TOUR;
  if (lo + 1 == hi) {
    assert(t[pos].mx == 1);
    return lo;
  }

  propagiraj(pos);
  if (t[2*pos+1].mx >= 1)
    return binr(2*pos+1, (lo+hi)/2, hi);
  return binr(2*pos+0, lo, (lo+hi)/2);
}

int p[TOUR];

int main()
{
  int n;
  scanf("%d", &n);

  REP(i, n) {
    int poz, st;
    scanf("%d%d", &poz, &st);
    if (st == 1) {
      int x;
      scanf("%d", &x);
      p[poz] = x;
      stavi(1, 0, TOUR, 0, poz+1, 1);
    }
    else
      stavi(1, 0, TOUR, 0, poz+1, -1);

    int tmp = binr(1, 0, TOUR);
    if (tmp < 0) printf("-1\n");
    else printf("%d\n", p[tmp]);
  }

  return 0;
}
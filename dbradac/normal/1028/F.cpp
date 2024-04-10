#include <cstdio>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;
typedef long double llf;

const llf EPS = 1e-13;
const llf VERT = 1e10;
const ll INF = 1e18 + 1e17;

struct str {
  llf d;
  ll val;
};

bool operator < (const str &a, const str &b) {
  if (abs(a.d - b.d) < EPS) return false;
  return a.d < b.d;
}

int n;
map <ll, set<P> > M;
unordered_map <ll, int> Sol;

ll rad(P p) {
  return (ll) p.X * p.X + (ll) p.Y * p.Y;
}

void upd(llf koef, int dod) {
  ll ind;
  if (koef == VERT) ind = INF;
  else ind = (ll) (koef / EPS);

  Sol[ind] += dod;
}

void add(P p, int st) { //st jel vec unutra
  ll rd = rad(p);

  if (rd) {
    if (p.X) {
      upd((llf) p.Y / p.X, st == 1 ? -1 : 1);
    }
    else
      upd(VERT, st == 1 ? -1 : 1);
  }

  auto it = M[rd].find(p);
  if (st) assert(it != M[rd].end());
  else assert(it == M[rd].end());

  for (auto __toc = M[rd].begin(); __toc != M[rd].end(); __toc++) {
    auto toc = *__toc;
    if (toc == p) continue;

    if (toc.Y == p.Y) {
      if (toc.X == -p.X)
        upd(VERT, st == 1 ? -2 : 2);
    }
    else {
      llf koef = (p.X - toc.X) / ((llf) toc.Y - p.Y);
      upd(koef, st == 1 ? -2 : 2);
    }
  }

  if (st) M[rd].erase(p);
  else M[rd].insert(p);

  n += (st ? -1 : 1);
}

ll ans(llf koef) {
  if (koef == VERT) return n - M[0].size() - Sol[INF];
  ll ret = n;

  if (!M[0].empty()) ret--;
  ll ind = (ll) (koef / EPS);
  for (ll i=ind-1; i<=ind+1; i++)
    ret -= Sol[i];

  return ret;
}

int main()
{
  int q;
  scanf("%d", &q);

  REP(i, q) {
    int st, x, y;
    scanf("%d%d%d", &st, &x, &y);

    if (st == 1)
      add(P(x, y), 0);
    else if (st == 2)
      add(P(x, y), 1);
    else {
      ll rje = 0;
      if (!x) rje = ans(VERT);
      else rje = ans((llf) y / x);

      printf("%lld\n", rje);
    }
  }

  return 0;
}
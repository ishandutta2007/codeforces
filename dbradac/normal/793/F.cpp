#include <set>
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

const int MAX = 1<<17, TOUR = 1<<17, LG = 18;

set <P> t[2*TOUR];

int presjek(P a, P b) {
  return max(a.X, b.X) <= min(a.Y, b.Y);
}

void ubaci(set <P> &S, P val) {  
  auto it = S.lower_bound({val.X, -1}); //trazimo manjeg
  for (; it != S.begin() && (it == S.end() || it->X > val.X); it--);
  
  for (; it != S.end();) {
    if (presjek(*it, val)) {
      val.X = min(val.X, it->X);
      val.Y = max(val.Y, it->Y);
      auto it2 = it++;
      S.erase(it2);
    }
    else if (it->X < val.X) it++;
    else break;
  }

  S.insert(val);
}

void insert(int pos, P val) {
  pos += TOUR;
  for (; pos; pos /= 2)
    ubaci(t[pos], val);
}

int eval(set <P> &S, int val) {
  auto it = S.lower_bound(P(val, val));
  for (; it != S.begin() && (it == S.end() || it->X > val); it--);
  if (it != S.end() && it->X <= val)
    return max(val, it->Y);
  return val;
}

void q(int pos, int lo, int hi, int begin, int &val) {
  if (hi <= begin) return;
  if (lo >= begin) {
    val = eval(t[pos], val);
    return;
  }
  q(2*pos+0, lo, (lo+hi)/2, begin, val);
  q(2*pos+1, (lo+hi)/2, hi, begin, val);
}

P p[MAX];
pair <P, int> kver[MAX];
int rje[MAX];

int main()
{
  int n;

  scanf("%*d%d", &n);
  
  REP(i, n) {
    scanf("%d%d", &p[i].X, &p[i].Y);
  }
  
  sort(p, p + n, [] (P a, P b) { return a.Y < b.Y; });

  int brq;
  scanf("%d", &brq);

  REP(i, brq) {
    scanf("%d%d", &kver[i].X.X, &kver[i].X.Y);
    kver[i].Y = i;
  }

  sort(kver, kver + brq, [] (pair<P, int> a, pair<P, int> b) { return a.X.Y < b.X.Y; });

  int indp = 0;
  REP(i, brq) {
    for (; indp < n && p[indp].Y <= kver[i].X.Y; indp++)
      insert(p[indp].X, p[indp]);

    rje[kver[i].Y] = kver[i].X.X;
    q(1, 0, TOUR, kver[i].X.X, rje[kver[i].Y]);
  }

  REP(i, brq)
    printf("%d\n", rje[i]);

  return 0;
}
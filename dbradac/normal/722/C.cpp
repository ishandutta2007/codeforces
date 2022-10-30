#include <cstdio>
#include <set>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int TOUR = 1<<17;
const ll INF = 5e13;

struct tour {
  ll sum;
  ll l, r;
  ll mx;
} t[2*TOUR];

tour Merge(tour a, tour b)
{
  tour ret = tour{a.sum+b.sum, 0, 0, 0};
  ret.l = max(a.l, a.sum + b.l);
  ret.r = max(b.r, b.sum + a.r);
  ret.mx = max(ret.sum, a.r + b.l);
  ret.mx = max(ret.mx, max(a.mx, b.mx));
  ret.mx = max(ret.mx, max(ret.l, ret.r));

  return ret;
}

int p[TOUR];
int n;

void Init()
{
  for (int i=0; i<n; i++)
    t[i+TOUR] = tour{p[i], p[i], p[i], p[i]};
  for (int i=TOUR-1; i; i--)
    t[i] = Merge(t[2*i], t[2*i+1]);
}

void Stavi(int pos)
{
  pos += TOUR;
  t[pos] = tour{-INF, -INF, -INF, -INF};
  pos /= 2;
  for (; pos; pos /= 2)
    t[pos] = Merge(t[2*pos], t[2*pos+1]);
}

int main()
{
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  Init();

  for (int i=0; i<n; i++) {
    int x;
    scanf("%d", &x); x--;
    Stavi(x);
    printf("%lld\n", t[1].mx);
  }

  return 0;
}
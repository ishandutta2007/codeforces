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

const int MAX = 1<<17, TOUR = 1<<17;
const ll INF = 1e18;

int vrijeme[MAX];
int vr[3] = {1, 90, 1440};
int cs[3] = {20, 50, 120};
ll t[2*TOUR];
ll rje[2*TOUR];

void stavi(int pos, int lo, int hi, int begin, int end, ll val)
{
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    t[pos] = min(t[pos], val);
    return;
  }

  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
}

ll vrati(int pos)
{
  pos += TOUR;
  ll ret = INF;

  for (; pos; pos /= 2)
    ret = min(ret, t[pos]);
  return ret;
}

int main()
{
  int n;
  scanf("%d", &n);

  REP(i, 2*TOUR) t[i] = INF;
  stavi(1, 0, TOUR, 0, 1, 0);

  REP(i, n)
    scanf("%d", &vrijeme[i]);

  REP(i, n+1) {
    rje[i] = vrati(i);
    if (i)
      printf("%lld\n", rje[i] - rje[i-1]);

    if (i == n) break;

    REP(j, 3) {
      int nt = vrijeme[i] + vr[j];
      int poz = lower_bound(vrijeme, vrijeme + n, nt) - vrijeme;
      stavi(1, 0, TOUR, 0, poz + 1, rje[i] + cs[j]);
    }
  }

  return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int TOUR = 1<<17;

struct daska {
  int vis, ind;
  daska (int vis, int ind) : vis(vis), ind(ind) {}
  daska () {}
} ev[TOUR];

bool operator < (daska a, daska b)
{
  return a.vis > b.vis;
}

struct tour {
  int maxx, left, right;
  tour (int maxx, int left, int right) : maxx(maxx), left(left), right(right) {}
  tour () {}
} t[2*TOUR];

tour Merge(tour l, tour r, int polsz)
{
  tour ret;

  ret.maxx = max(l.maxx, max(r.maxx, l.right + r.left));
  if (l.left == polsz) ret.left = polsz + r.left;
  else ret.left = l.left;
  if (r.right == polsz) ret.right = polsz + l.right;
  else ret.right = r.right;

  return ret;
}

void Stavi(int pos)
{
  int polsz;

  t[pos+TOUR] = tour(1, 1, 1);
  for (polsz=1, pos=(pos+TOUR)/2; pos; pos /= 2, polsz *= 2)
    t[pos] = Merge(t[2*pos], t[2*pos+1], polsz);
}

tour Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return tour(0, 0, 0);
  if (lo >= begin && hi <= end)
    return t[pos];

  return Merge(Vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
      Vrati(2*pos+1, (lo+hi)/2, hi, begin, end),
      (hi-lo)/2);
}

int p[TOUR], pp[TOUR], ql[TOUR], qr[TOUR], qw[TOUR], rje[TOUR];
int lgran[2*TOUR], rgran[2*TOUR];
vector <int> Q[2*TOUR];

int main()
{
  int n, brq;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    pp[i] = p[i];
  }

  sort(pp, pp+n);

  for (int i=0; i<n; i++) {
    p[i] = upper_bound(pp, pp+n, p[i]) - pp;
    ev[i] = daska(p[i], i);
  }

  sort(ev, ev+n);

  scanf("%d", &brq);

  for (int i=0; i<brq; i++) {
    scanf("%d%d%d", &ql[i], &qr[i], &qw[i]);
    Q[1].push_back(i);
  }

  lgran[1] = 0;
  rgran[1] = TOUR;

  for (int i=1, ind=0; i<TOUR; i++) {
    for (; ind<n && ev[ind].vis >= (rgran[i]+lgran[i]) / 2; ind++)
      Stavi(ev[ind].ind);
    for (int j=0; j<(int)Q[i].size(); j++) {
      if (Vrati(1, 0, TOUR, ql[Q[i][j]]-1, qr[Q[i][j]]).maxx < qw[Q[i][j]])
        Q[2*i+1].push_back(Q[i][j]);
      else
        Q[2*i+0].push_back(Q[i][j]);
    }
    lgran[2*i+1] = lgran[i]; rgran[2*i+1] = (rgran[i]+lgran[i]) / 2;
    lgran[2*i+0] = (rgran[i]+lgran[i]) / 2; rgran[2*i+0] = rgran[i];
    if (!lgran[i]) {
      memset(t, 0, sizeof t);
      ind = 0;
    }
  }

  for (int i=TOUR; i<2*TOUR; i++)
    for (int j=0; j<(int)Q[i].size(); j++)
      rje[Q[i][j]] = pp[lgran[i]-1];

  for (int i=0; i<brq; i++)
    printf("%d\n", rje[i]);

  return 0;
}
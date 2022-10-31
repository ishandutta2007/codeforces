#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int TOUR = 1<<17, MAXN = 100005, MAXQ = 5005;

struct str {
  int l, r;
  double prob;
  str (int l, int r, double prob) : l(l), r(r), prob(prob) {}
  str () {}
} q[MAXQ];

bool operator < (const str &a, const str &b)
{
  if (a.l != b.l)
    return a.l < b.l;
  return a.r > b.r;
}

int p[MAXN];
int t[2*TOUR];
int brq;
double dp[MAXQ][MAXQ], pref[MAXQ][MAXQ];

void Stavi(int pos, int val)
{
  for (t[pos+TOUR] = val, pos = (pos + TOUR) / 2; pos; pos /= 2)
    t[pos] = max(t[2*pos], t[2*pos+1]);
}

int Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return 0;
  if (lo >= begin && hi <= end)
    return t[pos];
  return max(Vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
             Vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int Rek(int from, int to, int ind)
{
  int ret=ind+1;
  vector <int> V;

  for (int i=ind+1; i<brq && q[i].r <= to; i++) {
    V.push_back(i);
    ret = i = Rek(q[i].l, q[i].r, i); i--;
  }
  
  double *tmpdp[2], *tmppref[2];
  
  for (int i=0; i<2; i++) {
    tmpdp[i] = new double[MAXQ];
    tmppref[i] = new double[MAXQ];
    for (int j=0; j<MAXQ; j++)
      tmpdp[i][j] = tmppref[i][j] = 0.0;
  }

  tmpdp[0][0] = 1.0;
  for (int i=0; i<MAXQ; i++)
    tmppref[0][i] = 1.0;


  int tmax = Vrati(1, 0, TOUR, from, to+1), tind = 0;
  
  for (int i=0; i<(int) V.size(); i++, tind ^= 1) {
    int imax = Vrati(1, 0, TOUR, q[V[i]].l, q[V[i]].r+1);

    for (int j=0; j<MAXQ; j++)
      tmpdp[1-tind][0] = 0.0;

    for (int j=0; j<MAXQ; j++) {
      int pos = tmax - imax + j;
      double p1=1.0, p2=0.0;

      if (pos < MAXQ) {
        if (pos > 0)
          p1 = pref[V[i]][pos-1];
        else
          p1 = 0.0;
        p2 = dp[V[i]][pos];
      }

      tmpdp[1-tind][j] = p1 * tmpdp[tind][j];
      tmpdp[1-tind][j] += tmppref[tind][j] * p2;
    }

    tmppref[1-tind][0] = tmpdp[1-tind][0];
    for (int j=1; j<MAXQ; j++)
      tmppref[1-tind][j] = tmppref[1-tind][j-1] + tmpdp[1-tind][j];
  }
  
  for (int j=0; j<MAXQ; j++) {
    dp[ind][j] = tmpdp[tind][j] * (1 - q[ind].prob);
    if (j)
      dp[ind][j] += tmpdp[tind][j-1] * q[ind].prob;

    pref[ind][j] = dp[ind][j];
    if (j)
      pref[ind][j] += pref[ind][j-1];
  }

  for (int i=0; i<2; i++) {
    delete[] tmpdp[i];
    delete[] tmppref[i];
  }

  return ret;
}

int main()
{
  int n, maxx = 0;

  scanf("%d%d", &n, &brq);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    maxx = max(maxx, p[i]);
  }

  for (int i=0; i<n; i++) {
    p[i] -= maxx - MAXQ;
    Stavi(i, p[i]);
  }

  for (int i=0; i<brq; i++) {
    scanf("%d%d%lf", &q[i].l, &q[i].r, &q[i].prob);
    q[i].l--; q[i].r--;
  }
  q[brq++] = str(0, n-1, 0.0);
  
  sort(q, q+brq);

  Rek(0, n-1, 0);
  
  double rje=0.0, sum=0.0;
  for (int i=0; i<MAXQ; i++) {
    rje += (i + maxx) * dp[0][i];
    sum += dp[0][i];
  }

  printf("%lf\n", rje);

  return 0;
}
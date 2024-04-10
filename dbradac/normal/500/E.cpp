#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 200005, TOUR = 1<<18, LOG = 19;
const int INF = 2000000500;

struct str {
  int poz, udalj, val;
  str (int poz, int udalj, int val) : poz(poz), udalj(udalj), val(val) {}
  str () {}
} lca[MAX][LOG];

bool operator < (str a, str b)
{
  if (a.poz != b.poz)
    return a.poz < b.poz;
  return a.udalj < b.udalj;
}

int poz[MAX], h[MAX];
int l[MAX], r[MAX];
str t[2*TOUR];

void Stavi(int pos, str nov)
{
  for (t[pos+TOUR]=nov, pos = (pos + TOUR) / 2; pos; pos /= 2)
    t[pos] = max(t[2*pos], t[2*pos+1]);
}

str Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return str(-1, -1, -1);
  if (lo >= begin && hi <= end)
    return t[pos];
  return max(Vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
             Vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

int Query(int l, int r)
{
  int rez=0;

  for (int i=LOG-1; i>=0; i--) {
    if (lca[l][i].poz < r) {
      rez += lca[l][i].val + poz[lca[l][i].poz+1] - lca[l][i].udalj;
      l = lca[l][i].poz + 1;
    }
  }

  return rez;
}

int main()
{
  int n, q;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d%d", &poz[i], &h[i]);
 
  poz[n] = INF;

  for (int i=n-1; i>=0; i--) {
    int dokle = upper_bound(poz, poz+n, poz[i] + h[i]) - poz - 1;
    lca[i][0] = max(str(dokle, poz[i] + h[i], 0), Vrati(1, 0, TOUR, i+1, dokle+1));
    Stavi(i, lca[i][0]);
  }

  for (int j=1; j<LOG; j++) {
    for (int i=0; i<n; i++) {
      if (lca[i][j-1].poz == n-1)
        lca[i][j] = lca[i][j-1];
      else
        lca[i][j] = str(lca[lca[i][j-1].poz+1][j-1].poz, lca[lca[i][j-1].poz+1][j-1].udalj, lca[i][j-1].val + lca[lca[i][j-1].poz+1][j-1].val + poz[lca[i][j-1].poz+1] - lca[i][j-1].udalj);
    }
  }

  scanf("%d", &q);

  for (int i=0; i<q; i++) {
    int l, r;
    scanf("%d%d", &l, &r); l--; r--;
    printf("%d\n", Query(l, r));
  }

  return 0;
}
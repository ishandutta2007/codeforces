#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int TOUR = 1<<17, MOD = 1e9 + 7, H = 3137;

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int n, m, k;
int prop[2*TOUR], hes[2*TOUR];
int pot[TOUR], sumg[TOUR];

void Propagiraj(int x, int polsz)
{
  if (prop[x] == -1)
    return;

  prop[2*x] = prop[2*x+1] = prop[x];
  hes[2*x] = hes[2*x+1] = Mul(sumg[polsz-1], prop[x]);

  prop[x] = -1;
}

void Stavi(int pos, int lo, int hi, int begin, int end, int val)
{
  if (lo >= end || hi <= begin)
    return;
  if (lo >= begin && hi <= end) {
    prop[pos] = val;
    hes[pos] = Mul(sumg[hi-lo-1], val);
    return;
  }

  Propagiraj(pos, (hi-lo) / 2);
  Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);

  hes[pos] = Add(Mul(hes[2*pos+0], pot[(hi-lo)/2]), hes[2*pos+1]);
}

int Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return 0;
  if (lo >= begin && hi <= end)
    return hes[pos];
 
  Propagiraj(pos, (hi-lo)/2);

  int l = Vrati(2*pos+0, lo, (lo+hi)/2, begin, end);
  int r = Vrati(2*pos+1, (lo+hi)/2, hi, begin, end);

  if (end >= (lo + hi) / 2)
    return Add(Mul(l, pot[min(hi, end) - (lo+hi)/2]), r);
  return l;
}

void GenPot()
{
  pot[0] = sumg[0] = 1;

  for (int i=1; i<TOUR; i++) {
    pot[i] = Mul(pot[i-1], H);
    sumg[i] = Add(sumg[i-1], pot[i]);
  }
}

char s[TOUR];

int main()
{
  memset(prop, -1, sizeof prop);

  scanf("%d%d%d%s", &n, &m, &k, s);

  GenPot();

  for (int i=0; i<n; i++)
    Stavi(1, 0, TOUR, i, i + 1, s[i] - '0' + 1);

  for (int i=0; i<m+k; i++) {
    int st, l, r, val;
    scanf("%d%d%d%d", &st, &l, &r, &val); l--;

    if (st == 1)
      Stavi(1, 0, TOUR, l, r, val + 1);
    else
      printf("%s\n", Vrati(1, 0, TOUR, l, r - val) == Vrati(1, 0, TOUR, l + val, r) ? "YES" : "NO");
  }

  return 0;
}
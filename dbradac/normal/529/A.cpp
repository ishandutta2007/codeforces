#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int TOUR = 1<<21, MOD = 1000000007, H = 3137;

struct tour {
  int brot, brzat, dodot;
  tour (int brot, int brzat, int dodot) : brot(brot), brzat(brzat), dodot(dodot) {}
  tour () {}
  int vel () {
    return 2 * (brot + dodot);
  }
} t[2*TOUR];

tour Merge(const tour &l, const tour &r)
{
  int dodr = max(0, r.dodot - (l.brot + l.dodot - l.brzat));
  return tour(l.brot + r.brot, l.brzat + r.brzat, l.dodot + dodr);
}

char s[TOUR];
int len;
int hes[TOUR];
int pot[TOUR];

int Mul(int a, int b)
{
  return ((ll) a * b) % MOD;
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Sub(int a, int b)
{
  return (a - b + MOD) % MOD;
}

void GenHes()
{
  pot[0] = 1;
  for (int i=1; i<TOUR; i++)
    pot[i] = Mul(pot[i-1], H);

  for (int i=1; i<=2*len; i++)
    hes[i] = Add(Mul(hes[i-1], H), s[(i-1) % len] - '(' + 1); 
}

int Manji(int a, int b)
{
  a++; b++;
  int lo=0, hi=len;
  
  for (; lo<hi; ) {
    int mid = (lo + hi + 1) / 2;
    if (Sub(hes[a+mid-1], Mul(hes[a-1], pot[mid])) ==
        Sub(hes[b+mid-1], Mul(hes[b-1], pot[mid])))
          lo = mid;
    else
      hi = mid - 1;
  }

  return s[(a+lo-1) % len] < s[(b+lo-1) % len];
}

void Ispis(int poc, int dodot, int dodzat)
{
  for (int i=0; i<dodot; i++)
    printf("(");

  for (int i=0; i<len; i++, poc++)
    printf("%c", s[poc % len]);

  for (int i=0; i<dodzat; i++)
    printf(")");

  printf("\n");
}

void GenTour()
{
  for (int i=2*TOUR-1; i; i--) {
    if (i < TOUR)
      t[i] = Merge(t[2*i], t[2*i+1]);
    else {
      int poz = i - TOUR;
      if (poz >= 2 * len)
        continue;

      if (s[poz % len] == '(')
        t[i] = tour(1, 0, 0);
      else
        t[i] = tour(0, 1, 1);
    }
  }
}

tour Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return tour(0, 0, 0);
  if (lo >= begin && hi <= end)
    return t[pos];
  return Merge(Vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
               Vrati(2*pos+1, (lo+hi)/2, hi, begin, end) );
}

int main()
{
  tour rje = tour(0, 0, 0);
  int indr=0;

  scanf("%s", s); len = (int) strlen(s);

  GenTour();
  GenHes();

  for (int i=0; i<len; i++) {
    tour tmp = Vrati(1, 0, TOUR, i, i+len);
    if (!i || tmp.vel() < rje.vel() || (tmp.vel() == rje.vel() && Manji(i, indr))) {
      rje = tmp;
      indr = i;
    }
  }

  Ispis(indr, rje.dodot, rje.dodot + rje.brot - rje.brzat);

  return 0;
}
#include <cstdio>
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

const int MAX = 1005, MAXQ = 1e6 + 5, TOUR = 1<<10, LOG = 10;

int p[MAX][MAX];
int gorljev[MAX][MAX];
int rje[MAXQ];
int pref[MAX][MAX];
int brred, brstup;

void GenPref()
{
  for (int i=1; i<=brred; i++) {
    int sum = 0;
    for (int j=1; j<=brstup; j++) {
      sum += p[i][j];
      pref[i][j] = sum + pref[i-1][j];
    }
  }
}

int Sum(int rr1, int rr2, int ss1, int ss2)
{
  return pref[rr2][ss2] - pref[rr1-1][ss2] - pref[rr2][ss1-1] + pref[rr1-1][ss1-1];
}

void GenKvad()
{
  for (int i=1; i<=brred; i++) {
    for (int j=1; j<=brstup; j++) {
      int lo = 0, hi = min(brstup - j + 1, brred - i + 1);
      for (; lo < hi; ) {
        int mid = (lo + hi + 1) / 2;
        if (Sum(i, i + mid - 1, j, j + mid - 1) == mid * mid)
          lo = mid;
        else
          hi = mid - 1;
      }

      gorljev[i][j] = lo;
    }
  }
}

int konst[2*TOUR][2*TOUR][LOG];

void GenKonst()
{
  for (int i=1; i<=brred; i++) {
    for (int j=1; j<=brstup; j++)
      konst[i+TOUR][j][0] = gorljev[i][j];

    for (int k=1; k<LOG; k++)
      for (int j=1; j<=brstup; j++)
        konst[i+TOUR][j][k] = max(konst[i+TOUR][j][k-1], konst[i+TOUR][j + (1<<(k-1))][k-1]);
  }

  for (int i=TOUR-1; i; i--)
    for (int j=1; j<=brstup; j++)
      for (int k=0; k<LOG; k++)
        konst[i][j][k] = max(konst[2*i][j][k], konst[2*i+1][j][k]);
}

int VratiDol(int tour[2*TOUR][LOG], int poc, int kraj)
{
  int ind = 31 - __builtin_clz(kraj - poc + 1);
  return max(tour[poc][ind], tour[kraj - (1<<ind) + 1][ind]);
}

int VratiGor(int pos, int lo, int hi, int begin, int end, int s1, int s2)
{
  if (lo >= end || hi <= begin)
    return 0;
  if (lo >= begin && hi <= end)
    return VratiDol(konst[pos], s1, s2);
  return max(VratiGor(2*pos+0, lo, (lo+hi)/2, begin, end, s1, s2),
             VratiGor(2*pos+1, (lo+hi)/2, hi, begin, end, s1, s2));
}

int Query(int r1, int s1, int r2, int s2)
{
  return VratiGor(1, 0, TOUR, r1, r2 + 1, s1, s2);
}

int main()
{
  brred = 1000; brstup = 1000;
  scanf("%d%d", &brred, &brstup);

  for (int i=1; i<=brred; i++)
    for (int j=1; j<=brstup; j++) {
      p[i][j] = rand() % 2;
      scanf("%d", &p[i][j]);
    }

  GenPref();
  GenKvad();
  GenKonst();

  int q;
  q = 1000000;
  scanf("%d", &q);

  for (int i=0; i<q; i++) {
/*    r1[i] = 1;
    r2[i] = brred;
    s1[i] = 1;
    s2[i] = brstup;*/

    int r1, s1, r2, s2;
    r1 = rand() % brred + 1;
    r2 = rand() % brred + 1;
    s1 = rand() % brred + 1;
    s2 = rand() % brred + 1;

    if (r1 > r2)
      swap(r1, r2);

    if (s1 > s2)
      swap(s1, s2);

    scanf("%d%d%d%d", &r1, &s1, &r2, &s2);

    int lo = 0, hi = min(r2 - r1 + 1, s2 - s1 + 1);

    for (; lo < hi; ) {
      int mid = (lo + hi + 1) / 2;
      if (Query(r1, s1, r2 - mid + 1, s2 - mid + 1) >= mid)
        lo = mid;
      else
        hi = mid - 1;
    }

    printf("%d\n", lo);
  }

  return 0;
}
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef unsigned long long ull;
typedef pair<int,int> pii;

const int MAX = 505, MAXQ = 600100;

ull dpl[MAX][MAX][MAX / 64 + 1], dpr[MAX][MAX][MAX / 64 + 1];
int brred, brstup;
int brq;
int r1[MAXQ], r2[MAXQ], s1[MAXQ], s2[MAXQ];
char s[MAX][MAX];
int pr[4] = {-1, 0, 1, 0}, ps[4] = {0, -1, 0, 1};
int rje[MAXQ];

void DodajDp(ull dp[MAX][MAX][MAX / 64 + 1], int komr, int koms, int jar, int jas)
{
  for (int i=0; i<MAX/64+1; i++)
    dp[komr][koms][i] |= dp[jar][jas][i];
}

int Vani(int lo, int hi, int red, int stup)
{
  return red < 0 || red >= brred || stup < lo || stup > hi;
}

void RijesiDp(int lo, int mid, int hi)
{
  for (int i=0; i<brred; i++)
    for (int j=lo; j<=hi; j++)
      for (int k=0; k<MAX / 64 + 1; k++)
        dpl[i][j][k] = dpr[i][j][k] = 0;
    
  for (int i=brred-1; i>=0; i--)
    for (int j=mid; j>=lo; j--) {
      if (j == mid && s[i][j] == '.')
        dpl[i][j][i/64] |= ((ull) 1) << (i % 64);
      for (int k=0; k<2; k++) {
        int nr = i + pr[k];
        int ns = j + ps[k];
        if (!Vani(lo, hi, nr, ns) && s[nr][ns] == '.' && s[i][j] == '.')
          DodajDp(dpl, nr, ns, i, j);
      }
    }

  for (int i=0; i<brred; i++) {
    for (int j=mid; j<=hi; j++) {
      if (j == mid && s[i][j] == '.')
        dpr[i][j][i/64] |= ((ull) 1) << (i % 64);
      for (int k=2; k<4; k++) {
        int nr = i + pr[k];
        int ns = j + ps[k];
        if (!Vani(lo, hi, nr, ns) && s[nr][ns] == '.' && s[i][j] == '.')
          DodajDp(dpr, nr, ns, i, j);
      }
    }
  }
}

int RijesiQuery(int ind)
{
  for (int i=0; i<MAX / 64 + 1; i++)
    if (dpl[r1[ind]][s1[ind]][i] & dpr[r2[ind]][s2[ind]][i])
      return 1;

  return 0;
}

void Rek(int lo, int hi)
{
  int mid = (lo + hi) / 2;

  if (lo > hi)
    return;

  RijesiDp(lo, mid, hi);

  for (int i=0; i<brq; i++)
    if (s1[i] >= lo && s1[i] <= mid && s2[i] >= mid && s2[i] <= hi)
      rje[i] = RijesiQuery(i);

  Rek(lo, mid - 1);
  Rek(mid + 1, hi);
}

int main()
{
  scanf("%d%d", &brred, &brstup);

  for (int i=0; i<brred; i++)
    scanf("%s", s[i]);

  scanf("%d", &brq);

  for (int i=0; i<brq; i++) {
    scanf("%d%d%d%d", &r1[i], &s1[i], &r2[i], &s2[i]);
    s1[i]--; r1[i]--; s2[i]--; r2[i]--;
  }

  Rek(0, brstup - 1);

  for (int i=0; i<brq; i++) {
    if (rje[i])
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
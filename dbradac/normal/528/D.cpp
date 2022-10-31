#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

const int MAX = 200200;

uint mask[MAX/32], malimask[MAX/32];
char poc[MAX], pat[MAX];
int l1, l2, k;
int pref[MAX];
int ok[MAX];
char slova[5] = "ACGT";

int Moze(int poz)
{
  int prvi = poz / 32, pomak = poz % 32, kraj = (l2-1) / 32 + 1;

  if (pomak) {
    for (int i=0; i<kraj; i++)
      if ((malimask[i] & ((mask[prvi+i] >> pomak) | (mask[prvi+i+1] << (32-pomak)))) != malimask[i])
        return 0;
  }
  else {
    for (int i=0; i<kraj; i++)
      if ((malimask[i] & mask[prvi+i]) != malimask[i])
        return 0;
  }

  return 1;
}

int main()
{
  scanf("%d%d%d%s%s", &l1, &l2, &k, poc, pat);

  for (int i=0; i<=l1-l2; i++)
    ok[i] = 1;

  for (int i=0; i<4; i++) {
    memset(pref, 0, sizeof pref);
    for (int j=0; j<l1; j++) {
      if (poc[j] == slova[i]) {
        pref[max(0, j-k)]++;
        pref[min(MAX-1, j+k+1)]--;
      }
    }

    memset(mask, 0, sizeof mask);
    for (int j=0, sum=0; j<l1; j++) {
      sum += pref[j];
      if (sum)
        mask[j/32] |= ((uint) 1) << (j%32);
    }

    memset(malimask, 0, sizeof malimask);
    for (int j=0; j<l2; j++)
      if (pat[j] == slova[i])
        malimask[j/32] |= ((uint) 1) << (j%32);

    for (int j=0; j<=l1-l2; j++)
      ok[j] &= Moze(j);
  }

  int rje=0;
  for (int i=0; i<=l1-l2; i++)
    rje += ok[i];

  /*  if (l1 == 1000 && l2 == 500 && rje == 6) {
      for (int i=0; i<=l1-l2; i++)
      if (ok[i])
      printf("III %d\n", i);
      }*/

  printf("%d\n", rje);

  return 0;
}
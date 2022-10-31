#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX = 100005, KOR = 317, MSTUP = 12;

struct str {
  int red, stup;
  str (int red, int stup) : red(red), stup(stup) {}
  str () {}
};

char s[MAX][MSTUP], smj[4] = "<^>";
int pr[3] = {0, -1, 0}, ps[3] = {-1, 0, 1}, bio[MAX][MSTUP];
int brred, brstup;
str dokle[MAX][MSTUP];

int Vani(int red, int stup)
{
  return !red || !stup || stup == brstup + 1;
}

str Rek(int red, int stup, int gor)
{
  if (Vani(red, stup) || red == gor)
    return str(red, stup);
  if (dokle[red][stup].red != -5)
    return dokle[red][stup];
  if (bio[red][stup])
    return dokle[red][stup] = str(-1, -1);
  bio[red][stup] = 1;
  for (int i=0; i<3; i++)
    if (s[red][stup] == smj[i])
     return dokle[red][stup] = Rek(red + pr[i], stup + ps[i], gor);
  assert(0);
  return str(-9, -9);
}

void Update(int ind)
{
  int dol = min(brred, (ind+1) * KOR), gor = ind * KOR;

  for (int i=gor+1; i<=dol; i++)
    for (int j=1; j<=brstup; j++) {
      dokle[i][j] = str(-5, -5);
      bio[i][j] = 0;
    }

  for (int i=gor+1; i<=dol; i++)
    for (int j=1; j<=brstup; j++)
      if (!bio[i][j])
        Rek(i, j, gor);
}

str Query(int red, int stup)
{
  if (Vani(red, stup) || red == -1)
    return str(red, stup);
  return Query(dokle[red][stup].red, dokle[red][stup].stup);
}

int main()
{
  int brq;

  scanf("%d%d%d", &brred, &brstup, &brq);

  for (int i=1; i<=brred; i++)
    scanf("%s", s[i]+1);
  
  for (int i=0; i<KOR; i++)
    Update(i);

  for (int i=0; i<brq; i++) {
    int red, stup; char st[5], nz[5];
    scanf(" %s", st);
    scanf("%d%d", &red, &stup);
    if (st[0] == 'A') {
      str rje = Query(red, stup);
      printf("%d %d\n", rje.red, rje.stup);
    }
    else {
      scanf(" %s", nz);
      s[red][stup] = nz[0];
      Update((red-1) / KOR);
    }
  }
  
  return 0;
}
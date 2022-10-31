#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 105;

char s[MAX][MAX];
int dao[MAX][MAX];
int bio[MAX][MAX];

int Daj(int red, int stup, int treba)
{
  for (int i=0; i<=red; i++)
    for (int j=0; j<=stup; j++)
      dao[i][j] += treba;

  if (bio[red][stup])
    return 0;
  return bio[red][stup] = 1;
}

int main()
{
  int brred, brstup;

  scanf("%d%d", &brred, &brstup);

  for (int i=0; i<brred; i++)
    scanf("%s", s[i]);

  int rje = 0;
  for (int i=brred-1; i>=0; i--) {
    for (int j=brstup-1; j>=0; j--) {
      int koef = -1;
      if (s[i][j] == 'W')
        koef = 1;

      if (dao[i][j] != koef) {
        int treba = koef - dao[i][j];
        rje += Daj(i, j, treba);
      }
    }
  }
  
  printf("%d\n", rje);

  return 0;
}
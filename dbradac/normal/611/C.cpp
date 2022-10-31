#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 505;

int brred, brstup;
char s[MAX][MAX];
int prefhor[MAX][MAX], prefver[MAX][MAX];

void GenPref(int pref[MAX][MAX])
{
  for (int i=1; i<=brred; i++) {
    int sum = 0;
    for (int j=1; j<=brstup; j++) {
      sum += pref[i][j];
      pref[i][j] = sum + pref[i-1][j];
    }
  }
}

int Suma(int pref[MAX][MAX], int r1, int r2, int s1, int s2)
{
  if (r1 > r2 || s1 > s2)
    return 0;
  return pref[r2][s2] - pref[r1-1][s2] - pref[r2][s1-1] + pref[r1-1][s1-1];
}

int main()
{
  scanf("%d%d", &brred, &brstup);

  for (int i=1; i<=brred; i++)
    scanf("%s", s[i] + 1);

  for (int i=1; i<=brred; i++) {
    for (int j=1; j<=brstup; j++) {
      if (s[i][j] == '#')
        continue;

      if (i < brred && s[i+1][j] == '.')
        prefver[i][j] = 1;
      if (j < brstup && s[i][j+1] == '.')
        prefhor[i][j] = 1;
    }
  }

  GenPref(prefver);
  GenPref(prefhor);

  int q;
  scanf("%d", &q);
  
  for (; q--; ) {
    int r1, s1, r2, s2;
    scanf("%d%d%d%d", &r1, &s1, &r2, &s2);
    printf("%d\n", Suma(prefhor, r1, r2, s1, s2-1) + Suma(prefver, r1, r2-1, s1, s2));
  }

  return 0;
}
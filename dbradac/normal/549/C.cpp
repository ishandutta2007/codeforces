#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int n, k, nep=0, par=0;
  char s[2][15] = { "Stannis", "Daenerys" };

  scanf("%d%d", &n, &k);

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp & 1)
      nep++;
    else
      par++;
  }

  int pot = n - k;
  int stan = (pot + 1) / 2;
  int dan = pot / 2;
  int rje = 0;

  if (!pot) {
    if (!(nep & 1))
      rje = 1;
  }
  else {
    if (stan == dan) {
     if ((stan < par || !(k % 2)) || (dan >= min(nep, par) && !(k % 2)))
        rje = 1;
    }
    else {      
      int manji = min(nep, par);
      if (nep == par)
        manji--;
      if (dan >= nep || ((dan >= manji) && !(k % 2)))
        rje = 1;
    }
  }

  printf("%s\n", s[rje]);

  return 0;
}
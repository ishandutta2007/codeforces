#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int poz[2][MAX], br[2], zad[2];
int brrje;
pair <int, int> rje[MAX];

int Pozicija(int velset, int ind, int start)
{
  if (br[ind] - start < velset)
    return MAX;
  return poz[ind][start+velset-1];
}

int Moze(int velset)
{
  int kolko[2] = {0, 0};
  int start[2] = {0, 0};

  for (;;) {
    int p1, p2;
    p1 = Pozicija(velset, 0, start[0]);
    p2 = Pozicija(velset, 1, start[1]);

    if (p1 < p2) {
      if (p1 == MAX)
        return -1;

      start[0] += velset;
      kolko[0]++;

      if (p1 == zad[0] && p1 > zad[1] && kolko[0] > kolko[1])
        return kolko[0];
      
      start[1] = lower_bound(poz[1], poz[1] + br[1], p1) - poz[1];
    }
    else {
      if (p2 == MAX)
        return -1;
      
      start[1] += velset;
      kolko[1]++;

      if (p2 == zad[1] && p2 > zad[0] && kolko[1] > kolko[0])
        return kolko[1];

      start[0] = lower_bound(poz[0], poz[0] + br[0], p2) - poz[0];
    }
  }
}

int main()
{
  int n;

  scanf("%d", &n);
  
  zad[0] = zad[1] = -1;

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp); tmp--;
    poz[tmp][br[tmp]++] = i;
    zad[tmp] = i;
  }

  for (int i=1; i<=n; i++) {
    int tmp = Moze(i);
    if (tmp != -1) {
      rje[brrje] = make_pair(tmp, i);
      brrje++;
    }
  }

  sort(rje, rje+brrje);

  printf("%d\n", brrje);

  for (int i=0; i<brrje; i++)
    printf("%d %d\n", rje[i].first, rje[i].second);

  return 0;
}
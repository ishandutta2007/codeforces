#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 200100;

int n;
int p[MAX], poc[MAX];
int ind[MAX], poz[MAX];

int Slj(int mj, int len, int smj) //1 desno, -1 lijevo
{
  if (smj == 1)
    return upper_bound(p, p + n, p[mj] + len) - p - 1;
  return lower_bound(p, p + n, p[mj] - len) - p;
}

int OkoDva(int lev, int des, int len)
{
  if (lev == des)
    return lev;

  len %= 2 * (p[des] - p[lev]);
  des = Slj(lev, len, 1);
  len -= p[des] - p[lev];

  lev = Slj(des, len, -1);
  len -= p[des] - p[lev];

  return OkoDva(lev, des, len);
}

int Rijesi(int mj, int len)
{
  int des = Slj(mj, len, 1);
  len -= p[des] - p[mj];

  int lev = Slj(des, len, -1);
  len -= p[des] - p[lev];
  
  return OkoDva(lev, des, len);
}

int main()
{
  int brq;

  scanf("%d%d", &n, &brq);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    poc[i] = p[i];
  }
  
  sort(p, p + n);

  for (int i=0; i<n; i++) {
    int tmp = lower_bound(p, p + n, poc[i]) - p;
    ind[tmp] = i;
    poz[i] = tmp;
  }

  for (int i=0; i<brq; i++) {
    int mj, len;
    scanf("%d%d", &mj, &len);
    printf("%d\n", ind[Rijesi(poz[mj-1], len)] + 1);
  }

  return 0;
}
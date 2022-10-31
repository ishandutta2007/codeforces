#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

void Nope()
{
  printf("-1\n");
  exit(0);
}

int e[10][10];
char s1[10], s2[10];
int brkomp[1<<6], bredge[1<<6];
int poz[10], kraj[10];
vector <P> R;

int Brznam(int x)
{
  int ret=0;
  for (; x; x /= 10, ret++);
  return ret;
}

void DodajKomp(int mask, int st)
{
  for (int i=0; i<(1<<6); i++)
    if (mask & i)
      brkomp[i] += st;
}

void DodajEdge(int mask, int st)
{
  for (int i=0; i<(1<<6); i++)
    if ((mask & i) == mask)
      bredge[i] += st;
}

int Moze()
{
  for (int i=0; i<(1<<6); i++)
    if (bredge[i] >= brkomp[i] && bredge[i])
      return 0;
  return 1;
}

int main()
{
  int n;

  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    int tmp = Brznam(i) - 1;
    DodajKomp(1<<tmp, 1);
  }

  for (int i=0; i<n-1; i++) {
    scanf("%s%s", s1, s2);
    int a = (int) strlen(s1) - 1;
    int b = (int) strlen(s2) - 1;
    if (a > b)
      swap(a, b);

    e[a][b]++;
    DodajEdge((1<<a) | (1<<b), 1);
  }

  if (!Moze())
    Nope();

  poz[0] = 1;
  kraj[0] = min(9, n);
  for (int i=1; i<10; i++) {
    poz[i] = poz[i-1] * 10;
    kraj[i] = min(kraj[i-1] * 10 + 9, n);
  }
  poz[0] = 2;

  int tkomp = 1;
  for (int i=0; i<n-1; i++) {
    int da=0;
    int star = tkomp;
    for (int j=0; j<6; j++) { //na kojeg
      for (int k=0; k<6; k++) { //koji je novi
        if (!(tkomp & (1<<j)) || poz[k] > kraj[k] || !e[min(j, k)][max(j, k)])
          continue;

        DodajKomp(tkomp, -1);
        DodajKomp(1<<k, -1);
        tkomp |= (1<<k);
        DodajKomp(tkomp, 1);
        DodajEdge((1<<j) | (1<<k), -1);

        if (Moze()) {
          e[min(j, k)][max(j, k)]--;          
          R.push_back(P(poz[j] - 1, poz[k]));
          poz[k]++;
          da = 1;
          break;
        }

        DodajEdge((1<<j) | (1<<k), 1);
        DodajKomp(tkomp, -1);
        tkomp = star;
        DodajKomp(1<<k, 1);
        DodajKomp(tkomp, 1);
      }

      if (da)
        break;
    }
  }

  for (int i=0; i<n-1; i++)
    printf("%d %d\n", R[i].X, R[i].Y);

  return 0;
}
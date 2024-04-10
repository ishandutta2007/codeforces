#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 200050;

P sume[7];
int cov[3];
int pocbr[7], br[7];
int indbc;
int poz[8];

void Nope()
{
  printf("-1\n");
  exit(0);
}

int Smanji(int ind, int kol, int st)
{
  int poc = kol;

  for (int i=ind; i<=min(6, ind+st); i++) {
    int od = min(kol, br[i]);
    kol -= od;
    br[i] -= od;
  }

  return poc - kol;
}

int Rijesi()
{
  int ret = 0;
  ret += Smanji(poz[7], MAX, 0);

  int tmp = Smanji(poz[3], MAX, 0);
  ret += tmp;
  Smanji(poz[4], tmp, MAX);

  tmp = Smanji(poz[5], MAX, 0);
  ret += tmp;
  Smanji(poz[2], tmp, MAX);

  int s3 = br[6];
  int s2 = br[5];
  int s1 = br[4];
  if (poz[1] == 3)
    s1 += br[3];

  int dod = max(s1, max((s1 + s2) / 2, (s1 + s2 + s3) / 3));
  ret += dod;
  Smanji(poz[4], dod, MAX);
  Smanji(poz[2], dod, MAX);
  Smanji(poz[1], dod, MAX);

  for (int i=0; i<7; i++)
    if (br[i])
      return MAX;

  return ret;
}

bool Manji(const P &a, const P &b)
{
  if (a.X != b.X)
    return a.X > b.X;
  return a.Y < b.Y;
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<3; i++)
    scanf("%d", &cov[i]);

  sort(cov, cov + 3, greater<int>());

  for (int i=1; i<8; i++) {
    for (int j=0; j<3; j++)
      if (i & (1<<j))
        sume[i-1].X += cov[j];

    sume[i-1].Y = i;
  }

  sort(sume, sume + 7, Manji);
  for (int i=0; i<7; i++)
    poz[sume[i].Y] = i;

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp > sume[0].X)
      Nope();

    for (int j=0; j<7; j++) {
      if (j == 6 || sume[j+1].X < tmp) {
        pocbr[j]++;
        break;
      }
    }
  }

  int rje = MAX;
  for (int i=0; i<=MAX; i++) {
    memcpy(br, pocbr, sizeof br);
    int tmp = Smanji(poz[6], i, MAX);
    Smanji(poz[1], tmp, MAX);
    tmp += Rijesi();
    rje = min(rje, tmp);
  }

  printf("%d\n", rje);

  return 0;
}
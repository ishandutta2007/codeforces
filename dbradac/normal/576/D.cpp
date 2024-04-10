#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int MAX = 152;

struct str {
  int a, b, val;
} edge[MAX];

bool operator < (const str &a, const str &b)
{
  return a.val < b.val;
}

int n, m;

void Ispis(int a[MAX][MAX])
{
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }

  printf("\n");
}

void NapHor(int poc[MAX][MAX], ull kraj[MAX][3])
{
  for (int i=0; i<MAX; i++)
    for (int j=0; j<3; j++)
      kraj[i][j] = 0;

  for (int i=0; i<MAX; i++)
    for (int j=0; j<MAX; j++)
      if (poc[i][j])
        kraj[i][j/64] |= ((ull) 1) << (j % 64);
}

void NapVer(int poc[MAX][MAX], ull kraj[3][MAX])
{
  for (int i=0; i<3; i++)
    for (int j=0; j<MAX; j++)
      kraj[i][j] = 0;

  for (int i=0; i<MAX; i++)
    for (int j=0; j<MAX; j++)
      if (poc[i][j])
        kraj[i/64][j] |= ((ull) 1) << (i % 64);
}

void Mnoz(int prvi[MAX][MAX], int drugi[MAX][MAX], int c[MAX][MAX])
{
  for (int i=0; i<MAX; i++)
    for (int j=0; j<MAX; j++)
      c[i][j] = 0;

  ull a[MAX][3], b[3][MAX];

  NapHor(prvi, a);
  NapVer(drugi, b);

  for (int i=0; i<MAX; i++)
    for (int j=0; j<MAX; j++)
      for (int k=0; k<3; k++)
        if (a[i][k] & b[k][j]) {
          c[i][j] = 1;
          break;
        }
}

void Potenciraj(int baza[MAX][MAX], int rje[MAX][MAX], int eksp)
{
  int b[2][MAX][MAX];
  int rj[2][MAX][MAX];
  int indb=0, indr=0;

  memset(b, 0, sizeof b);
  memset(rj, 0, sizeof rj);
  memcpy(b[0], baza, sizeof (b[0]));

  for (int i=0; i<MAX; i++)
    rj[0][i][i] = 1;

  for (; eksp; indb ^= 1, eksp /= 2) {
    if (eksp & 1) {
      Mnoz(b[indb], rj[indr], rj[1^indr]);
      indr ^= 1;
    }

    Mnoz(b[indb], b[indb], b[1^indb]);
  }

  memcpy(rje, rj[indr], sizeof (rj[indr]));
}

int Nadi(int poc[MAX][MAX], int prij[MAX][MAX], int t)
{
  int tmp[2][MAX][MAX];

  memcpy(tmp[0], poc, sizeof (tmp[0]));

  if (tmp[0][0][n-1]) {
    printf("%d\n", t);
    return 1;
  }

  t++;
  for (int i=0, ind=0; i<MAX; i++, t++, ind ^= 1) {
    Mnoz(tmp[ind], prij, tmp[1^ind]);
    if (tmp[1^ind][0][n-1]) {
      printf("%d\n", t);
      return 1;
    }
  }

  return 0;
}

void Rijesi()
{
  int prij[MAX][MAX], poten[MAX][MAX];
  int mozdoc[2][MAX][MAX];

  memset(prij, 0, sizeof prij);
  memset(mozdoc, 0, sizeof mozdoc);  

  mozdoc[0][0][0] = 1;
  int ind = 0;
  int prosli = 0;
  for (int i=0; i<m; i++, ind ^= 1) {
    if (Nadi(mozdoc[ind], prij, prosli))
      return;

    Potenciraj(prij, poten, edge[i].val - prosli);
    Mnoz(mozdoc[ind], poten, mozdoc[1^ind]);
    prij[edge[i].a][edge[i].b] = 1;

    prosli = edge[i].val;
  }  

  if (Nadi(mozdoc[ind], prij, prosli))
    return;

  printf("Impossible\n");
}

int main()
{
  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    edge[i] = str { a, b, c };
  }

  sort(edge, edge + m);

  Rijesi();
  
  return 0;
}
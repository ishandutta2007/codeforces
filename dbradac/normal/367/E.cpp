#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const int MOD = 1000000007, MAX = 320;

int Add(int a, int b)
{
  int tmp = a + b;
  if (tmp >= MOD)
    tmp -= MOD;
  return tmp;
}

int Mul(int a, int b)
{
  ll tmp = (ll) a * b;
  if (tmp >= MOD)
    tmp %= MOD;
  return (int) tmp;
}

int Inverz(int x)
{
  int ret = 1;

  for (int eksp = MOD - 2; eksp; eksp >>= 1 , x = Mul(x, x))
    if (eksp & 1)
      ret = Mul(ret, x);

  return ret;
}

int fak[2*MAX*MAX], invfak[2*MAX*MAX], inv[2*MAX*MAX];
int doso[2*MAX][2*MAX], lijevi[2*MAX][2*MAX];
int n, m;

void GenFak()
{
  fak[0] = invfak[0] = 1;

  for (int i=1; i<2*MAX*MAX; i++) {
    fak[i] = Mul(i, fak[i-1]);
    invfak[i] = Inverz(fak[i]);
    inv[i] = Inverz(i);
  }
}


int Povrh (int a, int b)
{
  if (a < b)
    return 0;
  return Mul(Mul(fak[a], invfak[a-b]), invfak[b]);
}

int Catalan(int x)
{
  return Mul(Povrh(2*x, x), Inverz(x+1));
}

void It()
{
  doso[1][0] = 1;

  for (int i=1; i<=2*m; i++) {
    for (int j=0; j<=m; j++) {
      if (j < m)
        doso[i+1][j+1] = Add(doso[i+1][j+1], doso[i][j]);
      if (i - j - 1 < j)
        doso[i+1][j] = Add(doso[i+1][j], doso[i][j]);
    }
  }
}

void Lijevi()
{
  for (int br=1; br<=m; br++)
    for (int i=1; i<=2*m; i++)
      for (int j=0; j<=m; j++)
        lijevi[br][i] = Add(lijevi[br][i], Mul(doso[i][j], doso[2*br-i+1][br-i+j+1]));
}

int main()
{
  int x, rez=0;
  
  scanf("%d%d%d", &m, &n, &x);

  if (m > n) {
    printf("0\n");
    return 0;
  }
  
  GenFak();
  It();
  Lijevi();

  for (int brd=0; brd<=m; brd++) {
    int jed = 2 * (m - brd);
    for (int dpr=0; dpr<brd; dpr++) { //dvostruki na x
      int dpos = brd - dpr - 1;
      if ((!Povrh(x-1, dpr)) || (!Povrh(n-x, dpos)))
          continue;
      for (int jedpr=0; jedpr<=jed; jedpr++) {
        int jedpos = jed - jedpr;
        rez = Add(rez, Mul(Mul(Mul(Povrh(x-1, dpr), Povrh(n-x, dpos)),
                           Mul(Povrh(x-1-dpr, jedpr), Povrh(n-x-dpos, jedpos))), Catalan(m - brd)));
      }
    }

    for (int dpr=0; dpr<=brd; dpr++) { //jednostruki na x
      int dpos = brd - dpr;
      if ((!Povrh(x-1, dpr)) || (!Povrh(n-x, dpos)))
        continue;
      for (int jedpr=0; jedpr<jed; jedpr++) {
        int jedpos = jed - jedpr - 1;
        rez = Add(rez, Mul(Mul(Mul(Povrh(x-1, dpr), Povrh(n-x, dpos)),
                           Mul(Povrh(x-1-dpr, jedpr), Povrh(n-x-dpos, jedpos))), lijevi[m-brd][jedpr+1]));
      }
    }
  }

  rez = Mul(rez, fak[m]);
  printf("%d\n", rez);

  return 0;
}
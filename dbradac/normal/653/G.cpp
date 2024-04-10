#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19, LOG = 19;
const int MOD = 1e9 + 7;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Pot(int x, int e)
{
  int ret=1;
  for (; e; e /= 2, x = Mul(x, x))
    if (e & 1)
      ret = Mul(ret, x);

  return ret;
}

int Inverz(int x)
{
  return Pot(x, MOD - 2);
}

int fak[MAX], invfak[MAX];

int Povrh(int a, int b)
{
  if (b < 0 || b > a)
    return 0;
  return Mul(fak[a], Mul(invfak[b], invfak[a-b]));
}

void GenFak()
{
  fak[0] = invfak[0] = 1;
  for (int i=1; i<MAX; i++) {
    fak[i] = Mul(fak[i-1], i);
    invfak[i] = Inverz(fak[i]);
  }
}

int sito[MAX];
int p[MAX];
int n;
int kolko[MAX][LOG];
int preffak[MAX], preftez[MAX];

void Eratosten()
{
  for (int i=2; i<MAX; i++)
    if (!sito[i])
      for (int j=i; j<MAX; j+=i)
        sito[j] = i;
}

void Rastav(int x)
{
  for (; x > 1; ) {
    int pr = sito[x], pot = 0;
    for (; !(x % pr); x /= pr, pot++);
    kolko[pr][pot]++;
  }
}

void GenPref(int a, int kol)
{
  for (int i=0; i<=kol; i++) {
    preffak[i] = Povrh(a, i);
    preftez[i] = Mul(Povrh(a, i), i);
    if (i) {
      preffak[i] = Add(preffak[i], preffak[i-1]);
      preftez[i] = Add(preftez[i], preftez[i-1]);
    }
  }
}

int Eval(int x)
{
  int ret = 0;

  kolko[x][0] = n;
  for (int i=1; i<LOG; i++)
    kolko[x][0] -= kolko[x][i];

  for (int i=0; i<LOG-1; i++) {
    int desno = n - kolko[x][i], izg = 0;
    GenPref(kolko[x][i], desno + 1);
    for (int j=1; j<=desno; j++) {
      int nac = Mul(Povrh(desno, j), preffak[j-1]);
      izg = Add(izg, Mul(nac, j));
      ret = Add(ret, Mul(Povrh(desno, j), preftez[j-1]));
    }

    int ost = Sub(Mul(Pot(2, n - 1), desno), izg);
    ret = Add(ret, ost);
    kolko[x][i+1] = Add(kolko[x][i+1], kolko[x][i]);
  }

  return ret;
}

int main()
{
  Eratosten();
  GenFak();

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    Rastav(p[i]);
  }

  int rje = 0;
  for (int i=2; i<MAX; i++)
    if (sito[i] == i)
      rje = Add(rje, Eval(i));

  printf("%d\n", rje);

  return 0;
}
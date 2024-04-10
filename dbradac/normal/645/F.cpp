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

const int MAX = 1<<20, MOD = 1e9 + 7;

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

int Inverz(int a)
{
  int ret = 1;
  for (int e = MOD - 2; e; e /= 2, a = Mul(a, a))
    if (e & 1)
      ret = Mul(ret, a);

  return ret;
}

int sito[MAX];
int fak[MAX], invfak[MAX];
int mob[MAX];
int koef[MAX];
int rje = 0;
int k;
int kol[MAX];

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

void Eratosten()
{
  for (int i=2; i<MAX; i++)
    if (!sito[i])
      for (int j=i; j<MAX; j+=i)
        sito[j] = i;
}

vector <P> Rastav(int x)
{
  vector <P> R;

  for (; x > 1; ) {
    int pr = sito[x], pot = 0;
    for (; !(x % pr); x /= pr, pot++);
    R.push_back(P(pr, pot));
  }

  return R;
}

void GenKoef()
{
  for (int i=1; i<MAX; i++) {
    vector <P> T = Rastav(i);
    for (int j=0; j<(1<<T.size()); j++) {
      int tmp = i;
      for (int l=0; l<(int) T.size(); l++)
        if (j & (1<<l))
          tmp /= T[l].X;

      if (!(__builtin_popcount(j) & 1))
        koef[i] = Add(koef[i], tmp);
      else
        koef[i] = Sub(koef[i], tmp);
    }
  }
}

void Rek(int x, vector <P> &V, int ind)
{
  if (ind == (int) V.size()) {
    rje = Sub(rje, Mul(koef[x], Povrh(kol[x], k)));
    kol[x]++;
    rje = Add(rje, Mul(koef[x], Povrh(kol[x], k)));
    return;
  }

  Rek(x, V, ind + 1);
  for (; !(x % V[ind].X); ) {
    x /= V[ind].X;
    Rek(x, V, ind + 1);
  }
}
void Dodaj(int x)
{
  vector <P> V = Rastav(x);
  Rek(x, V, 0);
}

int main()
{
  Eratosten();
  GenFak();
  GenKoef();

  int n, q;
  scanf("%d%d%d", &n, &k, &q);

  for (int i=0; i<n+q; i++) {
    int tmp;
    scanf("%d", &tmp);
    Dodaj(tmp);
    if (i >= n)
      printf("%d\n", rje);
  }

  return 0;
}
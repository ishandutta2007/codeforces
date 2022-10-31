#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 500100, MAXK = 10000100, MOD = 1e9 + 7;

int Add(int a, int b)
{
  int tmp = a + b;
  if (tmp >= MOD)
    tmp -= MOD;
  return tmp;
}

int Sub(int a, int b)
{
  int tmp = a - b;
  if (tmp < 0)
    tmp += MOD;
  return tmp;
}

int Mul(int a, int b)
{
  return (int) (((long long) a * b) % MOD);
}

int Norm(int x)
{
  if (x < 0)
    x += MOD;
  return x;
}

int sito[MAXK];
int p[MAXN];
int ima[MAXK];
int pot2m1[MAXN];
int praz;

void Eratosten()
{
  for (int i=2; i<MAXK; i++)
    if (!sito[i])
      for (int j=i; j<MAXK; j+=i)
        sito[j] = i;
}

vector <int> Prosti(int x)
{
  vector <int> R;

  for (; x > 1; ) {
    int pr = sito[x];
    R.push_back(pr);
    for (; !(x % pr); x /= pr);
  }

  return R;
}

void Dodaj(vector <int> V, int pl)
{
  int vel = (int) V.size();

  for (int i=0; i<(1<<vel); i++) {
    int um=1;
    for (int j=0; j<vel; j++)
      if (i & (1<<j))
        um *= V[j];

    int st = 1;
    if (__builtin_popcount(i) % 2)
      st = -1;

    praz = Sub(praz, Norm(pot2m1[ima[um]] * st));
    ima[um] += pl;
    praz = Add(praz, Norm(pot2m1[ima[um]] * st));
  }
}

int Fui(vector <int> V)
{
  int vel = (int) V.size();
  int ret=0;

  for (int i=0; i<(1<<vel); i++) {
    int um=1;
    for (int j=0; j<vel; j++)
      if (i & (1<<j))
        um *= V[j];

    if (__builtin_popcount(i) % 2)
      ret = Sub(ret, pot2m1[ima[um]]);
    else
      ret = Add(ret, pot2m1[ima[um]]);
  }

  return Sub(ret, praz);
}


int main()
{
  int n;

  Eratosten();

  pot2m1[0] = 0;
  for (int i=1; i<MAXN; i++)
    pot2m1[i] = Add(Mul(pot2m1[i-1], 2), 1);

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    Dodaj(Prosti(p[i]), 1);
  }

  int rje=0;
  for (int i=0; i<n; i++) {
    vector <int> P = Prosti(p[i]);
    Dodaj(P, -1);
    rje = Add(rje, Fui(Prosti(p[i])));
    Dodaj(P, 1);
  }
  
  printf("%d\n", rje);

  return 0;
}
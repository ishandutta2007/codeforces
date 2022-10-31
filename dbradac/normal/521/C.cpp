#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<17, MOD = 1000000007;

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Inverz(int x)
{
  int ret=1;

  for (int eksp=MOD-2; eksp; eksp>>=1, x = Mul(x, x))
    if (eksp & 1)
      ret = Mul(ret, x);
  return ret;
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int pref[MAX];
int povrh[MAX], poten[MAX];
char s[MAX];
int n, k;

void GenPref()
{  
  int broj=1, naz=1;

  for (int i=n-2; i>n-1-k; i--)
    broj = Mul(broj, i);
  
  for (int i=1; i<=k-1; i++)
    naz = Mul(naz, i);

  int bin = Mul(broj, Inverz(naz));

  for (int i=1, indgor=n-2, inddol=n-1-k, pot=1; i<MAX; i++, indgor--, inddol--, pot = Mul(pot, 10)) {
    pref[i] = Add(pref[i-1], Mul(pot, bin));
    bin = Mul(bin, Mul(Inverz(indgor), inddol));
  }
}

void GenPovrh()
{
  int broj=1, naz=1;

  for (int i=1; i<=k; i++)
    broj = naz = Mul(naz, i);

  naz = Inverz(naz);
  int bin = Mul(broj, naz);

  for (int i=k; i<MAX; i++) {
    povrh[i] = bin;
    bin = Mul(bin, Mul(i+1, Inverz(i+1-k)));
  }
}

void GenPoten()
{
  poten[0] = 1;
  for (int i=1; i<MAX; i++)
    poten[i] = Mul(poten[i-1], 10);
}

int main()
{
  int rez = 0;

  scanf("%d%d %s", &n, &k, s);

  GenPref();
  GenPovrh();
  GenPoten();

  if (k == 0) {
    for (int pot=1, i=n-1; i>=0; pot = Mul(pot, 10), i--)
      rez = Add(rez, Mul(pot, s[i] - '0'));
    printf("%d\n", rez);
    return 0;
  }

  for (int i=0; i<n; i++) {
    rez = Add(rez, Mul(s[i] - '0', pref[n-i-1]));
    rez = Add(rez, Mul(s[i] - '0', Mul(povrh[i], poten[n-i-1])));
  }
  
  printf("%d\n", rez);

  return 0;
}
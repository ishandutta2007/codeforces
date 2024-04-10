#include <cstdio>
#include <algorithm>

using namespace std;

const int HO = 101, HM = 3137, MOD = 1000000009, MAX = 1<<20;

typedef long long ll;

int Mul(int a, int b)
{
  return ((ll) a * b) % MOD;
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Sub(int a, int b)
{
  return (a - b + MOD) % MOD;
}

int heso[MAX], hesm[MAX];
int poto[MAX], potm[MAX];

int GetHesO(int poz, int len)
{
  return heso[poz+len-1] - poto[len] * heso[poz-1];
}

int GetHesM(int poz, int len)
{
  return Sub(hesm[poz+len-1], Mul(potm[len], hesm[poz-1]));
}

int pref[MAX];
char s[MAX];

int Lcp(int poz1, int poz2, int maxlen)
{
  int lo=0, hi=maxlen;

  for (; lo<hi; ) {
    int mid = (lo + hi + 1) / 2;

    if (GetHesO(poz1, mid) == GetHesO(poz2, mid) &&
        GetHesM(poz1, mid) == GetHesM(poz2, mid))
          lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

int main()
{
  int n, k;

  scanf("%d%d%s", &n, &k, s+1);

  potm[0] = 1;
  for (int i=1; i<MAX; i++)
    potm[i] = Mul(potm[i-1], HM);

  poto[0] = 1;
  for (int i=1; i<MAX; i++)
    poto[i] = poto[i-1] * HO;
  
  for (int i=1; i<=n; i++)
    hesm[i] = Add(Mul(hesm[i-1], HM), s[i] - 'a' + 1);

  for (int i=1; i<=n; i++)
    heso[i] = heso[i-1] * HO + s[i] - 'a' + 1;
  
  for (int i=1; i<=n; i++) {
    if ((ll) i * k > n)
      break;

    int trebao = GetHesO(1, i);
    int trebam = GetHesM(1, i);
    int ne=0;
    int poz=1;

    for (int kolko=0; kolko < k; poz+=i, kolko++) {
      if (GetHesO(poz, i) != trebao || GetHesM(poz, i) != trebam) {
        ne = 1;
        break;
      }
    }

    if (!ne) {
      int dulj = Lcp(poz, 1, min(i, n-poz+1));
      pref[poz-1]++;
      pref[poz+dulj]--;
    }
  }
  
  for (int i=1, sum=0; i<=n; i++) {
    sum += pref[i];
    if (sum)
      printf("1");
    else
      printf("0");
  }

  printf("\n");

  return 0;
}
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 500500, MOD = 1e9 + 7;

ll Norm(ll x)
{
  return ((x % MOD + MOD) % MOD);
}

int n;
ll prefsumx[2*MAX], prefsumy[2*MAX];
ll prefpov[2*MAX];
ll prefob[2*MAX], prefprav[2*MAX];
P tocke[2*MAX];

ll UmToc(int a, int b)
{
  return (ll) tocke[a].X * tocke[b].Y - (ll) tocke[b].X * tocke[a].Y;
}

ll Suma(ll polje[2*MAX], int a, int b)
{
  if (a > b)
    b += n;

  ll ret = polje[b];
  if (a)
    ret -= polje[a-1];

  return ret;
}

ll Povrsina(int a, int b)
{
  if (a == b || a + 1 == b)
    return 0;

  return Suma(prefpov, a, b - 1) + UmToc(b, a);
}

void GenPref()
{
  for (int i=0; i<2*n; i++) {
    prefpov[i] = UmToc(i, i + 1);
    prefsumx[i] = tocke[i].X;
    prefsumy[i] = tocke[i].Y;
    if (i) {
      prefpov[i] += prefpov[i-1];
      prefsumx[i] += prefsumx[i-1];
      prefsumy[i] += prefsumy[i-1];
    }

    prefsumx[i] = Norm(prefsumx[i]);
    prefsumy[i] = Norm(prefsumy[i]);
  }
}

int main()
{
  scanf("%d", &n);
  for (int i=n-1; i>=0; i--)
    scanf("%d%d", &tocke[i].X, &tocke[i].Y);

  for (int i=n; i<=2*n; i++)
    tocke[i] = tocke[i%n];

  GenPref();
  ll summanj = 0;

  for (int i=0, j=1; i<n; i++) {
    j = max(j, i + 1);
    for (; Povrsina(i, j) <= Povrsina(j, i); j++); j--;
    if (Povrsina(i, j) == Povrsina(j, i) && i > (j % n))
      j--;

    if (j == i + 1)
      continue;
    
    int kol = j - (i + 1);
    prefob[i] += kol;
    prefprav[i+2]--;
    prefprav[j+1]++;

    summanj = Norm(summanj + Norm(Suma(prefsumx, i+2, j)) * tocke[i].Y - Norm(Suma(prefsumy, i+2, j)) * tocke[i].X);
  }
  
  ll tprav = 0, tsum = 0;
  for (int i=0; i<2*n; i++) {
    tprav += prefprav[i];
    tsum += prefob[i] + tprav;
    tsum = Norm(tsum);

    summanj = Norm(summanj + Norm(UmToc(i, i+1)) * tsum);    
  }

  ll rje = Norm(Norm((ll) n * (n - 3) / 2) * Norm(Povrsina(0, n - 1)) - 2 * summanj);
  printf("%lld\n", rje);

  return 0;
}
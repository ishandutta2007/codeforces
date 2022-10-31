#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1000000007, MAX = 1<<17, H1 = 3137, H2 = 101;

int pot1[MAX], pot2[MAX], hash1[MAX], hash2[MAX];
int jelpoc[MAX], prvikraj[MAX];
int mali1, mali2;
int l;
int poc[MAX];
int sve[MAX];
char s[MAX], mali[MAX];

int Jednako(int poc)
{
  int kraj = poc + l - 1;
  poc--;

  return ((hash1[kraj] - (ll) hash1[poc] * pot1[l]) % MOD + MOD) % MOD == (ll) mali1 &&
         ((hash2[kraj] - (ll) hash2[poc] * pot2[l]) % MOD + MOD) % MOD == (ll) mali2;
}

void Stavi(int pos, int val, int p[MAX])
{
  for (pos++; pos < MAX; pos += pos & -pos)
    p[pos] = (p[pos] + val) % MOD;
}

int Vrati(int pos, int p[MAX])
{
  int ret=0;

  for (pos++; pos; pos -= pos & -pos)
    ret = (ret + p[pos]) % MOD;
  return ret;
}

int main()
{
  int n;

  pot1[0] = pot2[0] = 1;
  for (int i=1; i<MAX; i++) {
    pot1[i] = (int) (((ll) pot1[i-1] * H1) % MOD);
    pot2[i] = (int) (((ll) pot2[i-1] * H2) % MOD);
  }

  scanf("%s%s", s+1, mali);
  n = (int) strlen(s+1);
  l = (int) strlen(mali);

  for (int i=0; i<l; i++) {
    mali1 = (int) (((ll) mali1 * H1 + mali[i] - 'a' + 1) % MOD);
    mali2 = (int) (((ll) mali2 * H2 + mali[i] - 'a' + 1) % MOD);
  }

  for (int i=1; i<=n; i++) {
    hash1[i] = (int) (((ll) hash1[i-1] * H1 + s[i] - 'a' + 1) % MOD);
    hash2[i] = (int) (((ll) hash2[i-1] * H2 + s[i] - 'a' + 1) % MOD);
  }
  
  memset(prvikraj, -1, sizeof prvikraj);

  for (int i=1; i+l-1<=n; i++)
    jelpoc[i] = Jednako(i);

  for (int i=n; i; i--) {
    if (jelpoc[i])
      prvikraj[i] = i + l - 1;
    else
      prvikraj[i] = prvikraj[i+1];
  }
  
  Stavi(n+1, 1, sve);
  poc[n+1] = 1;

  for (int i=n; i; i--) {
    int japoc=0;
    if (prvikraj[i] != -1)
      japoc = (Vrati(MAX-5, sve) - Vrati(prvikraj[i], sve) + MOD) % MOD;
    poc[i] = japoc;
    int sadsve = (japoc + (Vrati(i+1, sve) - Vrati(i, sve) + MOD) % MOD) % MOD;
    Stavi(i, sadsve, sve);
  }

  printf("%d\n", (MOD - 1 + Vrati(1, sve)) % MOD);

  return 0;
}
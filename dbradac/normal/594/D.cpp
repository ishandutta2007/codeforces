#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 200100, MAXK = 1<<20, MOD = 1e9 + 7;

int Add(int a, int b)
{
  int tmp = a + b;
  if (tmp >= MOD)
    tmp -= MOD;
  return tmp;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Inv(int x)
{
  int ret = 1;
  for (int e = MOD - 2; e; e /= 2, x = Mul(x, x))
    if (e & 1)
      ret = Mul(ret, x);

  return ret;
}

int inverz[MAXK];
int sito[MAXK];
int p[MAX];
int rje[MAX];
int l[MAX], r[MAX];
int fen[MAX];
int poz[MAXK];
vector <int> V[MAX];

void Stavi(int pos, int val)
{
  for (pos++; pos < MAX; pos += pos & -pos)
    fen[pos] = Mul(fen[pos], val);
}

int Vrati(int pos)
{
  int ret = 1;
  for (pos++; pos; pos -= pos & -pos)
    ret = Mul(ret, fen[pos]);
  return ret;
}

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
    for (; !(x % pr); x /= pr);
    R.push_back(pr);
  }

  return R;
}

int main()
{
  Eratosten();
  for (int i=0; i<MAX; i++)
    fen[i] = 1;

  for (int i=1; i<MAXK; i++)
    inverz[i] = Inv(i);

  int n;

  scanf("%d", &n);

  for (int i=1; i<=n; i++)
    scanf("%d", &p[i]);

  int brq;

  scanf("%d", &brq);

  for (int i=0; i<brq; i++) {
    scanf("%d%d", &l[i], &r[i]);
    V[r[i]].push_back(i);
  }

  for (int i=1; i<=n; i++) {
    vector <int> R = Prosti(p[i]);
    for (int j=0; j<(int) R.size(); j++) {
      Stavi(poz[R[j]], Mul(inverz[R[j]-1], R[j]));
      Stavi(i, Mul(R[j]-1, inverz[R[j]]));
      poz[R[j]] = i;
    }
    Stavi(i, p[i]);

    for (int j=0; j<(int) V[i].size(); j++) {
      int tmp = V[i][j];
      rje[tmp] = Mul(Vrati(i), Inv(Vrati(l[V[i][j]] - 1)));
    }
  }

  for (int i=0; i<brq; i++)
    printf("%d\n", rje[i]);

  return 0;
}
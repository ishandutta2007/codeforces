#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17, MAXKOR = 32000;

int mod;

int Add(int a, int b)
{
  return (a + b) % mod;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % mod);
}

int Pot(int x, int e)
{
  int ret=1;
  for (; e; e /= 2, x = Mul(x, x))
    if (e & 1)
      ret = Mul(ret, x);

  return ret;
}

set <int> Ord;
map <int, int> Dijeli;
map <int, int> Mob;
int sito[MAXKOR];
int p[MAX];
vector <int> Pr;
vector <int> D;

void Eratosten()
{
  for (int i=2; i<MAXKOR; i++)
    if (!sito[i]) {
      Pr.push_back(i);
      for (int j=i; j<MAXKOR; j+=i)
        sito[j] = i;
    }
}

vector <P> Rastav(int x)
{
  vector <P> R;

  for (auto it : Pr) {
    if (!(x % it)) {
      int pot = 0;
      for (; !(x % it); x /= it, pot++);
      R.push_back(P(it, pot));
    }
  }

  if (x > 1)
    R.push_back(P(x, 1));

  return R;
}

void Rek(vector <P> &R, int ind, int um, vector <int> &V)
{
  if (ind == (int) R.size()) {
    V.push_back(um);
    return;
  }

  for (int i=0; i<=R[ind].Y; i++) {
    Rek(R, ind + 1, um, V);
    um *= R[ind].X;
  }
}

vector <int> Djelitelji(int x)
{
  vector <P> R = Rastav(x);
  vector <int> Ret;
  Rek(R, 0, 1, Ret);
  return Ret;
}

int Order(int x)
{
  for (auto it : D)
    if (Pot(x, it) == 1)
      return it;

  assert(0);
}

int main()
{
  int n, m, gc;

  Eratosten();

  scanf("%d%d%d", &n, &m, &mod); gc = mod - 1;

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<m; i++) {
    int tmp;
    scanf("%d", &tmp);
    gc = __gcd(gc, tmp);
  }

  D = Djelitelji(mod - 1);

  for (int i=0; i<n; i++) {
    p[i] = Pot(p[i], gc);
    Ord.insert(Order(p[i]));
  }

  for (auto it : Ord) {
    vector <int> Dj = Djelitelji(it);
    for (auto it2 : Dj)
      Dijeli[it2]++;
  }

  int rje = 0;
  for (auto it = --Dijeli.end(); ; it--) {
    int st[2] = {1, mod-1};

    vector <P> R = Rastav(it->X);
    for (int i=0; i<(int) (1<<(int) R.size()); i++) {
      int tmp = it->X;
      for (int j=0; j<(int) R.size(); j++)
        if (i & (1<<j))
          tmp /= R[j].X;

      Mob[tmp] = Add(Mob[tmp], st[__builtin_popcount(i) & 1]);
    }

    rje = Add(rje, Mul(it->X, Mob[it->X]));

    if (it == Dijeli.begin())
      break;
  }

  printf("%d\n", rje);

  return 0;
}
#include <cstdio>
#include <map>
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

const int MAX = 1<<17;

int MOD;

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Sub(int a, int b)
{
  return (a - b + MOD) % MOD;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Fi()
{
  int x = MOD;
  int ret = x;

  for (int i=2; i * i < x; i++) {
    if (!(x % i)) {
      ret = (int) (((ll) ret * (i - 1) / i));
      for (; !(x % i); x /= i);
    }
  }

  if (x > 1)
    ret = (int) (((ll) ret * (x - 1) / x));

  return ret;
}

int Eksp(int x, int e)
{
  int r = 1;
  for (; e; e /= 2, x = Mul(x, x))
    if (e & 1)
      r = Mul(r, x);

  return r;
}

ll rje = 0;
int fi;
int inverz10;
vector <P> V[MAX];
int naprijed[MAX], nazad[MAX];
int dub[MAX], valpar[MAX];
int n;
int pot10[MAX], invpot10[MAX];
int subtree[MAX];
int zab[MAX], par[MAX];
map <int, int> Mnaz;

int DfsSub(int node, int prosli, vector <int> &T)
{
  subtree[node] = 0;
  T.push_back(node);
  par[node] = prosli;

  for (auto it : V[node])
    if (it.X != prosli && !zab[it.X])
      subtree[node] += DfsSub(it.X, node, T);

  return ++subtree[node];
}

int Pot10(int x)
{
  if (x < 0)
    return invpot10[-x];
  return pot10[x];
}

void Dodaj(int node)
{
  int val = Mul(Sub(0, naprijed[node]), Pot10(-dub[node]));
  rje += Mnaz[val];
}

void DfsNap(int node, int prosli, int pre, int val, vector <int> &T)
{
  T.push_back(node);

  if (prosli != -1) {
    dub[node] = dub[prosli] + 1;
    naprijed[node] = Add(Mul(10, val), pre);
  }
  else {
    dub[node] = 0;
    naprijed[node] = 0;
  }

  for (auto it : V[node]) {
    if (it.X != prosli && !zab[it.X]) {
      valpar[it.X] = it.Y;
      DfsNap(it.X, node, it.Y, naprijed[node], T);
    }
  }
}

void DfsNaz(int node, int prosli, int pre, int val, vector <int> &T)
{
  T.push_back(node);

  if (prosli != -1)
    nazad[node] = Add(val, Mul(pot10[dub[node] - 1], pre));
  else {
    dub[node] = 0;
    nazad[node] = 0;
  }

  for (auto it : V[node]) {
    if (it.X != prosli && !zab[it.X])
      DfsNaz(it.X, node, it.Y, nazad[node], T);
  }
}

void Decomp(int node)
{
  Mnaz.clear();

  vector <int> Svi;

  DfsSub(node, -1, Svi);

  int centr = -1;
  int kol = (int) Svi.size();

  for (auto it : Svi) {
    int mx = kol - subtree[it];

    for (auto it2 : V[it])
      if (it2.X != par[it] && !zab[it2.X])
        mx = max(mx, subtree[it2.X]);

    if (2 * mx <= kol)
      centr = it;
  }

  assert(centr != -1);
  zab[centr] = 1;
  dub[centr] = 0;
  naprijed[centr] = 0;
  nazad[centr] = 0;

  for (auto it : V[centr]) {
    if (zab[it.X])
      continue;

    vector <int> T;
    DfsNap(it.X, centr, it.Y, 0, T);
    T.clear();
    DfsNaz(it.X, centr, it.Y, 0, T);

    for (auto tmp : T)
      Dodaj(tmp);

    for (auto tmp : T)
      Mnaz[nazad[tmp]]++;
  }

  Dodaj(centr);  

  Mnaz.clear();

  Mnaz[nazad[centr]]++;
  for (int i=(int) V[centr].size() -1; i>=0; i--) {
    P it = V[centr][i];
    if (zab[it.X])
      continue;

    vector <int> T;
    DfsNap(it.X, centr, it.Y, 0, T);
    T.clear();
    DfsNaz(it.X, centr, it.Y, 0, T);

    for (auto tmp : T)
      Dodaj(tmp);

    for (auto tmp : T)
      Mnaz[nazad[tmp]]++;
  }

  for (auto it : V[centr])
    if (!zab[it.X])
      Decomp(it.X);
}

int main()
{
  scanf("%d%d", &n, &MOD);

  fi = Fi();

  pot10[0] = 1;
  invpot10[0] = 1;
  for (int i=1; i<MAX; i++) {
    pot10[i] = Mul(10, pot10[i-1]);
    invpot10[i] = Eksp(pot10[i], fi - 1);
  }

  for (int i=0; i<n-1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); c %= MOD;
    V[a].push_back(P(b, c));
    V[b].push_back(P(a, c));
  }

  vector <int> Mamice;
  DfsSub(0, -1, Mamice);
  Decomp(0);

  printf("%lld\n", rje);

  return 0;
}
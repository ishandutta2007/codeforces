#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 1<<18;
const int MOD = 1e9 + 7;

int add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int bio[MAX];
ll val[MAX];
vector <P> V[MAX];
int pot[MAX];

int povrh2(int x)
{
  return (int) (((ll) x * (x - 1) / 2) % MOD);
}

vector <ll> gauss(vector <ll> T)
{
  vector <ll> R;

  int ind = 0;
  for (int i=0; i<63; i++) {
    for (int j=ind; j<(int) T.size(); j++) {
      if (T[j]>>i & 1) {
        swap(T[ind], T[j]);
        for (int k=0; k<(int) T.size(); k++)
          if (k != ind && (T[k]>>i & 1))
            T[k] ^= T[ind];

        ind++;
      }
    }
  }

  for (auto it : T)
    if (it)
      R.push_back(it);

  return R;
}

void dfs(ll node, ll prosli, vector <ll> &T, vector <ll> &Cv)
{
  bio[node] = 1;
  Cv.push_back(node);

  for (auto it : V[node]) {
    if (bio[it.X] && it.X != prosli)
      T.push_back(val[node] ^ val[it.X] ^ it.Y);
    else if (!bio[it.X]) {
      val[it.X] = val[node] ^ it.Y;
      dfs(it.X, node, T, Cv);
    }
  }
}

int eval(int node)
{
  int ret = 0;
  vector <ll> T;
  vector <ll> Cv;

  dfs(node, -1, T, Cv);
  T = gauss(T);

  int sajz = (int) T.size();
  for (int i=0; i<62; i++) {
    int brojnode[2] = {0, 0};
    int brojgaus[2] = {0, 0};

    for (auto it : Cv)
      brojnode[(val[it]>>i) & 1]++;

    for (auto it : T)
      brojgaus[(it>>i) & 1]++;

    int prom = 0, neprom = pot[sajz];
    if (brojgaus[1])
      prom = pot[sajz-1];
    neprom = sub(pot[sajz], prom);

    int tmp = 0;
    tmp = add(tmp, mul(add(povrh2(brojnode[0]), povrh2(brojnode[1])), prom));
    tmp = add(tmp, mul(mul(brojnode[0], brojnode[1]), neprom));

    ret = add(ret, mul(tmp, pot[i]));
  }

  return ret;
}

int main()
{
  pot[0] = 1;
  for (int i=1; i<MAX; i++)
    pot[i] = mul(2, pot[i-1]);

  int n, m;
  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b;
    ll c;
    scanf("%d%d%lld", &a, &b, &c); a--; b--;
    V[a].push_back(P(b, c));
    V[b].push_back(P(a, c));
  }

  int rje = 0;
  for (int i=0; i<n; i++)
    if (!bio[i])
      rje = add(rje, eval(i));

  printf("%d\n", rje);

  return 0;
}
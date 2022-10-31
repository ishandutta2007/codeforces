#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1<<20, LOG = 20, MOD = (1e9) + 7;

int ea[MAXN], eb[MAXN], est[MAXN];
int lca[MAXN][LOG], dub[MAXN];
int gore[MAXN], dole[MAXN];
int pot[MAXN];
int p[MAXN];
vector <int> V[MAXN];

int Add(int a, int b)
{
  return (((a + b) % MOD) + MOD) % MOD;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

void Dfs(int node, int prosli)
{
  dub[node] = dub[prosli] + 1;
  lca[node][0] = prosli;
  for (int i=1; i<LOG; i++)
    lca[node][i] = lca[lca[node][i-1]][i-1];

  for (int i=0; i<(int) V[node].size(); i++)
    if (V[node][i] != prosli)
      Dfs(V[node][i], node);
}

int Lca(int a, int b)
{
  if (dub[a] > dub[b])
    swap(a, b);

  for (int i=0, raz=dub[b]-dub[a]; raz; raz /= 2, i++)
    if (raz & 1)
      b = lca[b][i];

  if (a == b)
    return a;

  for (int i=LOG-1; i>=0; i--) {
    if (lca[a][i] != lca[b][i]) {
      a = lca[a][i];
      b = lca[b][i];
    }
  }

  return lca[a][0];
}

void DfsCalc(int node, int prosli)
{
  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli) {
      DfsCalc(nn, node);
      gore[node] += gore[nn];
      dole[node] += dole[nn];
    }
  }
}

int main()
{
  int n, k;

  scanf("%d", &n);

  for (int i=0; i<n-1; i++) {
    scanf("%d%d%d", &ea[i], &eb[i], &est[i]);
    V[ea[i]].push_back(eb[i]);
    V[eb[i]].push_back(ea[i]);
  }

  Dfs(1, 1);

  scanf("%d", &k);

  int mojg = 1;
  for (int i=0; i<k; i++) {
    scanf("%d", &p[i]);
    int lc = Lca(mojg, p[i]);

    gore[mojg]++;
    gore[lc]--;

    dole[p[i]]++;
    dole[lc]--;

    mojg = p[i];
  }

  DfsCalc(1, 1);

  pot[0] = 1;
  for (int i=1; i<MAXN; i++)
    pot[i] = Mul(pot[i-1], 2);

  int rje = 0;
  for (int i=0; i<n-1; i++) {
    if (est[i]) {
      if (dub[ea[i]] < dub[eb[i]])
        rje = Add(rje, pot[gore[eb[i]]] - 1);
      else
        rje = Add(rje, pot[dole[ea[i]]] - 1);
    }
  }
  
  printf("%d\n", rje);

  return 0;
}
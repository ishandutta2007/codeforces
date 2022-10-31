#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 200100, LOG = 18, INF = 0x3f3f3f3f;

int n;
vector <P> V[MAX];
int disc[MAX];
int wkomp[MAX], komp[MAX];
int bio[MAX];
int isbridge[MAX];
int brk = 0;
int vr = 1;
int from[MAX], to[MAX];
int lca[MAX][LOG];
int dub[MAX];
int gore[MAX], dolje[MAX];
P sorted[MAX];
vector <int> Vk[MAX];

int Bridgevi(int node, int prosli, int tk)
{
  komp[node] = tk;
  disc[node] = vr++;
  int ret = MAX;

  for (int i=0; i<(int) V[node].size(); i++) {
    P nn = V[node][i];
    
    if (!disc[nn.X])
      ret = min(ret, Bridgevi(nn.X, nn.Y, tk));
    else if (nn.Y != prosli)
      ret = min(ret, disc[nn.X]);
  }
  
  if (prosli != -1 && ret >= disc[node])
    isbridge[prosli] = 1;

  return ret;
}

void DfsKomp(int node, int tk)
{
  wkomp[node] = tk;
  Vk[tk].push_back(node);

  for (int i=0; i<(int) V[node].size(); i++) {
    P nn = V[node][i];
    if (!isbridge[nn.Y] && wkomp[nn.X] == -1)
      DfsKomp(nn.X, tk);
  }
}

void InitLca(int node, int prosli)
{
  bio[node] = 1;

  lca[node][0] = prosli;
  dub[node] = dub[prosli] + 1;
  for (int i=1; i<LOG; i++)
    lca[node][i] = lca[lca[node][i-1]][i-1];

  for (int i=0; i<(int) Vk[node].size(); i++) {
    for (int j=0; j<(int) V[Vk[node][i]].size(); j++) {
      P nn = V[Vk[node][i]][j];
      if (isbridge[nn.Y] && !bio[wkomp[nn.X]])
        InitLca(wkomp[nn.X], node);
    }
  }
}

int Lca(int a, int b)
{
  if (dub[a] > dub[b])
    swap(a, b);

  for (int i=0, raz = dub[b] - dub[a]; raz; raz /= 2, i++)
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

int main()
{
  int m, brq, rje = 1;

  scanf("%d%d%d", &n, &m, &brq);

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(P(b, i));
    V[b].push_back(P(a, i));
  }

  for (int i=0; i<n; i++)
    if (!disc[i])
      Bridgevi(i, -1, brk++);
  
  for (int i=0; i<brq; i++) {
    scanf("%d%d", &from[i], &to[i]); from[i]--; to[i]--;
    if (komp[from[i]] != komp[to[i]])
      rje = 0;
  }

  memset(wkomp, -1, sizeof wkomp);
  for (int i=0; i<n; i++)
    if (wkomp[i] == -1)
      DfsKomp(i, brk++);
  
  memset(bio, 0, sizeof bio);
  for (int i=0; i<brk; i++)
    if (!bio[i])
      InitLca(i, i);
  
  memset(gore, INF, sizeof gore);
  memset(dolje, INF, sizeof dolje);

  for (int i=0; i<brq; i++) {
    int lc = Lca(wkomp[from[i]], wkomp[to[i]]);
    gore[wkomp[from[i]]] = min(gore[wkomp[from[i]]], dub[lc]);
    dolje[wkomp[to[i]]] = min(dolje[wkomp[to[i]]], dub[lc]);
  }

  for (int i=0; i<brk; i++)
    sorted[i] = P(-dub[i], i);

  sort(sorted, sorted + brk);

  for (int i=0; i<brk; i++) {
    int tmp = sorted[i].Y;
    if (gore[tmp] < dub[tmp] && dolje[tmp] < dub[tmp])
      rje = 0;

    gore[lca[tmp][0]] = min(gore[lca[tmp][0]], gore[tmp]);
    dolje[lca[tmp][0]] = min(dolje[lca[tmp][0]], dolje[tmp]);
  }

  printf("%s\n", rje ? "Yes" : "No");

  return 0;
}
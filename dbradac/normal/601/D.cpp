#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int MOD[2] = {(int) (1e9 + 7), (int) (1e9 + 9)}, H[2] = {3137, 101};
const int MAX = 300100;

typedef pair<int, int> P;
#define X first
#define Y second

P sor[MAX];
vector <int> V[MAX];
int uk[MAX], maxx = -1;
int pot[2][MAX];
int n;
int dub[MAX];
int c[MAX];
int subtree[MAX];
char ss[MAX];
int pl;
int jelnaj[MAX];
int tren=0;
P hsh[MAX];
multiset <P> S;

int Add(int a, int b, int iii)
{
  a += b;
  if (a >= MOD[iii])
    a -= MOD[iii];
  return a;
}

int Mul(int a, int b, int iii)
{
  return (int) (((long long) a * b) % MOD[iii]);
}

int Dfs(int node, int prosli, P th)
{
  dub[node] = dub[prosli] + 1;

  th = P(Add(th.X, Mul(pot[0][dub[node]], (int) ss[node] - 'a' + 1, 0), 0),
         Add(th.Y, Mul(pot[1][dub[node]], (int) ss[node] - 'a' + 1, 1), 1));
  hsh[node] = th;

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli)
      subtree[node] += Dfs(nn, node, th);
  }

  return ++subtree[node];
}

void Makni(P vall)
{
  S.erase(S.find(vall));
  if (S.find(vall) == S.end())
    tren--;
}

void Stavi(P vall)
{
  if (S.find(vall) == S.end())
    tren++;
  S.insert(vall);
}

void Pocisti(int node, int prosli)
{
  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli)
      Pocisti(nn, node);
  }

  Makni(hsh[node]);
}

void DfsStavi(int node, int prosli)
{
  Stavi(hsh[node]);
  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli)
      DfsStavi(nn, node);
  }
}

void DfsRje(int node, int prosli, int vr)
{
  int tmaxx = -1, ind = -1;

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli && subtree[nn] > tmaxx) {
      tmaxx = subtree[nn];
      ind = nn;
    }
  }

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli && nn != ind)
      DfsRje(nn, node, 1);
  }

  if (ind != -1)
    DfsRje(ind, node, 0);

  Stavi(hsh[node]);
  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli && nn != ind)
      DfsStavi(nn, node);
  }

  uk[node] = tren + c[node];
//  if (uk[node] == 6)
  //  printf("ASDF %d %d\n", node + 1, uk[node]);

  maxx = max(maxx, uk[node]);

  if (vr)
    Pocisti(node, prosli);
}

void GenPot()
{
  for (int i=0; i<2; i++) {
    pot[i][0] = 1;
    for (int j=1; j<MAX; j++)
      pot[i][j] = Mul(pot[i][j-1], H[i], i);
  }
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &c[i]);

  scanf("%s", ss);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  GenPot();
  Dfs(0, 0, P(0, 0));
  DfsRje(0, -1, 0);

  int rje = 0;
  printf("%d\n", maxx);
  for (int i=0; i<n; i++)
    if (uk[i] == maxx)
      rje++;

  printf("%d\n", rje);

  return 0;
}
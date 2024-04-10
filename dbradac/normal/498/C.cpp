#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 31623, MAXN = 105;

int brpr;
int sito[MAX], prosti[MAX];
int edge[MAXN][MAXN];
int n, brpar;
int bio[MAXN];
int p[MAXN];
int rje;
int a[MAXN], b[MAXN];
vector <int> V[MAXN];
map <int, int> M;

int Dfs(int node, int protok)
{
  if (protok <= 0)
    return 0;

  bio[node] = 1;
  if (node == n + 1) {
    rje += protok;
    return protok;
  }

  for (int i=0; i<(int) V[node].size(); i++) {
    int slj = V[node][i];
    if (!bio[slj]) {
      int tmp = Dfs(slj, min(protok, edge[node][slj]));
      if (tmp > 0) {
        edge[node][slj] -= tmp;
        edge[slj][node] += tmp;
        return tmp;
      }
    }
  }

  return 0;
}

void Flow()
{
  for (;;) {
    memset(bio, 0, sizeof bio);
    if (!Dfs(0, 50))
      break;
  }
}

void Rastav(int x)
{
  for (int i=0; i<brpr; i++) {
    if (!(x % prosti[i]))
      M[prosti[i]] = 1;
    for (; !(x % prosti[i]); x /= prosti[i]);
  }

  if (x > 1)
    M[x] = 1;
}

void Prep(int broj)
{
  for (int i=1; i<=n; i++) {
    int tmp=0;
    for (; !(p[i] % broj); p[i] /= broj, tmp++);
    if (!(i%2))
      edge[0][i] = tmp;
    else
      edge[i][n+1] = tmp;
  }

  for (int i=0; i<brpar; i++) {
    edge[a[i]][b[i]] = 50;
    edge[b[i]][a[i]] = 0;
  }
}

int main()
{
  for (int i=2; i<MAX; i++) {
    if (!sito[i]) {
      prosti[brpr++] = i;
      for (int j=2*i; j<MAX; j+=i)
        sito[j] = 1;
    }
  }

  scanf("%d%d", &n, &brpar);
  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    Rastav(p[i]);
  }

  for (int i=0; i<brpar; i++) {
    scanf("%d%d", &a[i], &b[i]);
    if (a[i] % 2)
      swap(a[i], b[i]);
    V[a[i]].push_back(b[i]);
    V[b[i]].push_back(a[i]);
  }

  for (int i=1; i<=n; i++) {
    V[0].push_back(i);
    V[i].push_back(n+1);
  }

  for (map <int, int> :: iterator it=M.begin(); it!=M.end(); it++) {
    Prep(it->first);
    Flow();
  }

  printf("%d\n", rje);

  return 0;
}
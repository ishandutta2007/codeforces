#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1<<17;

int rje;
int n, m;
vector <int> V[MAX];
int p[MAX];

void Dfs(int node, int prosli, int cat)
{
  if (p[node])
    cat++;
  else
    cat = 0;

  if (cat > m)
    return;

  if (V[node].size() == 1 && node)
    rje++;

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli)
      Dfs(nn, node, cat);
  }
}

int main()
{
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  Dfs(0, -1, 0);

  printf("%d\n", rje);

  return 0;
}
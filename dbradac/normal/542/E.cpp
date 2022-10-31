#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1005;

int n;
int ne = 0;
int dist[MAX], komp[MAX];
int best[MAX];
vector <int> V[MAX];
queue <int> Q;

void Bfs(int node, int tk)
{
  memset(dist, -1, sizeof dist);
  dist[node] = 0;
  Q.push(node);

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();
    komp[tmp] = tk;
    best[tk] = max(best[tk], dist[tmp]);

    for (int i=0; i<(int) V[tmp].size(); i++) {
      int nn = V[tmp][i];
      if (dist[nn] == -1) {
        dist[nn] = dist[tmp] + 1;
        Q.push(nn);
      }
      else if (!((dist[tmp] - dist[nn]) % 2))
        ne = 1;
    }
  }
}

int main()
{
  int m;

  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  memset(komp, -1, sizeof komp);
  int brkomp = 0;

  for (int i=0; i<n; i++) {
    if (komp[i] == -1)
      Bfs(i, brkomp++);
    else
      Bfs(i, komp[i]);
  }

  if (ne)
    printf("-1\n");
  else {
    int rje = 0;
    for (int i=0; i<brkomp; i++)
      rje += best[i];

    printf("%d\n", rje);
  }

  return 0;
}
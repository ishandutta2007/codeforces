#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 3005, INF = 0x3f3f3f3f;

vector <int> V[MAX];
queue <int> Q;
int dist[MAX][MAX];

void Bfs(int poc)
{
  dist[poc][poc] = 0;
  Q.push(poc);

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();
    for (int i=0; i<(int) V[tmp].size(); i++) {
      int nn = V[tmp][i];
      if (dist[poc][nn] == INF) {
        dist[poc][nn] = dist[poc][tmp] + 1;
        Q.push(nn);
      }
    }
  }
}

int main()
{
  int n, e;

  memset(dist, INF, sizeof dist);

  scanf("%d%d", &n, &e);

  for (int i=0; i<e; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].push_back(b);
    V[b].push_back(a);    
  }
  
  int a, b, t1, c, d, t2;
  scanf("%d%d%d%d%d%d", &a, &b, &t1, &c, &d, &t2);

  for (int i=1; i<=n; i++)
    Bfs(i);

  if (dist[a][b] > t1 || dist[c][d] > t2)
    printf("-1\n");
  else {
    int minn = dist[a][b] + dist[c][d];
  
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        int val = dist[a][i] + 
                  dist[i][c] + 
                  dist[i][j] + 
                  dist[j][b] + 
                  dist[j][d];
        
        if (dist[a][i] + dist[i][j] + dist[j][b] <= t1 &&
            dist[c][i] + dist[i][j] + dist[j][d] <= t2)
              minn = min(minn, val);
        
        val = dist[a][i] +
              dist[i][d] +
              dist[i][j] +
              dist[j][b] +
              dist[j][c];

        if (dist[a][i] + dist[i][j] + dist[j][b] <= t1 &&
            dist[d][i] + dist[i][j] + dist[j][c] <= t2)
              minn = min(minn, val);

        val = dist[a][i] + 
              dist[i][b] +
              dist[i][j] +
              dist[j][c] +
              dist[j][d];

        if (dist[a][i] + dist[i][b] <= t1 &&
            dist[c][j] + dist[j][d] <= t2)
              minn = min(minn, val);
      }
    }

    printf("%d\n", e - minn);
  }

  return 0;
}
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 10005, MAXK = 10, MAXL = 105, INF = 0x3f3f3f3f;

int n, k, l;
int p[MAXK];
int trebam[MAXN];
int dulj[MAXL];
int dist[2*MAXK][MAXN];
int dp[1<<(2*MAXK)];
vector <int> V;
queue <int> Q;

void Bfs(int poc)
{
  dist[poc][V[poc]] = 0;
  Q.push(V[poc]);

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();
    for (int i=0; i<l; i++) {
      for (int j=-1; j<=2; j+=2) {
        int nn = tmp + dulj[i] * j;
        if (nn >= 0 && nn <= n && dist[poc][nn] == INF) {
          dist[poc][nn] = dist[poc][tmp] + 1;
          Q.push(nn);
        }
      }
    }
  }
}

int main()
{
  scanf("%d%d%d", &n, &k, &l);

  for (int i=0; i<k; i++) {
    scanf("%d", &p[i]); p[i]--;
    trebam[p[i]] ^= 1;
    trebam[p[i]+1] ^= 1;
  }

  for (int i=0; i<l; i++)
    scanf("%d", &dulj[i]);

  memset(dist, INF, sizeof dist);

  for (int i=0; i<=n; i++)
    if (trebam[i])
      V.push_back(i);

  for (int i=0; i<(int) V.size(); i++)
    Bfs(i);

  memset(dp, INF, sizeof dp);
  dp[0] = 0;
  int sz = (int) V.size();

  for (int i=0; i<(1<<(sz)); i++) {
    int ind = -1;
    for (int j=0; j<sz; j++) {
      if (!(i & (1<<j))) {
        ind = j;
        break;
      }
    }

    if (ind == -1)
      break;

    for (int j=0; j<sz; j++)
      if (!(i & (1<<j)) && j != ind)
        dp[i | (1<<ind) | (1<<j)] = min(dp[i | (1<<ind) | (1<<j)], dp[i] + dist[ind][V[j]]);
  }

  if (dp[(1<<sz)-1] == INF)
    printf("-1\n");
  else
    printf("%d\n", dp[(1<<sz)-1]);

  return 0;
}
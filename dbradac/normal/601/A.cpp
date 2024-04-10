#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct str {
  int a, b, raz;
};

const int MAX = 405, INF = 0x3f3f3f3f;

queue <str> Q;
int dp[2][MAX][MAX];
int e[MAX][MAX];
int n, m;

void Stavi(int a, int b, int raz, int vr)
{
  if (dp[raz][a][b] == INF) {
    dp[raz][a][b] = vr;
    Q.push(str { a, b, raz });
  }
}

int Bfs()
{
  memset(dp, INF, sizeof dp);
  dp[0][0][0] = 0;
  Q.push(str { 0, 0, 0 });

  for (; !Q.empty(); ) {
    str tmp = Q.front();
    Q.pop();
    if (tmp.a == tmp.b && tmp.a == n - 1)
      return dp[tmp.raz][tmp.a][tmp.b];

    int nvr = dp[tmp.raz][tmp.a][tmp.b];
    if (!tmp.raz)
      nvr++;
  
    if (!tmp.raz) {
      for (int i=0; i<n; i++)
        if (e[tmp.a][i])
          Stavi(i, tmp.b, 1^tmp.raz, nvr);
    }
    else {
      for (int i=0; i<n; i++)
        if (!e[tmp.b][i])
          Stavi(tmp.a, i, 1^tmp.raz, nvr);
    }
  }

  return -1;
}

int main()
{
  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    e[a][b] = e[b][a] = 1;
  }
  e[n-1][n-1] = 1;

  printf("%d\n", Bfs());

  return 0;
}
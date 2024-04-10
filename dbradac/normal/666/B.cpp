#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 3005;

vector <P> Nap[MAX], Naz[MAX];
int dist[MAX][MAX];
int n, m;
vector <int> V[MAX];

void Bfs(int poc)
{
  queue <int> Q;
  Q.push(poc);
  dist[poc][poc] = 0;

  for (; !Q.empty(); ) {
    int tmp = Q.front(); Q.pop();
    for (auto it : V[tmp]) {
      if (dist[poc][it] == -1) {
        dist[poc][it] = dist[poc][tmp] + 1;
        Q.push(it);
      }
    }
  }
}

int main()
{
  memset(dist, -1, sizeof dist);

  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
  }

  for (int i=0; i<n; i++)
    Bfs(i);

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if (dist[i][j] != -1) {
        Nap[i].push_back(P(dist[i][j], j));
        Naz[j].push_back(P(dist[i][j], i));
      }

  for (int i=0; i<n; i++) {
    sort(Nap[i].begin(), Nap[i].end(), greater<P>());
    sort(Naz[i].begin(), Naz[i].end(), greater<P>());
  }

  int rje = -1;
  vector <int> R;

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      for (int k=0; k<5; k++) {
        for (int l=0; l<5; l++) {
          if (k >= (int) Naz[i].size() || l >= (int) Nap[j].size() || dist[i][j] == -1)
            continue;

          int sum = dist[i][j] + Naz[i][k].X + Nap[j][l].X;
          if (sum <= rje)
            continue;

          vector <int> T{ Naz[i][k].Y, i, j, Nap[j][l].Y };
          vector <int> S = T;
          sort(S.begin(), S.end());

          int ne = 0;
          for (int ind=0; ind<3; ind++)
            if (S[ind] == S[ind+1])
              ne = 1;

          if (!ne) {
            rje = sum;
            R = T;
          }
        }
      }
    }
  }

  for (auto it : R)
    printf("%d ", it + 1);
  printf("\n");

  return 0;
}
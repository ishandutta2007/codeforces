#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAXN = 10010, MAXK = 105;
const ll INF = 1e18;

ll dist[2][MAXN];
vector <P> V[MAXN], Poc[MAXN];
int poc[2], kraj;
int n, m, k;
int a[MAXK], b[MAXK], l[MAXK], r[MAXK];
int rje[MAXK];
int pravrje[MAXK];

void Dijkstra(int ind)
{
  set <P> S;
  for (int i=0; i<n; i++)
    dist[ind][i] = INF;

  dist[ind][poc[ind]] = 0;
  S.insert(P(0, poc[ind]));

  for (; !S.empty(); ) {
    auto tmp = *S.begin(); S.erase(S.begin());
    for (auto it : V[tmp.Y]) {
      ll ndist = tmp.X + it.Y;
      if (dist[ind][it.X] > ndist) {
        S.erase(P(dist[ind][it.X], it.X));
        dist[ind][it.X] = ndist;
        S.insert(P(dist[ind][it.X], it.X));
      }
    }
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d%d", &poc[0], &poc[1], &kraj); poc[0]--; poc[1]--; kraj--;

  for (int i=0; i<m; i++) {
    int aa, bb, cc;
    scanf("%d%d%d", &aa, &bb, &cc); aa--; bb--;
    Poc[aa].push_back(P(bb, cc));
  }

  for (int i=0; i<k; i++) {
    scanf("%d%d%d%d", &a[i], &b[i], &l[i], &r[i]);
    a[i]--; b[i]--;
  }

  int moze[2] = {0, 0};

  for (int st=0; st<2; st++) {
    memset(rje, 0, sizeof rje);
    for (;;) {
      for (int i=0; i<n; i++)
        V[i] = Poc[i];
      for (int i=0; i<k; i++)
        V[a[i]].push_back(P(b[i], rje[i] ? rje[i] : r[i]));

      Dijkstra(0);
      Dijkstra(1);

      int ind = -1;
      ll minn = INF;

      for (int i=0; i<k; i++) {
        if (!rje[i] && min(dist[0][a[i]], dist[1][a[i]]) < minn) {
          minn = min(dist[0][a[i]], dist[1][a[i]]);
          ind = i;
        }
      }

      if (ind == -1)
        break;

      if (dist[0][a[ind]] < dist[1][a[ind]])
        rje[ind] = l[ind];
      else if (dist[0][a[ind]] > dist[1][a[ind]])
        rje[ind] = r[ind];
      else if (!st)
        rje[ind] = r[ind];
      else
        rje[ind] = l[ind];
    }

    if (dist[0][kraj] < dist[1][kraj]) {
      moze[0] = 1;
      memcpy(pravrje, rje, sizeof rje);
    }
    else if (dist[0][kraj] == dist[1][kraj] && !moze[0]) {
      moze[1] = 1;
      memcpy(pravrje, rje, sizeof rje);
    }
  }

  if (moze[0] || moze[1]) {
    printf("%s\n", moze[0] ? "WIN" : "DRAW");
    for (int i=0; i<k; i++)
      printf("%d ", pravrje[i] ? pravrje[i] : r[i]);
    printf("\n");
  }
  else
    printf("LOSE\n");

  return 0;
}
#include <cstdio>
#include <set>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 10005, MAXN = 1005;
const ll INF = 1e15;

ll rje[MAX];
int bitan[2];
vector <P> V[MAX];
ll pravdist[2][MAX];
ll pseudodist[2][MAX];
int a[MAX], b[MAX], c[MAX];
int praze[MAXN][MAXN];
int n, m, l;
int odak[MAX];
int treba[MAX];

void Nope()
{
  printf("NO\n");
  exit(0);
}

void Dijkstra(ll dist[MAX], int odakle[MAX], int poc)
{
  set <P> S;

  for (int i=0; i<MAX; i++)
    dist[i] = INF;

  dist[poc] = 0;
  S.insert(P(0ll, (ll) poc));

  for (; !S.empty(); ) {
    P tmp = *S.begin();
    S.erase(S.begin());
    for (auto it : V[tmp.Y]) {
      ll nd = tmp.X + it.Y;
      if (nd < dist[it.X]) {
        odakle[it.X] = (int) tmp.Y;
        S.erase(P(dist[it.X], it.X));
        dist[it.X] = nd;
        S.insert(P(dist[it.X], it.X));
      }
    }
  }
}

int main()
{
  scanf("%d%d%d%d%d", &n, &m, &l, &bitan[0], &bitan[1]);

  memset(praze, -1, sizeof praze);
  for (int i=0; i<m; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    if (c[i]) {
      V[a[i]].push_back(P(b[i], c[i]));
      V[b[i]].push_back(P(a[i], c[i]));
    }
    else
      praze[a[i]][b[i]] = praze[b[i]][a[i]] = i;
  }

  Dijkstra(pravdist[0], odak, bitan[0]);
  Dijkstra(pravdist[1], odak, bitan[1]);

  if (pravdist[0][bitan[1]] < l)
    Nope();

  for (int i=0; i<m; i++) {
    if (!c[i]) {
      V[a[i]].push_back(P(b[i], 1));
      V[b[i]].push_back(P(a[i], 1));
    }
  }

  Dijkstra(pseudodist[1], odak, bitan[1]);
  Dijkstra(pseudodist[0], odak, bitan[0]);

  if (pseudodist[0][bitan[1]] > l)
    Nope();

  for (int i=0; i<n; i++)
    if (praze[i][odak[i]] != -1)
      treba[praze[i][odak[i]]] = 1;

  for (int i=0; i<m; i++)
    if (!treba[i] && c[i] == 0)
      rje[i] = INF;

  for (;;) {
    for (int i=0; i<n; i++)
      V[i].clear();

    for (int i=0; i<m; i++) {
      if (c[i] || rje[i]) {
        V[a[i]].push_back(P(b[i], max((ll) c[i], rje[i])));
        V[b[i]].push_back(P(a[i], max((ll) c[i], rje[i])));
      }
    }

    Dijkstra(pravdist[0], odak, bitan[0]);
    Dijkstra(pravdist[1], odak, bitan[1]);

    int da = 0;
    for (int i=0; i<m; i++) {
      if (!c[i] && !rje[i]) {
        ll tr = min(pravdist[0][a[i]] + pravdist[1][b[i]],
                    pravdist[1][a[i]] + pravdist[0][b[i]]);

        rje[i] = max(1ll, l - tr);
        da = 1;
        break;
      }
    }

    if (!da)
      break;
  }

  printf("YES\n");
  for (int i=0; i<m; i++)
    printf("%d %d %lld\n", a[i], b[i], c[i] ? (ll) c[i] : rje[i]);

  return 0;
}
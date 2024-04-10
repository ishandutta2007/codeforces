#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> P2;
#define X first
#define Y second

const ll INF = 1e18;
const int MAX = 2005;

int n, m, poc1, poc2;
int p[MAX], x[MAX], y[MAX];
ll dist1[MAX], dist2[MAX];
ll sor1[MAX], sor2[MAX];
set <P2> S;
vector <P> V[MAX];
ll polje[MAX][MAX];
ll pref[MAX][MAX];
int ima[MAX][MAX], imap[MAX][MAX];
ll dp[2][MAX][MAX], best[2][MAX];

void Dijkstra(int node, ll dist[MAX])
{
  dist[node] = 1;
  S.insert(P2(1, node));

  for (; !S.empty(); ) {    
    P2 tmp = *S.begin();
    S.erase(S.begin());

    for (int i=0; i<(int) V[tmp.Y].size(); i++) {
      ll nd = dist[tmp.Y] + V[tmp.Y][i].Y;
      int nn = V[tmp.Y][i].X;
      if (!dist[nn]) {
        dist[nn] = nd;
        S.insert(P2(nd, nn));
      }
      else if (nd < dist[nn]) {
        S.erase(S.find(P2(dist[nn], nn)));
        dist[nn] = nd;
        S.insert(P2(nd, nn));
      }
    }
  }
}

int Binary(int r, int s, int st)
{
  if (!st) {
    int lo = r;
    int hi = n;

    for (; lo < hi; ) {
      int mid = (lo + hi + 1) / 2;
      if (pref[mid][s] > pref[r][s])
        lo = mid;
      else
        hi = mid - 1;
    }

    return lo;
  }
  else {
    int lo = s;
    int hi = n;

    for (; lo < hi; ) {
      int mid = (lo + hi + 1) / 2;
      if (pref[r][mid] > pref[r][s])
        lo = mid;
      else
        hi = mid - 1;
    }

    return lo;
  }
}

int Ima(int r1, int r2, int s1, int s2)
{
  return imap[r2][s2] - imap[r1-1][s2] - imap[r2][s1-1] + imap[r1-1][s1-1];
}

ll Suma(int r1, int r2, int s1, int s2)
{
  return pref[r2][s2] - pref[r1-1][s2] - pref[r2][s1-1] + pref[r1-1][s1-1];
}

int main()
{
  scanf("%d%d%d%d", &n, &m, &poc1, &poc2); poc1--; poc2--;

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    V[a].push_back(P(b, c));
    V[b].push_back(P(a, c));
  }

  Dijkstra(poc1, dist1);
  Dijkstra(poc2, dist2);

  memcpy(sor1, dist1, sizeof dist1);
  memcpy(sor2, dist2, sizeof dist2);
  sort(sor1, sor1 + n);
  sort(sor2, sor2 + n);

  for (int i=0; i<n; i++) {
    x[i] = lower_bound(sor1, sor1 + n, dist1[i]) - sor1 + 1;
    y[i] = lower_bound(sor2, sor2 + n, dist2[i]) - sor2 + 1;
    polje[x[i]][y[i]] += p[i];
    ima[x[i]][y[i]]++;
  }

  for (int i=1; i<MAX; i++) {
    ll sum = 0;
    int ss = 0;
    for (int j=1; j<MAX; j++) {
      sum += polje[i][j];
      pref[i][j] = sum + pref[i-1][j];
      ss += ima[i][j];
      imap[i][j] = ss + imap[i-1][j];
    }
  }

  for (int i=0; i<2; i++)
    for (int j=0; j<MAX; j++)
      best[i][j] = INF;

  for (int i=MAX-2; i; i--) {
    for (int j=MAX-2; j; j--) {
      if (!Ima(i, i, j, MAX-1))
        dp[0][i][j] = dp[0][i+1][j];
      else
        dp[0][i][j] = Suma(i, MAX-1, j, MAX-1) - best[0][j];

      if (!Ima(i, MAX-1, j, j))
        dp[1][i][j] = dp[1][i][j+1];
      else
        dp[1][i][j] = Suma(i, MAX-1, j, MAX-1) - best[1][i];

      best[0][j] = min(best[0][j], dp[1][i][j] + Suma(i, MAX-1, j, MAX-1));
      best[1][i] = min(best[1][i], dp[0][i][j] + Suma(i, MAX-1, j, MAX-1));
    }
  }

  if (dp[0][1][1] > 0)
    printf("Break a heart\n");
  else if (dp[0][1][1] < 0)
    printf("Cry\n");
  else
    printf("Flowers\n");

  return 0;
}
#include <cstdio>
#include <ctime>
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

const int MAX = 55, INF = 0x3f3f3f3f;
const double TL = 1.9;

int n, brojmed;
int poce[MAX][MAX];
int e[MAX][MAX];
int bio[MAX], kol[MAX];

int Bfs()
{
  memset(bio, INF, sizeof bio);
  queue <int> Q;
  Q.push(0);
  bio[0] = -1;
  kol[0] = INF;

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();
    
    if (tmp == n - 1)
      return kol[tmp];

    for (int i=0; i<n; i++) {
      if (e[tmp][i] && bio[i] == INF) {
        bio[i] = tmp;
        kol[i] = min(e[tmp][i], kol[tmp]);
        Q.push(i);
      }
    }
  }

  return 0;
}

int Flow()
{
  int ret = 0;
  for (;;) {
    int tmp = Bfs();
    if (!tmp)
      return ret;

    ret += tmp;
    if (ret >= brojmed)
      return ret;

    for (int node=n-1; node; ) {
      int prije = bio[node];
      e[prije][node] -= tmp;
      e[node][prije] += tmp;
      node = prije;
    }
  }

  return -1;
}

int Moze(double val)
{
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      e[i][j] = (int) min((double) 1e5, poce[i][j] / val);
  
  return Flow() >= brojmed;
}

int main()
{
  int bre;

  scanf("%d%d%d", &n, &bre, &brojmed);

  for (int i=0; i<bre; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    poce[a][b] = c;
  }

  double lo = 0, hi = 1e9;

  for (int i=0; i<100 && (double) clock() / CLOCKS_PER_SEC < TL; i++) {
    double mid = (lo + hi) / 2;
    if (Moze(mid))
      lo = mid;
    else
      hi = mid;
  }

  printf("%.10lf\n", lo * brojmed);

  return 0;
}
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define TRACE(x) cerr << #x << " " << x << endl;

#define X first
#define Y second


using namespace std;

typedef long long ll;
typedef pair <int, int> P;

const int LOG = 17, MAX = 1<<LOG;
const ll INF = 100000000000000000ll;

ll dist[MAX], distup[MAX], distdown[MAX];
int leaf[MAX];
int lca[MAX][LOG];
int p[MAX];
int n, root;
ll rje;
vector <P> V[MAX];

ll DfsDown(int node, int prosli)
{
  if (V[node].size() == 1)
    leaf[node] = 1;

  for (int i=0; i<(int) V[node].size(); i++) {
    P nn = V[node][i];
    if (nn.X != prosli)
      distdown[node] = max(distdown[node], nn.Y + DfsDown(nn.X, node));
  }

  return distdown[node];
}

void DfsUp(int node, int prosli)
{
  ll dosad = distup[node];
  for (int i=0; i<(int) V[node].size(); i++) {
    P nn = V[node][i];
    if (nn.X != prosli) {
      distup[nn.X] = max(distup[nn.X], dosad + nn.Y);
      dosad = max(dosad, distdown[nn.X] + nn.Y);
    }
  }

  dosad = distup[node];
  for (int i=(int) V[node].size()-1; i>=0; i--) {
    P nn = V[node][i];
    if (nn.X != prosli) {
      distup[nn.X] = max(distup[nn.X], dosad + nn.Y);
      dosad = max(dosad, distdown[nn.X] + nn.Y);
    }
  }

  for (int i=0; i<(int) V[node].size(); i++) {
    P nn = V[node][i];
    if (nn.X != prosli)
      DfsUp(nn.X, node);
  }

  dist[node] = max(distdown[node], distup[node]);
}

void DfsLca(int node, int prosli)
{
  lca[node][0] = prosli;
  for (int i=1; i<LOG; i++)
    if (lca[node][i-1] != -1)
      lca[node][i] = lca[lca[node][i-1]][i-1];

  for (int i=0; i<(int) V[node].size(); i++) {
    P nn = V[node][i];
    if (nn.X != prosli)
      DfsLca(nn.X, node);
  }
}

void Postavi(ll val)
{
  memset(p, 0, sizeof p);

  for (int i=0; i<n; i++) {
    p[i]++;
    int node = i;
    for (int j=LOG-1; j>=0; j--)
      if (lca[node][j] != -1 && dist[i] - dist[lca[node][j]] <= val)
        node = lca[node][j];
    if (node == root)
      continue;
    p[lca[node][0]]--;
  }
}

ll DfsRje(int node, int prosli)
{
  ll sum = p[node];

  for (int i=0; i<(int) V[node].size(); i++) {
    P nn = V[node][i];
    if (nn.X != prosli)
      sum += DfsRje(nn.X, node);    
  }

  rje = max(rje, sum);
  return sum;
}

int main()
{
  int q;

  scanf("%d", &n);

  for (int i=0; i<n-1; i++) {
    int a, b, v;
    scanf("%d%d%d", &a, &b, &v); a--; b--;
    V[a].push_back(P(b, v));
    V[b].push_back(P(a, v));
  }

  DfsDown(0, -1);
  DfsUp(0, -1);
  
  ll minn = INF;

  for (int i=0; i<n; i++) {
    if (dist[i] < minn) {
      minn = dist[i];
      root = i;
    }
  }
  
  memset(lca, -1, sizeof lca);
  DfsLca(root, -1);
  
  scanf("%d", &q);
  for (int i=0; i<q; i++) {
    ll val;
    cin >> val;
    Postavi(val);
    rje = 0;
    DfsRje(root, -1);
    cout << rje << endl;
  }

  return 0;
}
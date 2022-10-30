#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 3005;

struct edge {
  int node, val, ind;
};

vector <edge> V[MAX];
int aa[MAX], bb[MAX], cc[MAX];
int zab[MAX];
int bio[MAX];
int p[MAX];

P DfsMax(int node)
{
  if (bio[node]++)
    return P(-1, -1);

  P ret = P(-1, -1);
  for (auto it : V[node]) {
    if (!zab[it.ind]) {
      ret = max(ret, P(it.val, it.ind));
      ret = max(ret, DfsMax(it.node));
    }
  }
  
  return ret;
}

P DfsSum(int node)
{
  if (bio[node]++)
    return P(0, 0);

  P ret = P(1, p[node]);

  for (auto it : V[node])
    if (!zab[it.ind]) {
      P tmp = DfsSum(it.node);
      ret.X += tmp.X;
      ret.Y += tmp.Y;
    }

  return ret;
}

int Rek(int node, int kol)
{
  memset(bio, 0, sizeof bio);
  int e = DfsMax(node).Y;
  zab[e] = 1;

  memset(bio, 0, sizeof bio);
  P suml = DfsSum(aa[e]);
  P sumr = DfsSum(bb[e]);

  if (suml.X < sumr.X) {
    swap(suml, sumr);
    swap(aa[e], bb[e]);
  }

  int nkol = kol - (min(suml.X, sumr.Y) + min(sumr.X, suml.Y));

  if (nkol <= 0)
    return cc[e];

  return Rek(aa[e], nkol);
}

int main()
{
  int n;

  scanf("%d", &n);
  if (n == 1) {
    printf("0\n");
    return 0;
  }

  for (int i=0; i<n-1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    aa[i] = a; bb[i] = b; cc[i] = c;
    V[a].push_back(edge{b, c, i});
    V[b].push_back(edge{a, c, i});
  }

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  printf("%d\n", Rek(0, n));

  return 0;
}
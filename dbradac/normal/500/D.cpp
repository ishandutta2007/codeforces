#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1<<17;

struct str {
  int node, val;
  str (int node, int val) : node(node), val(val) {}
  str () {}
};

vector <str> V[MAX];
int subtree[MAX];
int a[MAX], b[MAX], c[MAX];
int dub[MAX];
int n;
double rje, povrh;

int Dfs(int node, int prosli, int gornji)
{
  if (prosli != -1)
    dub[node] = dub[prosli] + 1;

  subtree[node] = 1;
  for (int i=0; i<(int) V[node].size(); i++)
    if (V[node][i].node != prosli)
      subtree[node] += Dfs(V[node][i].node, node, V[node][i].val);

  rje += (double) gornji * (double) subtree[node] * ((double) n - subtree[node]) / povrh;
  return subtree[node];
}

int main()
{
  int q;

  scanf("%d", &n);

  for (int i=0; i<n-1; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]); a[i]--; b[i]--;
    V[a[i]].push_back(str(b[i], c[i]));
    V[b[i]].push_back(str(a[i], c[i]));
  }

  povrh = (double) n * (n-1) / 6;

  Dfs(0, -1, 0);
  
  scanf("%d", &q);

  for (int i=0; i<q; i++) {
    int ind, novi;
    scanf("%d%d", &ind, &novi); ind--;
    int tmp;
    if (dub[a[ind]] > dub[b[ind]])
      tmp = a[ind];
    else
      tmp = b[ind];
    rje -= (c[ind] - novi) * (double) subtree[tmp] * ((double) n - subtree[tmp]) / povrh;
    c[ind] = novi;
    printf("%lf\n", rje);
  }


  return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 6005;

int p[MAX], sor[MAX], rje;
short dpup[MAX][MAX], dpdown[MAX][MAX];
vector <int> V[MAX];

void Rek(int node, int prosli)
{
  for (vector <int> :: iterator it=V[node].begin(); it!=V[node].end(); it++)
    if (*it!=prosli)
      Rek(*it, node);

  for (vector <int> :: iterator it=V[node].begin(); it!=V[node].end(); it++) {
    if (*it != prosli) {
      for (int i=1; i<MAX; i++) { //dpdown[*it]
        rje = max(rje, dpup[node][i-1] + dpdown[*it][i]);
        if (i > p[node])
          rje = max(rje, dpup[node][p[node]-1] + dpdown[*it][i] + 1);
      }
      for (int i=1; i<MAX; i++) { //dpup[*it]
        rje = max(rje, dpdown[node][i+1] + dpup[*it][i]);
        if (i < p[node])
          rje = max(rje, dpdown[node][p[node]+1] + dpup[*it][i] + 1);
      }
      for (int i=MAX-1; i; i--)
        dpdown[node][i] = max(dpdown[node][i], max(dpdown[*it][i], dpdown[node][i+1]));
      for (int i=1; i<MAX; i++)
        dpup[node][i] = max(dpup[node][i], max(dpup[*it][i], dpup[node][i-1]));
    }
  }

  for (int i=p[node]+1; i<MAX; i++)
    dpdown[node][p[node]] = max(dpdown[node][p[node]], (short) (dpdown[node][i] + 1));
  
  for (int i=1; i<p[node]; i++)
    dpup[node][p[node]] = max(dpup[node][p[node]], (short) (dpup[node][i] + 1));

  for (int i=1; i<MAX; i++)
    rje = max(rje, (int) (max(dpdown[node][i], dpup[node][i])));
}

int main()
{
  int n;

  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    sor[i] = p[i];
  }

  sort(sor+1, sor+n+1);

  for (int i=1; i<=n; i++)
    p[i] = upper_bound(sor+1, sor+n+1, p[i]) - sor;

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].push_back(b);
    V[b].push_back(a);
  }

  Rek(1, -1);

  printf("%d\n", rje);

  return 0;
}
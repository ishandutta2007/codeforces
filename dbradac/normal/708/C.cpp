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

const int MAX = 1<<19;

vector <int> V[MAX];
int sub[MAX];
int par[MAX];
int kol[MAX];

int DfsSub(int node, int prosli)
{
  sub[node] = 0;
  par[node] = prosli;
  for (auto it : V[node])
    if (it != prosli)
      sub[node] += DfsSub(it, node);

  return ++sub[node];
}

void DfsMetni(int node, int prosli, int val)
{
  kol[node] = val;
  for (auto it : V[node])
    if (it != prosli)
      DfsMetni(it, node, val);
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  DfsSub(0, -1);

  int centr = -1;
  for (int i=0; i<n; i++) {
    int da = 1;
    if ((n - sub[i]) * 2 > n)
      da = 0;

    for (auto it : V[i])
      if (sub[it] * 2 > n && it != par[i])
        da = 0;

    if (da) {
      if (centr != -1) {
        for (int j=0; j<n; j++)
          printf("1 ");
        printf("\n");
        return 0;
      }
      centr = i;
    }
  }

  DfsSub(centr, -1);

  int mx = -1, ind = -1;

  for (auto it : V[centr]) {
    if (sub[it] > mx) {
      mx = sub[it];
      ind = it;
    }
  }

  int mx2 = 0;
  for (auto it : V[centr])
    if (sub[it] > mx2 && ind != it)
      mx2 = sub[it];

  TRACE(mx);

  for (auto it : V[centr]) {
    if (it == ind)
      DfsMetni(it, centr, mx2);
    else
      DfsMetni(it, centr, mx);
  }

  for (int i=0; i<n; i++) {
    int st = 0;
    if (i == centr)
      st = 1;

    int ost = (n - sub[i]) - kol[i];
    if (ost * 2 <= n)
      st = 1;

    printf("%d ", st);
  }
  printf("\n");

  return 0;
}
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

const int MAX = 1<<17;

P e[MAX];
vector <int> V[MAX];
int bio[MAX];
int n;

int Dfs(int node)
{
  if (bio[node])
    return bio[node];

  int ret = 1;
  for (auto it : V[node])
    ret = max(ret, 1 + Dfs(it));

  return bio[node] = ret;
}

int Moze(int mid)
{
  memset(bio, 0, sizeof bio);

  for (int i=0; i<n; i++)
    V[i].clear();

  for (int i=0; i<mid; i++)
    V[e[i].X].push_back(e[i].Y);

  for (int i=0; i<n; i++)
    if (!bio[i])
      Dfs(i);

  for (int i=0; i<n; i++)
    if (bio[i] == n)
      return 1;

  return 0;
}

int main()
{
  int m;

  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++) {
    scanf("%d%d", &e[i].X, &e[i].Y);
    e[i].X--;
    e[i].Y--;
  }

  int lo = 1, hi = m + 1;
  for (; lo < hi; ) {
    int mid = (lo + hi) / 2;
    if (Moze(mid))
      hi = mid;
    else
      lo = mid + 1;
  }

  printf("%d\n", lo == m + 1 ? -1 : lo);

  return 0;
}
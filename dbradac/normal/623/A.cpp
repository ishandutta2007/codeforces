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

const int MAX = 505;

int e[MAX][MAX];
int bio[MAX];
int n, m;
char rje[MAX];

void Nope()
{
  printf("No\n");
  exit(0);
}

void Dfs(int node, int st)
{
  if (bio[node] != -1) {
    if (bio[node] != st)
      Nope();
    return;
  }

  bio[node] = st;
  for (int i=0; i<n; i++)
    if (i != node && e[node][i])
      Dfs(i, 1^st);
}

int main()
{
  memset(bio, -1, sizeof bio);
  scanf("%d%d", &n, &m);

  for (int i=0; i<MAX; i++)
    for (int j=0; j<MAX; j++)
      e[i][j] = 1;

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    e[a][b] = e[b][a] = 0;
  }

  for (int i=0; i<n; i++)
    if (bio[i] == -1)
      Dfs(i, 0);

  for (int i=0; i<n; i++) {
    int da=1;
    for (int j=0; j<n; j++)
      if (e[i][j] && i != j)
        da = 0;

    if (da) {
      rje[i] = 'b';
      continue;
    }

    if (bio[i] == 0)
      rje[i] = 'a';
    else
      rje[i] = 'c';
  }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if (rje[i] != 'b' && rje[j] != 'b' && rje[i] != rje[j] && !e[i][j])
        Nope();

  printf("Yes\n");
  printf("%s\n", rje);

  return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 20005, MAXN = 205, S = 0, T = 201;

int p[MAXN];
int sito[MAX];
int edge[MAXN][MAXN];
int doso[MAXN], bio[MAXN];
int n;
vector <int> R[MAXN];
  
int Dfs(int node, int protok)
{
  bio[node] = 1;
  
  if (node == T)
    return protok;

  for (int i=0; i<MAXN; i++)
    if (edge[node][i] && !bio[i]) {
      doso[i] = node;
      int tmp = Dfs(i, min(protok, edge[node][i]));
      if (tmp)
        return tmp;
    }

  return 0;
}

void Flow()
{
  int rje=0;

  for (;;) {
    memset(bio, 0, sizeof bio);
    int tmp = Dfs(S, MAX);
    if (!tmp)
      break;
    rje += tmp;

    for (int node=T; node != S;) {
      int od = doso[node];
      edge[od][node] -= tmp;
      edge[node][od] += tmp;
      node = od;
    }
  }

  if (rje != n) {
    printf("Impossible\n");
    return;
  }

  memset(bio, 0, sizeof bio);

  int ind=0;

  for (int i=1; i<=n; i++) {
    if (!bio[i]) {      
      R[ind].push_back(i);
      bio[i] = 1;

      for (int node=i;;) {
        int da = 0;
        for (int j=1; j<=n; j++) {
          int st;
          if (p[node] & 1)
            st = edge[node][j];
          else
            st = edge[j][node];

          if (!sito[p[node] + p[j]] && !st && !bio[j]) {
            da = 1;
            R[ind].push_back(j);
            bio[j] = 1;
            node = j;
            break;
          }
        }
        if (!da)
          break;
      }
      ind++;
    }
  }

  printf("%d\n", ind);
  for (int i=0; i<ind; i++) {
    printf("%u ", R[i].size());
    for (int j=0; j<(int) R[i].size(); j++)
      printf("%d ", R[i][j]);
    printf("\n");
  }
}


int main()
{
  for (int i=2; i<MAX; i++)
    if (!sito[i])
      for (int j=2*i; j<MAX; j+=i)
        sito[j] = 1;

  scanf("%d", &n);

  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    if (p[i] & 1)
      edge[S][i] = 2;
    else
      edge[i][T] = 2;
  }
  
  for (int i=1; i<=n; i++)
    if (p[i] & 1)
     for (int j=1; j<=n; j++)
       if (!sito[p[i] + p[j]])
         edge[i][j] = 1;

  Flow();

  return 0;
}
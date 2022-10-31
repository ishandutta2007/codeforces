#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 305;

char s[MAX][MAX];
int poc[MAX], poz[MAX];
int rje[MAX];
int bio[MAX];
int zauzeto[MAX];
int n;
vector <int> V[MAX];

void Dfs(int komp, int node)
{
  bio[node] = komp;
  V[komp].push_back(node);
  
  for (int i=0; i<n; i++)
    if (s[node][i] == '1' && bio[i] == -1)
      Dfs(komp, i);
}

int main()
{
  int komp=0;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &poc[i]);
    poz[poc[i]] = i;
  }

  for (int i=0; i<n; i++)
    scanf("%s", s[i]);

  memset(bio, -1, sizeof bio);

  for (int i=0; i<n; i++) {
    if (bio[i] == -1) {
      Dfs(komp, i);
      komp++;
    }
  }

  for (int i=0; i<komp; i++)
    sort(V[i].begin(), V[i].end());

  for (int i=1; i<=n; i++) {
    int tkomp = bio[poz[i]];
    for (int j=0; j<(int)V[tkomp].size(); j++)
      if (!zauzeto[V[tkomp][j]]) {
        rje[V[tkomp][j]] = i;
        zauzeto[V[tkomp][j]] = 1;
        break;
      }
  }

  for (int i=0; i<n; i++)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

const int MAX = 1<<17;

vector <pii> V[MAX][2];
map <int, int> M;
int p[MAX];
int n, a, b;
vector <int> Vrati;
int bio[MAX];

int Dfs(int node, int val)
{
  if (bio[node] != -1)
    return bio[node] == val;

  bio[node] = val;
  Vrati.push_back(node);

  for (int i=0; i<(int) V[node][val].size(); i++)
    if (!Dfs(V[node][val][i].first, V[node][val][i].second))
      return 0;
  return 1;
}

int Rijesi()
{
  memset(bio, -1, sizeof bio);

  for (int i=1; i<=n; i++) {
    if (bio[i] == -1) {
      Vrati.clear();
      if (!Dfs(i, 0)) {
        for (int j=0; j<(int) Vrati.size(); j++)
          bio[Vrati[j]] = -1;
        Vrati.clear();
        if (!Dfs(i, 1))
          return 0;
        Vrati.clear();
      }
      Vrati.clear();
    }
  }
  
  return 1;
}

int main() {

  scanf("%d%d%d", &n, &a, &b);

  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    M[p[i]] = i;
  }

  for (int i=1; i<=n; i++) {
    if (M[a - p[i]]) {
      V[i][0].push_back(pii(M[a - p[i]], 0));
      V[i][1].push_back(pii(M[a - p[i]], 1));
    }
    else
      V[i][0].push_back(pii(i, 1));

    if (M[b - p[i]]) {
      V[i][1].push_back(pii(M[b - p[i]], 1));
      V[i][0].push_back(pii(M[b - p[i]], 0));
    }
    else
      V[i][1].push_back(pii(i, 0));
  }

  if (Rijesi()) {
    printf("YES\n");
    for (int i=1; i<=n; i++)
      printf("%d ", bio[i]);
    printf("\n");
  }
  else
    printf("NO\n");

  return 0;
}
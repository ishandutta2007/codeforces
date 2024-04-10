#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

#define X first
#define Y second

using namespace std;

const int MAX = 100005, KOR = 317;

vector <pair<int, int> > E[MAX];

vector <int> V[MAX];
vector <int> T, K;
map < pair<int, int>, int> M;
map < pair<int, int>, int> Q;
int qa[MAX], qb[MAX], isti[MAX];
int urank[MAX], root[MAX];
int bio[MAX];

int Find(int x)
{
  if (root[x] == -1)
    return x;
  return root[x] = Find(root[x]);
}

void Union(int a, int b)
{
  a = Find(a);
  b = Find(b);
  
  if (a != b) {
    if (urank[a] < urank[b])
      root[a] = b;
    else if (urank[a] > urank[b])
      root[b] = a;
    else {
      root[b] = a;
      urank[a]++;
    }
  }
}

void Dfs(int node)
{
  bio[node] = 1;
  K.push_back(node);

  for (int i=0; i<(int) V[node].size(); i++)
    if (!bio[V[node][i]])
      Dfs(V[node][i]);
}

int main()
{
  int n, bre, brq;

  scanf("%d%d", &n, &bre);

  for (int i=0; i<bre; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    E[c].push_back(make_pair(a, b));
  }
  
  scanf("%d", &brq);

  for (int i=0; i<brq; i++) {
    scanf("%d%d", &qa[i], &qb[i]);
    if (qa[i] > qb[i])
      swap(qa[i], qb[i]);
    if (!Q[make_pair(qa[i], qb[i])])
      Q[make_pair(qa[i], qb[i])] = 1;
    else
      isti[i] = 1;
  }

  for (int i=1; i<MAX; i++) {
    if ((int) E[i].size() > KOR) {
      memset(root, -1, sizeof root);
      memset(urank, 0, sizeof urank);

      for (int j=0; j<(int) E[i].size(); j++)
        Union(E[i][j].X, E[i][j].Y);

      for (int j=0; j<brq; j++)
        if (!isti[j] && Find(qa[j]) == Find(qb[j]))
          M[make_pair(qa[j], qb[j])]++;
    }
    else {
      for (int j=0; j<(int) E[i].size(); j++) {
        V[E[i][j].X].push_back(E[i][j].Y);
        V[E[i][j].Y].push_back(E[i][j].X);
        T.push_back(E[i][j].X);
        T.push_back(E[i][j].Y);
      }
      
      for (int j=0; j<(int) T.size(); j++) {
        if (!bio[T[j]]) {
          K.clear();
          Dfs(T[j]);
          
          sort(K.begin(), K.end());

          for (int k=0; k<(int) K.size(); k++)
            for (int l=k+1; l<(int) K.size(); l++)
              M[make_pair(K[k], K[l])]++;
        }
      }

      for (int j=0; j<(int) T.size(); j++) {
        V[T[j]].clear();
        bio[T[j]] = 0;
      }
      T.clear();
    }
  }

  for (int i=0; i<brq; i++)
    printf("%d\n", M[make_pair(qa[i], qb[i])]);

  return 0;
}
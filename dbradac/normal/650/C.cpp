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

const int MAX = 1000100;

int p[MAX];
int urank[MAX], root[MAX];
int rje[MAX];
int bio[MAX];
vector <int> V[MAX];

int Find(int x)
{
  if (root[x] == -1)
    return x;
  return root[x] = Find(root[x]);
}

void Spoji(int a, int b)
{
  a = Find(a);
  b = Find(b);

  if (a == b)
    return;

  if (urank[a] > urank[b])
    root[b] = a;
  else if (urank[b] > urank[a])
    root[a] = b;
  else {
    urank[a]++;
    root[b] = a;
  }
}

void ObradiPoc(vector<P> &T)
{
  sort(T.begin(), T.end());

  for (int i=0; i<(int) T.size()-1; i++)
    if (T[i].X == T[i+1].X)
      Spoji(T[i].Y, T[i+1].Y);
}

void ObradiKraj(vector<P> &T)
{
  sort(T.begin(), T.end());

  for (int i=0; i<(int) T.size()-1; i++)
    if (T[i].X < T[i+1].X)
      V[Find(T[i+1].Y)].push_back(Find(T[i].Y));
}

int Dfs(int node)
{
  if (bio[node] != -1)
    return bio[node];

  int ret = 0;
  for (int i=0; i<(int) V[node].size(); i++)
    ret = max(ret, Dfs(V[node][i]) + 1);

  return bio[node] = ret;
}


int main()
{
  memset(root, -1, sizeof root);

  int brred, brstup;
  scanf("%d%d", &brred, &brstup);

  for (int i=0; i<brred; i++)
    for (int j=0; j<brstup; j++)
      scanf("%d", &p[i*brstup+j]);

  for (int i=0; i<brred; i++) {
    vector <P> T;
    for (int j=0; j<brstup; j++)
      T.push_back(P(p[i*brstup+j], i*brstup + j));

    ObradiPoc(T);
  }

  for (int j=0; j<brstup; j++) {
    vector <P> T;
    for (int i=0; i<brred; i++)
      T.push_back(P(p[i*brstup+j], i*brstup + j));

    ObradiPoc(T);
  }

  for (int i=0; i<brred; i++) {
    vector <P> T;
    for (int j=0; j<brstup; j++)
      T.push_back(P(p[i*brstup+j], i*brstup + j));

    ObradiKraj(T);
  }

  for (int j=0; j<brstup; j++) {
    vector <P> T;
    for (int i=0; i<brred; i++)
      T.push_back(P(p[i*brstup+j], i*brstup + j));

    ObradiKraj(T);
  }

  memset(bio, -1, sizeof bio);
  for (int i=0; i<MAX; i++)
    if (bio[i] == -1)
      Dfs(i);

  for (int i=0; i<brred*brstup; i++)
    rje[i] = bio[Find(i)] + 1;

  for (int i=0; i<brred; i++) {
    for (int j=0; j<brstup; j++)
      printf("%d ", rje[i*brstup+j]);
    printf("\n");
  }

  return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int TOUR = 1<<17, TOURK = 10, LOG = 18;

vector <int> Merge(vector <int> &A, vector <int> &B)
{
  vector <int> R;

  int ia = 0, ib = 0;
  for (; (ia < (int) A.size() || ib < (int) B.size()) && R.size() < TOURK; ) {
    if (ia == (int) A.size())
      R.push_back(B[ib++]);
    else if (ib == (int) B.size())
      R.push_back(A[ia++]);
    else if (A[ia] < B[ib])
      R.push_back(A[ia++]);
    else
      R.push_back(B[ib++]);
  }

  return R;
}

int p[TOUR];
int root[TOUR], poz[TOUR], dub[TOUR], subtree[TOUR], par[TOUR];
int vrijeme;
int brnode, brcov;
int lca[TOUR][LOG];
vector <int> V[TOUR];
vector <int> L[TOUR][LOG];
vector <int> Node[TOUR];

void Dfs(int node, int prosli)
{
  vector <int> Prazan;

  dub[node] = dub[prosli] + 1;
  lca[node][0] = prosli;
  L[node][0] = Merge(Node[node], Prazan);

  for (int i=1; i<LOG; i++) {
    lca[node][i] = lca[lca[node][i-1]][i-1];
    L[node][i] = Merge(L[node][i-1], L[lca[node][i-1]][i-1]);
  }

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli)
      Dfs(nn, node);
  }
}

vector <int> Query(int a, int b)
{
  vector <int> R;

  if (dub[a] > dub[b])
    swap(a, b);

  for (int i=0, raz=dub[b]-dub[a]; raz; raz/=2, i++) {
    if (raz & 1) {
      R = Merge(R, L[b][i]);
      b = lca[b][i];
    }
  }

  if (a == b) {
    R = Merge(R, L[a][0]);
    return R;
  }

  for (int i=LOG-1; i>=0; i--) {
    if (lca[a][i] != lca[b][i]) {
      R = Merge(R, L[a][i]);
      R = Merge(R, L[b][i]);
      a = lca[a][i];
      b = lca[b][i];
    }
  }

  R = Merge(R, L[b][0]);
  R = Merge(R, L[a][1]);

  return R;
}

int main()
{
  int q;

  scanf("%d%d%d", &brnode, &brcov, &q);

  for (int i=0; i<brnode-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  for (int i=0; i<brcov; i++) {
    int tmp;
    scanf("%d", &tmp); tmp--;
    Node[tmp].push_back(i);
  }

  Dfs(0, 0);

/*  for (int i=0; i<brnode; i++) {
    for (int j=0; j<2; j++) {
      for (int k=0; k<(int) L[i][j].size(); k++)
        printf("%d ", L[i][j][k]);
      printf("\n");
    }
    printf("\n\n");
  }*/

  for (int i=0; i<q; i++) {
    int a, b, kol;
    scanf("%d%d%d", &a, &b, &kol); a--; b--;
    vector <int> T = Query(a, b);

    kol = min(kol, (int) T.size());
    printf("%d ", kol);
    for (int j=0; j<kol; j++)
      printf("%d ", T[j] + 1);
    printf("\n");
  }

  return 0;
}
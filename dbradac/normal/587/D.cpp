#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 50100, KOR = 100;

vector <int> Vgraf[MAX];
vector <P> V[3*MAX][2]; //2SAT
map <int, vector<int> > M[MAX]; //boje
vector <int> Vr;
int t[3*MAX];
int val[3*MAX];
int ea[MAX], eb[MAX];
int n, m, inde;

void Nope()
{
  printf("No\n");
  exit(0);
}

void UbaciEdge(int a, int sta, int b, int stb)
{
  V[a][sta ^ 1].push_back(P(b, stb));
  V[b][stb ^ 1].push_back(P(a, sta));
}

void PobacajSve(vector <int> &T, int ind)
{
  for (int i=0; i<(int) T.size(); i++)
    UbaciEdge(T[i], 1, ind, 0);

  for (int i=0; i<(int) T.size(); i++)
    for (int j=i+1; j<(int) T.size(); j++)
      UbaciEdge(T[i], 1, T[j], 1);
}

int Dfs(int node, int st, int x)
{
  if (val[node] != -1)
    return val[node] == st;

  if (!st && t[node] > x)
    return 0;

  val[node] = st;
  Vr.push_back(node);

  for (int i=0; i<(int) V[node][st].size(); i++) {
    P tmp = V[node][st][i];
    if (!Dfs(tmp.X, tmp.Y, x))
      return 0;
  }

  return 1;
}

int Moze(int x)
{
  memset(val, -1, sizeof val);

  for (int i=0; i<inde; i++) {
    if (val[i] != -1)
      continue;

    Vr.clear();
    if (!Dfs(i, 1, x)) {
      for (int j=0; j<(int) Vr.size(); j++)
        val[Vr[j]] = -1;

      Vr.clear();
      if (t[i] > x || !Dfs(i, 0, x))
        return 0;
    }
  }

  return 1;
}

int main()
{
  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int c;
    scanf("%d%d%d%d", &ea[i], &eb[i], &c, &t[i]); ea[i]--; eb[i]--;
    M[ea[i]][c].push_back(i);
    M[eb[i]][c].push_back(i);
    Vgraf[ea[i]].push_back(i);
    Vgraf[eb[i]].push_back(i);
  }

  for (int i=0; i<n; i++) {
    for (map<int, vector<int> > :: iterator it = M[i].begin(); it != M[i].end(); it++) {
      if (it->Y.size() > 2)
        Nope();
      if (it->Y.size() == 2)
        UbaciEdge(it->Y[0], 0, it->Y[1], 0);
    }
  }
  
  inde = m;
  for (int i=0; i<n; i++) {
    vector <int> T;
    int poc = inde;
    for (int j=0; j<(int) Vgraf[i].size(); j++) {
      if (j && !(j % KOR)) {
        PobacajSve(T, inde++);
        T.clear();
      }

      T.push_back(Vgraf[i][j]);
    }

    PobacajSve(T, inde++);

    for (int j=poc; j<inde; j++)
      for (int k=j+1; k<inde; k++)
        UbaciEdge(j, 1, k, 1);
  }


  int lo=0, hi=1e9 + 5;
  for (; lo<hi; ) {
    int mid = (lo + hi) / 2;
    if (Moze(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  
  if (lo > (1e9))
    Nope();
  Moze(lo);

  printf("Yes\n");
  vector <int> T;
  for (int i=0; i<m; i++)
    if (!val[i])
      T.push_back(i + 1);

  printf("%d %d\n", lo, (int) T.size());
  for (int i=0; i<(int) T.size(); i++)
    printf("%d ", T[i]);
  printf("\n");

  return 0;
}
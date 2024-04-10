#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef long long ll;

struct raz {
  int broj, naz;
  raz (int _broj, int _naz) : broj(_broj), naz(_naz) {}
  raz () {}
};

bool operator < (raz a, raz b)
{
  return ((ll) a.broj * b.naz) < ((ll) b.broj * a.naz);
}

struct str {
  int node;
  raz r;
  str (int _node, raz _r) : node(_node), r(_r) {}
  str () {}
};

bool operator < (str a, str b)
{
  if (a.r < b.r)
    return 1;
  if (b.r < a.r)
    return 0;
  return a.node < b.node;
}

const int MAX = 100050;

vector <int> V[MAX];
int brfor[MAX];
int isfor[MAX], pocfor[MAX];
set <str> S;
raz rje = raz(0, 1);
int n, m, brf;

void Ispis()
{
  int br = 0;

  for (int i=0; i<n; i++)
    if (!isfor[i])
      br++;

  printf("%d\n", br);
  for (int i=0; i<n; i++)
    if (!isfor[i])
      printf("%d ", i + 1);

  printf("\n");
}

void Rijesi(int ispis)
{
  S.clear();

  for (int i=0; i<n; i++)
    isfor[i] = pocfor[i];
  
  memset(brfor, 0, sizeof brfor);

  for (int i=0; i<n; i++) {
    if (!isfor[i]) {
      for (int j=0; j<(int) V[i].size(); j++)
        brfor[i] += isfor[V[i][j]];

      S.insert(str(i, raz((int) V[i].size() - brfor[i], (int) V[i].size())));
    }
  }

  for (; !S.empty(); ) {
    set <str> :: iterator it = S.begin();

    if (!ispis) {
      if (rje < it->r)
        rje = it->r;
    }
    else if (!(it->r < rje)) {
      Ispis();
      return;
    }

    isfor[it->node] = 1;
    for (int i=0; i<(int) V[it->node].size(); i++) {
      int nn = V[it->node][i];
      if (!isfor[nn]) {
        S.erase(str(nn, raz((int) V[nn].size() - brfor[nn], (int) V[nn].size())));
        brfor[nn]++;
        S.insert(str(nn, raz((int) V[nn].size() - brfor[nn], (int) V[nn].size())));
      }
    }

    S.erase(it);
  }
}


int main()
{
  scanf("%d%d%d", &n, &m, &brf);

  for (int i=0; i<brf; i++) {
    int tmp;
    scanf("%d", &tmp); tmp--;
    isfor[tmp] = pocfor[tmp] = 1;
  }

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);    
  }

  Rijesi(0);
  Rijesi(1);

  return 0;
}
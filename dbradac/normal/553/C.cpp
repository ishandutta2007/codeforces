#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
map <P, int> M;

const int MAX = 100050, MOD = 1e9 + 7;

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

vector <int> V[MAX], N[MAX];
int komp[MAX];
int strana[MAX];
int rje = 1;

void Dfs(int node)
{
  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (!strana[nn]) {
      strana[nn] = strana[node];
      Dfs(nn);
    }
    else if (strana[nn] != strana[node])
      rje = 0;
  }

  for (int i=0; i<(int) N[node].size(); i++) {
    int nn = N[node][i];
    if (!strana[nn]) {
      strana[nn] = -strana[node];
      Dfs(nn);
    }
    else if (strana[nn] == strana[node])
      rje = 0;
  }
}

int main()
{
  int n, m;

  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c) {
      V[a].push_back(b);
      V[b].push_back(a);
    }
    else {
      N[a].push_back(b);
      N[b].push_back(a);
    }
  }

  strana[1] = 1;
  Dfs(1);

  for (int i=1; i<=n; i++)
    if (!strana[i]) {
      rje = Mul(rje, 2);
      strana[i] = 1;
      Dfs(i);
    }
  
  printf("%d\n", rje);

  return 0;
}
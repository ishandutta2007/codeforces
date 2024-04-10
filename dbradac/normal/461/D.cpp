#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;

const int MAX = 100005, MOD = 1000000007;

int n;
int ne=0;
int val[MAX];
vector <P> V[2][MAX];

int Mul2(int x)
{
  return (2 * x) % MOD;
}

int Lgran(int r, int s)
{
  return abs(r - s) + 1;
}

int Rgran(int r, int s)
{
  return min(r + s - 1, 2 * n - (r + s) + 1);
}

void Dfs(int node, int p)
{
  for (int i=0; i<(int) V[p][node].size(); i++) {
    P nn = V[p][node][i];
    if (val[nn.X] == -1) {
      val[nn.X] = val[node] ^ nn.Y;
      Dfs(nn.X, p);
    }
    else if ((val[node] ^ nn.Y) != val[nn.X]) {
      ne = 1;
      return;
    }
  }
}

int main()
{
  int k, rez=1;

  scanf("%d%d", &n, &k);

  for (int i=0; i<k; i++) {
    int r, s;
    char c;
    scanf("%d%d %c", &r, &s, &c);

    int par = (r + s + 1) % 2;
    int lg = (Lgran(r, s) + 1) / 2;
    int rg = (Rgran(r, s) + 1) / 2;
    
    int tmp = 0;
    if (c == 'o')
      tmp = 1;

    V[par][rg].push_back(P(lg-1, tmp));
    V[par][lg-1].push_back(P(rg, tmp));
  }
 
  for (int j=0; j<=1; j++) {
    memset(val, -1, sizeof val);
    val[0] = 0;
    Dfs(0, j);

    int kraj = n / 2;
    if (j)
      kraj = (n+1) / 2;

    for (int i=1; i<=kraj; i++) {
      if (val[i] == -1) {
        rez = Mul2(rez);
        val[i] = 0;
        Dfs(i, j);
      }
    }
  }

  if (ne)
    printf("0\n");
  else
    printf("%d\n", rez);

  return 0;
}
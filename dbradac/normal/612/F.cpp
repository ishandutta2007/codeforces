#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 2005, INF = 0x3f3f3f3f;

vector <int> Poz[MAX];
int p[MAX];
int dp[MAX][MAX];
P kamo[MAX][MAX];
vector <int> Saz;
int n;

int Cw(int a, int b)
{
  return (n + b - a) % n;
}

int Ccw(int a, int b)
{
  return (n + a - b) % n;
}

void PutCw(int poc, int a, int b, int ind)
{
  for (int i=a; ; i=(i+1) % Poz[ind].size()) {
    printf("+%d\n", Cw(poc, Poz[ind][i]));
    poc = Poz[ind][i];
    if (i == b)
      break;
  }
}

void PutCcw(int poc, int a, int b, int ind)
{
  for (int i=a; ; i=(i+Poz[ind].size()-1) % Poz[ind].size()) {
    printf("-%d\n", Ccw(poc, Poz[ind][i]));
    poc = Poz[ind][i];
    if (i == b)
      break;
  }
}

int Rek(int poz, int na, int rec)
{
  if (!rec && dp[poz][na] != INF)
    return dp[poz][na];

  if (na == (int) Saz.size())
    return 0;

  int slj = (lower_bound(Poz[na].begin(), Poz[na].end(), poz) - Poz[na].begin()) % Poz[na].size();
  int pros = (slj + Poz[na].size() - 1) % Poz[na].size();

  int tmp = Cw(poz, Poz[na][pros]) + Rek(Poz[na][pros], na + 1, 0);
  if (rec && tmp == dp[poz][na]) {
    PutCw(poz, slj, pros, na);
    return Rek(Poz[na][pros], na + 1, 1);
  }
  dp[poz][na] = min(dp[poz][na], tmp);

  if (Poz[na][slj] != poz) {
    tmp = Ccw(poz, Poz[na][slj]) + Rek(Poz[na][slj], na + 1, 0);
    if (rec && tmp == dp[poz][na]) {
      PutCcw(poz, pros, slj, na);
      return Rek(Poz[na][slj], na + 1, 1);
    }
    dp[poz][na] = min(dp[poz][na], tmp);
  }

  for (int i=0; i<(int) Poz[na].size(); i++) {
    int zad = (i + 1) % Poz[na].size();
    tmp = Cw(poz, Poz[na][i]) + Ccw(Poz[na][i], Poz[na][zad]) + Rek(Poz[na][zad], na + 1, 0);
    if (rec && tmp == dp[poz][na]) {
      PutCw(poz, slj, i, na);
      PutCcw(Poz[na][i], pros, zad, na);
      return Rek(Poz[na][zad], na + 1, 1);
    }
    dp[poz][na] = min(dp[poz][na], tmp);

    zad = (i + Poz[na].size() - 1) % Poz[na].size();
    tmp = Ccw(poz, Poz[na][i]) + Cw(Poz[na][i], Poz[na][zad]) + Rek(Poz[na][zad], na + 1, 0);
    if (rec && tmp == dp[poz][na]) {
      PutCcw(poz, pros, i, na);
      PutCw(Poz[na][i], slj, zad, na);
      return Rek(Poz[na][zad], na + 1, 1);
    }
    dp[poz][na] = min(dp[poz][na], tmp);
  }

  return dp[poz][na];
}

int main()
{
  int pocpoz;

  scanf("%d%d", &n, &pocpoz); pocpoz--;

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    Saz.push_back(p[i]);
  }

  sort(Saz.begin(), Saz.end());
  Saz.resize(unique(Saz.begin(), Saz.end()) - Saz.begin());

  for (int i=0; i<n; i++)
    Poz[lower_bound(Saz.begin(), Saz.end(), p[i]) - Saz.begin()].push_back(i);

  memset(dp, INF, sizeof dp);
  printf("%d\n", Rek(pocpoz, 0, 0));
  Rek(pocpoz, 0, 1);

  return 0;
}
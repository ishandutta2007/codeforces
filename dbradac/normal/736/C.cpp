#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXN = 250, MOD = 1e9 + 7;

int add(int a, int b)
{
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int dp[MAXN][MAXN][MAXN]; //node, gore, dub
int dub[MAXN], mdub[MAXN];
int par[MAXN];
vector <int> V[MAXN];
int k;

void dfs(int node, int prosli)
{
  par[node] = prosli;
  dub[node] = dub[prosli] + 1;
  if (!node) dub[node] = 22;
  mdub[node] = dub[node];

  for (auto it : V[node]) {
    if (it != prosli) {
      dfs(it, node);
      mdub[node] = max(mdub[node], mdub[it]);
    }
  }
}

int rek(int node, int gore, int tre_dub)
{
  //int deb = 0;
//  if (node == 2 && gore == 20 && tre_dub > dub[node])
  //  deb = 1;

  if (tre_dub > mdub[node]) tre_dub = MAXN - 1;
  if (dub[node] - gore > k)
    gore = 0;

//  if (deb) printf("KASDPKAO %d %d\n", gore, tre_dub);

  if (dub[node] - gore > k && tre_dub - dub[node] > k) return 0;
  if (dp[node][gore][tre_dub] != -1)
    return dp[node][gore][tre_dub];

//  if (deb) printf("asofjoasjifKASDPKAO %d %d\n", gore, tre_dub);

  int tmp[2][2];
  memset(tmp, 0, sizeof tmp);

  int ngore = gore;
  if (tre_dub == dub[node]) {
    tmp[0][1] = 1;
    ngore = tre_dub;
  }
  else
    tmp[0][0] = 1;

  int dgore = max(ngore, dub[node] - (tre_dub - dub[node]));
//  if (tre_dub == 24 && !node)
  //  TRACE(dgore);

  int ind = 0;
  for (auto it : V[node]) {
    if (it == par[node]) continue;

    memset(tmp[1^ind], 0, sizeof tmp[1^ind]);
    for (int i=tre_dub; i<MAXN; i++) {
      if (i != tre_dub || i > mdub[it]) {
        tmp[1^ind][0] = add(tmp[1^ind][0], mul(tmp[ind][0], rek(it, dgore, i)));
        tmp[1^ind][1] = add(tmp[1^ind][1], mul(tmp[ind][1], rek(it, dgore, i)));
      }

      if (i > mdub[it]) break;
    }

    if (tre_dub <= mdub[it]) {
      tmp[1^ind][1] = add(tmp[1^ind][1], mul(tmp[ind][1], rek(it, ngore, tre_dub)));
      tmp[1^ind][1] = add(tmp[1^ind][1], mul(tmp[ind][0], rek(it, ngore, tre_dub)));
    }

    ind ^= 1;

//    if (tre_dub == 24 && !node)    
  //    TRACE(tmp[ind][1]);
  }

  //TRACE(node); TRACE(gore); TRACE(tre_dub);
  //  TRACE(tmp[0][1]);

//  if (tre_dub == 24 && !node)
  //  TRACE(tmp[ind][1]);

//  if (node == 2 && gore == 20)
  //  printf("KADKAOSDK\n");

  if (tre_dub > mdub[node]) {
    if (dub[node] - gore <= k) {
    //  if (node == 2 && gore == 20) printf("MMMM %d\n", tmp[ind][0]);
      return dp[node][gore][tre_dub] = tmp[ind][0];
    }
    return dp[node][gore][tre_dub] = 0;
  }

  return dp[node][gore][tre_dub] = tmp[ind][1];
}

int main()
{
  int n;
  scanf("%d%d", &n, &k);

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  dfs(0, 0);

  memset(dp, -1, sizeof dp);
  int rje = 0;
  REP(i, MAXN) {
    rje = add(rje, rek(0, -1000, i));
//    if (rek(0, -1000, i))
  //    printf("KK %d %d\n", i, rek(0, -1000, i));
  }

  printf("%d\n", rje);

  return 0;
}
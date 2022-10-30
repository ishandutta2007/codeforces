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
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 1005;

vector <int> V[MAX];
vector <P> Vk[MAX];
P val[MAX];
P sum[MAX];
int bio[MAX];
int brk=0;
int n;

void dfs(int node)
{
  if (bio[node]++) return;
  Vk[brk].push_back(P(val[node]));
  sum[brk].X += val[node].X;
  sum[brk].Y += val[node].Y;

  for (auto it : V[node])
    dfs(it);
}

void komp()
{
  REP(i, n) {
    if (!bio[i]) {
      dfs(i);
      brk++;
    }
  }
}

ll dp[MAX][MAX];

int main()
{
  int m, maxw;
  scanf("%d%d%d", &n, &m, &maxw);

  REP(i, n)
    scanf("%lld", &val[i].X);
  REP(i, n)
    scanf("%lld", &val[i].Y);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  komp();

  REP(i, brk) {
    REP(j, MAX) {
      ll ja = dp[i][j];
      dp[i+1][j] = max(dp[i+1][j], ja);
      if (j + sum[i].X <= maxw)
        dp[i+1][j+sum[i].X] = max(dp[i+1][j+sum[i].X], ja + sum[i].Y);

      for (auto it : Vk[i]) 
        if (j + it.X <= maxw)
          dp[i+1][j+it.X] = max(dp[i+1][j+it.X], ja + it.Y);    
    }
  }

  ll rje = 0;
  REP(i, maxw+1)
    rje = max(rje, dp[brk][i]);

  printf("%lld\n", rje);

  return 0;
}
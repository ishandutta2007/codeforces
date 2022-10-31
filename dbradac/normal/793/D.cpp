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
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 85, INF = 0x3f3f3f3f;

int dp[MAX][MAX][MAX]; //dulj, poz, ogr
vector <P> V[MAX];

int izmedu(int a, int b, int p) {
  if (a > b) swap(a, b);
  return p > a && p < b;
}

int rek(int dulj, int poz, int ogr) {
  if (dulj == 0) return 0;
  int &ret = dp[dulj][poz][ogr];
  if (ret != -1) return ret;
  
  ret = INF;

  for (auto it : V[poz]) {
    if (izmedu(poz, ogr, it.X)) {
      ret = min(ret, it.Y + rek(dulj-1, it.X, ogr));
      ret = min(ret, it.Y + rek(dulj-1, it.X, poz));
    }
  }

  return ret;
}

int main()
{
  int m, n, k;
  scanf("%d%d%d", &n, &k, &m);
  
  REP(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    V[a].push_back(P(b, c));
  }

  memset(dp, -1, sizeof dp);
  int rje = INF;
  FOR(i, 1, n+1) {
    rje = min(rje, rek(k-1, i, 0));
    rje = min(rje, rek(k-1, i, n+1));
  }

  printf("%d\n", rje < INF/2 ? rje : -1);

  return 0;
}
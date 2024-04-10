#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 19;

int n, m;
int edge[MAX][MAX];
int p[MAX];
ll dp[MAX][1<<MAX];

int Plus(int pros, int nov)
{
  if (pros == 18)
    return 0;
  return edge[pros][nov];
}

ll Rek(int zad, int st)
{
  if (dp[zad][st] != -1)
    return dp[zad][st];

  if (__builtin_popcount(st) == m)
    return 0;

  ll ret=0;
  for (int i=0; i<n; i++)
    if (!((1<<i) & st))
      ret = max(ret, Rek(i, st | (1<<i)) + p[i] + Plus(zad, i));
  
  return dp[zad][st] = ret;
}

int main()
{
  int k;

  memset(dp, -1, sizeof dp);

  scanf("%d%d%d", &n, &m, &k);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<k; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    edge[a][b] = c;
  }

  cout << Rek(18, 0) << endl;

  return 0;
}
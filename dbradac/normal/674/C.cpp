#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
typedef long double llf;
#define X first
#define Y second

const int MAX = 200100, MAXK = 51;
const llf INF = 1e50, EPS = 1e-7;

int p[MAX];
ll pref[MAX];
int n, k;
llf dp[MAXK][MAX];
int piv[MAXK][MAX];
llf prefrec[MAX];

void Rijesi1(int ind, int poz, int from, int to)
{
  from = max(poz, from);
  piv[ind][poz] = from;
  llf minn = INF;
  llf sum = 0;

  for (int i=from; i<=to; i++) {
    sum += ((llf) pref[i] - pref[poz-1]) / p[i];
    if (sum + dp[ind-1][i+1] + EPS < minn) {
      minn = sum + dp[ind-1][i+1];
      piv[ind][poz] = i;
    }
  }
}

void Rijesi(int ind, int lo, int hi, int from, int to)
{
  if (lo > hi)
    return;

  int mid = (lo + hi) / 2;
  Rijesi1(ind, mid, from, to);

  Rijesi(ind, lo, mid - 1, from, piv[ind][mid]);
  Rijesi(ind, mid + 1, hi, piv[ind][mid], to);
}

void NadiDp(int ind)
{
  for (int i=1; i<=piv[ind][1]; i++)
    dp[ind][1] += ((llf) pref[i]) / p[i];
  dp[ind][1] += dp[ind-1][piv[ind][1]+1];

  for (int i=2; i<=n; i++) {
    if (piv[ind][i-1] >= i)
      dp[ind][i] = dp[ind][i-1] - (p[i-1] * (prefrec[piv[ind][i-1]] - prefrec[i-2])) - dp[ind-1][piv[ind][i-1]+1];
    else
      dp[ind][i] = 0;

    for (int j=max(i, piv[ind][i-1]+1); j<=piv[ind][i]; j++)
      dp[ind][i] += ((llf) pref[j] - pref[i-1]) / p[j];

    dp[ind][i] += dp[ind-1][piv[ind][i]+1];
  }
}

llf W(int a, int b)
{
  llf ret=0;
  for (int i=a; i<=b; i++)
    ret += ((llf) pref[i] - pref[a-1]) / p[i];

  return ret;
}

int main()
{
  scanf("%d%d", &n, &k);

  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    pref[i] = pref[i-1] + p[i];
    prefrec[i] = prefrec[i-1] + (llf) 1 / p[i];
  }

  dp[0][n+1] = 0;
  for (int i=1; i<=n; i++)
    dp[0][i] = INF;

  for (int i=1; i<=k; i++) {
    Rijesi(i, 1, n, 1, n);
    NadiDp(i);
  }

  printf("%.10lf\n", (double) dp[k][1]);

  return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long double llf;

const int MAX = 2005, INF = 0x3f3f3f3f;

int n, h;
int p[MAX];
int doklel[MAX], dokler[MAX];
llf dp[2][2][MAX][MAX];
llf prob;

llf Rek(int stl, int str, int l, int r)
{
  if (l > r)
    return 0;

  if (dp[stl][str][l][r] > -0.5)
    return dp[stl][str][l][r];

  llf ret = 0;
  
  int lg, rg;

  if (!l)
    lg = -INF;
  else {
    if (!stl)
      lg = p[l-1];
    else
      lg = p[l-1] + h;
  }

  lg = max(lg, p[l] - h);

  if (r == n - 1)
    rg = INF;
  else {
    if (!str)
      rg = p[r+1];
    else
      rg = p[r+1] - h;
  }

  rg = min(rg, p[r] + h);
  
  ret += 0.5 * prob * ((p[l] - lg) + Rek(0, str, l + 1, r));
  ret += 0.5 * (1 - prob) * ((rg - p[r]) + Rek(stl, 0, l, r - 1));

  int nl = min(r + 1, dokler[l] + 1);
  rg = min(rg, p[nl-1] + h);
  ret += 0.5 * (1 - prob) * ((rg - p[l]) + Rek(1, str, nl, r));

  int nr = max(l - 1, doklel[r] - 1);
  lg = max(lg, p[nr+1] - h);
  ret += 0.5 * prob * ((p[r] - lg) + Rek(stl, 1, l, nr));

  return dp[stl][str][l][r] = ret;
}

int main()
{
  cin >> n >> h >> prob;

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);
  sort(p, p + n);

  for (int i=n-1; i>=0; i--) {
    if (i == n-1 || p[i] + h <= p[i+1])
      dokler[i] = i;
    else
      dokler[i] = dokler[i+1];
  }

  for (int i=0; i<n; i++) {
    if (!i || p[i] - h >= p[i-1])
      doklel[i] = i;
    else
      doklel[i] = doklel[i-1];
  }

  for (int ii=0; ii<2; ii++)
    for (int jj=0; jj<2; jj++)
      for (int i=0; i<MAX; i++)
        for (int j=0; j<MAX; j++)
          dp[ii][jj][i][j] = -1;

  printf("%.12lf\n", (double) Rek(0, 0, 0, n-1));

  return 0;
}
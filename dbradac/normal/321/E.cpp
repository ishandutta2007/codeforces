#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define TRACE(x) cerr << #x << " = " << x << endl;

using namespace std;

const int MAX = 4005;

int dp[MAX][MAX], pivot[MAX][MAX];
int polje[MAX][MAX], pref[MAX][MAX];
int weight[MAX][MAX];
char s[2*MAX];

void Rijesi(int ost, int ind, int lo, int hi)
{
  for (int i=lo; i<=hi; i++)
    if (dp[ost][ind] == -1 || dp[ost-1][i] + weight[i+1][ind] <= dp[ost][ind]) {
      dp[ost][ind] = dp[ost-1][i] + weight[i+1][ind];
      pivot[ost][ind] = i;
    }
}

void Rek(int ost, int lo, int hi, int from, int to)
{
  int mid = (lo + hi) / 2;

  if (lo > hi)
    return;

  Rijesi(ost, mid, from, to);

  Rek(ost, lo, mid-1, from, pivot[ost][mid]);
  Rek(ost, mid+1, hi, pivot[ost][mid], to);
}

int main()
{
  int n, gond;

  scanf("%d%d ", &n, &gond);
  
  for (int i=1; i<=n; i++) {
    scanf(" %[^\n]", s);
    for (int j=0, ind=1; ind<=n; j+=2, ind++) {
      polje[i][ind] = s[j] - '0';
      pref[i][ind] = pref[i][ind-1] + polje[i][ind];
    }
  }

  for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
      weight[i][j] = weight[i][j-1] + pref[j][j] - pref[j][i-1];
  
  memset(dp, -1, sizeof dp);

  for (int i=1; i<=n; i++)
    dp[1][i] = weight[1][i];

  for (int i=2; i<=gond; i++)
    Rek(i, 1, n, 1, n);

  printf("%d\n", dp[gond][n]);

  return 0;
}
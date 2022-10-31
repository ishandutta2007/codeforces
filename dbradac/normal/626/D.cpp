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
#define X first
#define Y second

const int MAX = 10005, POL = MAX / 2;

int p[MAX];
int brraz[MAX];
double dp[3][MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  sort(p, p + n);

  for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++)
      brraz[p[j] - p[i]]++;

  int pov = n * (n - 1) / 2;
  double koef = 1.0 / pov;

  dp[0][0] = 1;
  for (int i=0; i<2; i++)
    for (int j=0; j<POL; j++)
      for (int k=0; k<POL; k++)
        dp[i+1][j+k] += dp[i][j] * koef * brraz[k];

  double rje=0;
  double sum=0;
  
  for (int i=0; i<MAX; i++) {
    rje += koef * brraz[i] * sum;
    sum += dp[2][i];
  }

  printf("%.10lf\n", rje);

  return 0;
}
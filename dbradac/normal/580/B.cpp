#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

P cov[MAX];
ll pref[MAX];

int main()
{
  int n, d;

  scanf("%d%d", &n, &d);

  for (int i=1; i<=n; i++)
    scanf("%d%d", &cov[i].X, &cov[i].Y);
  
  sort(cov + 1, cov + n + 1);

  for (int i=1; i<=n; i++)
    pref[i] = pref[i-1] + cov[i].Y;

  ll rje = 0;
  for (int i=1; i<=n; i++) {
    int zad = lower_bound(cov + 1, cov + n + 1, P(cov[i].X + d, -1)) - cov;
    rje = max(rje, pref[zad - 1] - pref[i-1]);
  }

  cout << rje << endl;

  return 0;
}
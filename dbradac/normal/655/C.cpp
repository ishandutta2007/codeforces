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

const int MAX = 1<<17;

int p[MAX], pref[2*MAX];
char s[MAX];
int n, k;

int main()
{
  scanf("%d%d%s", &n, &k, s + 1);

  for (int i=1; i<=n; i++)
    pref[i] = pref[i-1] + (1 - (s[i] - '0'));

  int rje = n;
  for (int i=1; i<=n; i++) {
    if (s[i] != '0')
      continue;

    int lo = 0, hi = n;
    for (; lo<hi; ) {
      int mid = (lo + hi) / 2;
      if (pref[min(n, i+mid)] - pref[max(0, i-mid-1)] >= k + 1)
        hi = mid;
      else
        lo = mid + 1;
    }

    rje = min(rje, lo);
  }

  printf("%d\n", rje);

  return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1<<17, MAXM = 20;

int koji[MAXN];
int poj[MAXM];
int nevalja[1<<MAXM];

int main()
{
  int n, m, d, rje=MAXM;

  scanf("%d%d%d", &n, &m, &d);

  for (int i=0; i<m; i++) {
    int k;
    scanf("%d", &k);
    for (int j=0; j<k; j++) {
      int tmp;
      scanf("%d", &tmp); tmp--;
      koji[tmp] = i;
    }
  }

  int mask=0;
  for (int i=0; i<d; i++) {
    if (!poj[koji[i]])
      mask ^= (1 << koji[i]);
    poj[koji[i]]++;
  }  

  for (int poc=0, kraj=d-1; kraj<n; poc++, kraj++) {
    nevalja[~mask & ((1<<m) - 1)] = 1;
    poj[koji[poc]]--;
    if (!poj[koji[poc]])
      mask ^= (1 << koji[poc]);

    if (!poj[koji[kraj+1]])
      mask ^= (1 << koji[kraj+1]);
    poj[koji[kraj+1]]++;
  }

  for (int i=(1<<m)-1; i>=0; i--) {
    if (nevalja[i]) {
      for (int j=0; j<m; j++)
        if ((1<<j) & i)
          nevalja[i ^ (1<<j)] = 1;
    }
    else
      rje = min(rje, __builtin_popcount(i));
  }

  printf("%d\n", rje);

  return 0;
}
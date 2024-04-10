#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1005;

int w[MAX], p[MAX];
int prosli[MAX], bio[MAX];

int main()
{
  int n, m, rje=0;

  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
    scanf("%d", &w[i]);
  
  memset(prosli, -1, sizeof prosli);

  for (int i=0; i<m; i++) {
    scanf("%d", &p[i]); p[i]--;
    memset(bio, 0, sizeof bio);

    for (int j=i-1; j>prosli[p[i]]; j--) {
      if (!bio[p[j]]) {
        rje += w[p[j]];
        bio[p[j]] = 1;
      }
    }
    prosli[p[i]] = i;
  }

  printf("%d\n", rje);

  return 0;
}
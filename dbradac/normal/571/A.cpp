#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 300100;

ll pref[MAX];

int main()
{
  int p[3];

  for (int i=0; i<3; i++)
    scanf("%d", &p[i]);

  int l;
  scanf("%d", &l);

  ll rje=0;
  for (int i=0; i<3; i++) {
    for (int j=0; j<=l; j++) {
      int raz = p[i] + j - p[(i+1) % 3] - p[(i+2) % 3];
      raz = min(l - j, raz);

      if (raz >= 0)
        rje += ((ll) raz + 1) * (raz + 2) / 2;
    }
  }

  rje = -rje;
  for (int i=0; i<=l; i++)
    rje += ((ll) 2 + i) * (1 + i) / 2;

  printf("%lld\n", rje);

  return 0;
}
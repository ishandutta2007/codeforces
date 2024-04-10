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

const int MAX = 21;

int brred, brstup;
int p[MAX][MAX];

int dobar(int tmp[MAX])
{
  for (int i=0; i<brstup; i++)
    if (tmp[i] != i + 1)
      return 0;
  return 1;
}

int moze(int a, int b)
{
  for (int i=0; i<brred; i++) {
    int da = 0;
    int tmp[MAX];

    for (int j=0; j<brstup; j++)
      for (int k=j; k<brstup; k++) {
        memcpy(tmp, p[i], sizeof tmp);
        swap(tmp[a], tmp[b]);
        swap(tmp[j], tmp[k]);
        if (dobar(tmp))
          da = 1;

        memcpy(tmp, p[i], sizeof tmp);
        swap(tmp[j], tmp[k]);
        swap(tmp[a], tmp[b]);
        if (dobar(tmp))
          da = 1;
      }

    if (!da)
      return 0;
  }

  return 1;
}

int main()
{
  scanf("%d%d", &brred, &brstup);

  for (int i=0; i<brred; i++)
    for (int j=0; j<brstup; j++)
      scanf("%d", &p[i][j]);

  for (int i=0; i<brstup; i++) {
    for (int j=i; j<brstup; j++) {
      if (moze(i, j)) {
        printf("YES\n");
        return 0;
      }
    }
  }

  printf("NO\n");

  return 0;
}
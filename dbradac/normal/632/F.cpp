#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 2505;

int p[MAX][MAX];
bitset <MAX> red[MAX], stup[MAX];
pair <int, P> sor[MAX*MAX];
int n;

void Nope()
{
  printf("NOT MAGIC\n");
  exit(0);
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      scanf("%d", &p[i][j]);
      sor[i * n + j] = make_pair(-p[i][j], P(i, j));
    }

  for (int i=0; i<n; i++)
    if (p[i][i])
      Nope();

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if (p[i][j] != p[j][i])
        Nope();

  sort(sor, sor + n * n);

  for (int i=0; i<n*n; ) {
    int poc = i;
    for (; i<n*n && sor[i].X == sor[poc].X; i++) {
      red[sor[i].Y.X].set(sor[i].Y.Y, 1);
      stup[sor[i].Y.Y].set(sor[i].Y.X, 1);
    }

    for (i=poc; i<n*n && sor[i].X == sor[poc].X; i++)
      if ((int) (red[sor[i].Y.X] | stup[sor[i].Y.Y]).count() != n)
        Nope();
  }

  printf("MAGIC\n");

  return 0;
}
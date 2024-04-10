#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

struct str {
  int x, y, ind;
} toc[MAX];

bool operator < (const str &a, const str &b)
{
  if (a.y - a.x != b.y - b.x)
    return a.y - a.x > b.y - b.x;
  return a.x < b.x;
}

void Nope()
{
  printf("NO\n");
  exit(0);
}

P oz[MAX];
P rje[MAX];
map <P, int> M;

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &toc[i].x, &toc[i].y);
    toc[i].ind = i;
  }

  sort(toc, toc + n);

  for (int i=0; i<n; i++) {
    scanf("%d", &oz[i].X);
    oz[i].Y = -(i+1);
  }

  sort(oz, oz + n, greater<P>());

  for (int i=0; i<n; i++) {
    if (oz[i].X != toc[i].y - toc[i].x)
      Nope();
    

    int tmp = -oz[i].Y;
    rje[tmp-1] = P(toc[i].x, toc[i].y);

    M[P(toc[i].x, toc[i].y)] = tmp;
    if (M[P(toc[i].x - 1, toc[i].y)] > tmp || M[P(toc[i].x, toc[i].y - 1)] > tmp ||
        (M[P(toc[i].x + 1, toc[i].y)] && M[P(toc[i].x + 1, toc[i].y)] < tmp) ||
        (M[P(toc[i].x, toc[i].y + 1)] && M[P(toc[i].x, toc[i].y + 1)] < tmp))
          Nope();
  }

  printf("YES\n");
  for (int i=0; i<n; i++)
    printf("%d %d\n", rje[i].X, rje[i].Y);

  return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 10005;

pair<int, int> p[MAX];

int main()
{
  int n, k, rje=0;

  scanf("%d%d", &n, &k);

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    p[i] = make_pair(tmp, i);
  }

  sort(p, p+n);

  for (rje=0; rje<n; rje++) {
    if (p[rje].first > k)
      break;
    k -= p[rje].first;
  }

  printf("%d\n", rje);
  for (int i=0; i<rje; i++)
    printf("%d ", p[i].second + 1);
  printf("\n");

  return 0;
}
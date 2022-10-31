#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int p[MAX];
int bio[MAX];

void Rek(int node)
{
  if (bio[node])
    return;
  bio[node] = 1;
  Rek(node + p[node]);
}

int main()
{
  int n, k;

  scanf("%d%d", &n, &k);

  for (int i=1; i<n; i++)
    scanf("%d", &p[i]);

  Rek(1);
  if (bio[k])
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
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

const int MAX = 5005;

int Nope()
{
  printf("-1\n");
  exit(0);
}

int bitan[MAX];

int main()
{
  int n, k, a, b, c, d;

  scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);

  if (n == 4)
    Nope();

  if (k < n + 1)
    Nope();

  bitan[a] = bitan[b] = bitan[c] = bitan[d] = 1;

  printf("%d ", a);
  printf("%d ", c);

  int x=-1;
  for (int i=1; i<=n; i++)
    if (!bitan[i]) {
      x = i;
      printf("%d ", i);
      break;
    }

  printf("%d ", d);

  for (int i=x+1; i<=n; i++)
    if (!bitan[i])
      printf("%d ", i);

  printf("%d ", b);
  printf("\n");

  printf("%d ", c);
  printf("%d ", a);
  printf("%d ", x);
  printf("%d ", b);

  bitan[x] = 1;
  for (int i=n; i>=1; i--)
    if (!bitan[i])
      printf("%d ", i);

  printf("%d ", d);
  printf("\n");


  return 0;
}
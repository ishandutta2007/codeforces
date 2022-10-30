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

int main()
{
  int n, d, h;

  scanf("%d%d%d", &n, &d, &h);

  if (d > 2 * h || (d == 1 && n > 2)) {
    printf("-1\n");
    return 0;
  } 

  int zad = 2;
  for (int i=0; i<h; i++, zad++)
    printf("%d %d\n", zad-1, zad);

  int pros = 1;
  for (int i=0; i<d-h; i++, zad++) {
    printf("%d %d\n", pros, zad);
    pros = zad;
  }

  if (d > h) {
    for (; zad <= n; zad++)
      printf("%d %d\n", 1, zad);
  }
  else {
    for (; zad <= n; zad++)
      printf("%d %d\n", 2, zad);
  }

  return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int r=0, n, minn=200;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    minn = min(minn, b);
    r += a * minn;
  }

  printf("%d\n", r);

  return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int n, vis, ret;

  scanf("%d%d", &n, &vis); ret = vis;

  for (; n--; ) {
    int kat, t;
    scanf("%d%d", &kat, &t);
    ret = max(ret, t + kat);
  }

  printf("%d\n", ret);

  return 0;
}